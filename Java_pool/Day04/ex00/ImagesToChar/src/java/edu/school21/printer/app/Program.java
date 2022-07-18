package edu.school21.printer.app;

import edu.school21.printer.logic.ConvertFile;
import java.io.IOException;

public class Program {
    public static void main(String[] args) {
        if (args.length == 1) {
            char[][] newArr = null;
            try {
                newArr = ConvertFile.toCharArray(args[0]);
            } catch (IOException e) {
                System.err.printf("Failed to read '%s': %s\n", args[0], e.getMessage());
                return;
            } catch (ConvertFile.ConvertException e) {
                System.err.printf("Failed to convert '%s': %s\n", args[0], e.getMessage());
                return;
            }
            for (int i = 0; i < newArr[0].length; ++i) {
                for (int j = 0; j < newArr.length; ++j) {
                    System.out.print(newArr[j][i]);
                }
                System.out.println();
            }
        }
    }
}
