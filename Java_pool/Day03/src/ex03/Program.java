package ex03;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class Program {

    private static int parseInitData(String[] args) {
        String  prefix = "--threadsCount=";
        if (args.length != 1) {
            System.out.println("Error : wrong number of arguments");
        } else {
            if (args[0].startsWith(prefix)) {
                try {
                    int count = Integer.parseInt(args[0].substring(prefix.length()));
                    return count;
                } catch (NumberFormatException e) {
                    System.err.printf("%s is not a number\n", args[0]);
                }
            } else {
                System.out.println("Error : miss right prefix to count");
            }
        }
        return -1;
    }

    private static Map<Integer, String> parseInputFile(String filename) {
        Map<Integer, String> fileData = new TreeMap<>();
        try (BufferedReader file = new BufferedReader(new FileReader(filename))) {
            String line = null;
            while ((line = file.readLine()) != null) {
                if (line.split("\\s+").length != 2) {
                    System.err.println("Error : wrong format of input file");
                    System.exit(-1);
                } else {
                    int key = Integer.parseInt(line.split("\\s+")[0]);
                    String value = line.split("\\s+")[1];
                    fileData.put(key, value);
                }
            }
            System.out.println(fileData);
        } catch (IOException e) {
            System.err.println("Error : wrong format of input file");
            return null;
        } catch (NumberFormatException e) {
            System.err.println("Error : wrong format of data in input file");
            return null;
        }
        return fileData;
    }

    public static void main(String[] args) {
        int numOfTreads = parseInitData(args);
        Map<Integer, String> fileData =
                parseInputFile("/Users/aarchiba/Desktop/oop/Java_pool/Day03/src/ex03/files_urls.txt");
        if (numOfTreads > 0) {
            FileLauncher loader = new FileLauncher(numOfTreads, fileData);
            loader.generalAction();
        }
    }
}
