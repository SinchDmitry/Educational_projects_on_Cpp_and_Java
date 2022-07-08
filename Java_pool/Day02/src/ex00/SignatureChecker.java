package ex00;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class SignatureChecker {
    private Map<String, int[]> _signMap;

    public SignatureChecker() {
        _signMap = new HashMap<>();
    }

    public boolean parseSign(String inputString) {
        String[] keyValueArray = inputString.split(",");
        if (keyValueArray.length != 2) {
            System.err.println("Error : wrong signature type");
            return false;
        }
        String[] stringToHexIntArray = keyValueArray[1].trim().split("\\s+");
        int[] intArray = new int[keyValueArray.length];
        for (int i = 0; i < stringToHexIntArray.length; ++i) {
            intArray[i] = Integer.parseInt(stringToHexIntArray[i], 16);
        }
        _signMap.put(keyValueArray[0], intArray);
        return true;
    }

    public void createMap() {
        String path =
                "/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex00/signature.txt";
        try (FileInputStream readFile = new FileInputStream(path)) {
            int red;
            String tmpSign = "";
            while ((red = readFile.read()) != -1) {
                if (red != '\n') {
                    tmpSign += (char)red;
                } else {
                    if (!parseSign(tmpSign)) {
                        System.exit(-1);
                    }
                    tmpSign = "";
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println("Error: signature.txt not found");
            System.exit(-1);
        } catch (IOException e) {
            System.err.printf("Error : %s\n", e.getMessage());
            System.exit(-1);
        } catch (NumberFormatException e) {
            System.err.println("Error: parse error");
            System.exit(-1);
        }
    }
}
