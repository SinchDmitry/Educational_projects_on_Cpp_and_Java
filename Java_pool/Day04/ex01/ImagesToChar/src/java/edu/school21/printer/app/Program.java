package edu.school21.printer.app;

import edu.school21.printer.logic.ConvertFileFolder;
import java.io.IOException;

public class Program {
    private static int checkInputArgs(String[] args) {
        if (args[0].length() == 1 && args[1].length() == 1)  {
            if ((int)args[0].toCharArray()[0] > 0 && (int)args[0].toCharArray()[0] < 255 &&
                    (int)args[1].toCharArray()[0] > 0 && (int)args[1].toCharArray()[0] < 255) {
                return 0;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        if (args.length == 2 && checkInputArgs(args) == 0) {
            char[][] newArr = null;
            String path = "/resources/image.bmp";
            try {
                newArr = ConvertFileFolder.toCharArray(path, args[0].toCharArray()[0], args[1].toCharArray()[0]);
            } catch (IOException e) {
                System.err.printf("Error : failed to read '%s': %s\n", args[0], e.getMessage());
                return;
            } catch (ConvertFileFolder.ConvertException e) {
                System.err.printf("Error : failed to convert '%s': %s\n", args[0], e.getMessage());
                return;
            }
            for (int i = 0; i < newArr[0].length; ++i) {
                for (char[] chars : newArr) {
                    System.out.print(chars[i]);
                }
                System.out.println();
            }
        } else {
            System.err.println("Error : wrong number of arguments");
        }
    }
}
