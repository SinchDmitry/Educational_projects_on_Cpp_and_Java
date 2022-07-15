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
//            a.findSign("/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/en.subject.pdf");
//            a.findSign("/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex00/Program.java");
//            a.findSign("/Users/aarchiba/Desktop/Educational_projects_on_Cpp_and_Java/Java_pool/Day02/src/ex00/png.png");
        } else {
            System.err.println("Error : empty signature");
            System.exit(-1);
        }
        System.exit(0);
    }
}
