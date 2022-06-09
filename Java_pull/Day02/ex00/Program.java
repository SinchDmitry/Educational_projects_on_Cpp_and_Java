import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        SignatureChecker checker = new SignatureChecker();
        if (!checker.init()) {
            return;
        }

        Scanner s = new Scanner(System.in);
        String input = "";
        while (true) {
            input = s.nextLine();

            if (input.equals("42")) {
                break;
            }

            checker.checkFileSignature(input.trim());
        }
    }
}