package app;

import logic.ParseTest;

import java.io.IOException;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) throws IOException {
        if (args.length == 4) {
            ParseTest test = new ParseTest();
            System.out.println(args[0] + " | " + args[1] + " | " + args[2] + " | " + args[3]);
            test.argsPrinter();
            Scanner input = new Scanner(System.in);
            while (true) {
                int tmp = System.in.read();
                System.out.println("i see : " + (char)tmp);
            }
        } else {
            System.err.println("Error : wrong number of input arguments");
            System.exit(-1);
        }
        System.exit(0);
    }
}
