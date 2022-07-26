package ex00;

import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        SignatureChecker a = new SignatureChecker();
        if (a.createMap()) {
            while (true) {
                Scanner input = new Scanner(System.in);
                if (input.hasNextLine()) {
                    String path = input.nextLine();
                    if (path.equals("42")){
                        break;
                    } else {
                        a.findSign(path);
                    }
                }
            }
        } else {
            System.err.println("Error : empty signature");
            System.exit(-1);
        }
        System.exit(0);
    }
}
