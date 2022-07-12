package ex00;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.stream.Collectors;

public class SignatureChecker {
    private final Map<String, int[]> _signMap;

    public SignatureChecker() {
        _signMap = new HashMap<>();
        try {
            new FileOutputStream("/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex00/result.txt").close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean parseSign(String inputString) {
        String[] keyValueArray = inputString.split(",");
        if (keyValueArray.length != 2) {
            System.err.println("Error : wrong signature type");
            return false;
        }
        String[] stringToHexIntArray = keyValueArray[1].trim().split("\\s+");
        int[] intArray = new int[stringToHexIntArray.length];
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
            System.err.println("Error : signature.txt not found");
            System.exit(-1);
        } catch (IOException e) {
            System.err.printf("Error : %s\n", e.getMessage());
            System.exit(-1);
        } catch (NumberFormatException e) {
            System.err.println("Error : parse error");
            System.exit(-1);
        }
    }

    private void    printResult (String output) {
        try {
            FileOutputStream result = new FileOutputStream("/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex00/result.txt", true);
            result.write(output.getBytes(StandardCharsets.UTF_8));
            result.write('\n');
            result.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private boolean checkPartOfSign(int[] val, int[] parseVal) {
        if (val.length < parseVal.length) {
            return false;
        } else {
            for (int i = 0; i < parseVal.length; ++i) {
                if (parseVal[i] != val[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    public void findSign(String path) {
        try (FileInputStream readFile = new FileInputStream(path)) {
            int red;
            List<Integer> redBytes = new ArrayList<>();
            List<Map.Entry<String, int[]>> tmpSignPrev = null;
            List<Map.Entry<String, int[]>> tmpSign;
            while ((red = readFile.read()) != -1) {
                redBytes.add(red);
                int[] tmp = redBytes.stream().mapToInt(i -> i).toArray();
                tmpSign = _signMap.entrySet().stream().filter(it -> checkPartOfSign(it.getValue(),
                        tmp)).collect(Collectors.toList());
                if (tmpSign.size() == 0) {
                    redBytes.remove(redBytes.size() - 1);
                    break;
                }
                tmpSignPrev = tmpSign;
            }
            if (tmpSignPrev == null) {
                System.out.println("UNDEFINED");
            } else if (tmpSignPrev.size() > 0) {
                tmpSign = _signMap.entrySet().stream().filter(item -> Arrays.equals((item.getValue()),
                        redBytes.stream().mapToInt(i -> i).toArray())).collect(Collectors.toList());
                if (tmpSign.size() == 0) {
                    System.out.println("UNDEFINED");
                    return;
                }
                System.out.println("PROCESSED");
                printResult(tmpSign.get(0).getKey());
            }
        } catch (FileNotFoundException e) {
            System.err.println("Error: input file not found");
            System.exit(-1);
        } catch (IOException e) {
            System.err.printf("Error : %s\n", e.getMessage());
            System.exit(-1);
        }
    }
}

