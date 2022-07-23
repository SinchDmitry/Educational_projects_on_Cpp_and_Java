package ex01;
import  java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int     exitCode = -1;
        int     i = 1;
        boolean res = true;
        if (input.hasNextInt()) {
            int number;
            if ((number = input.nextInt()) > 1) {
                exitCode = 0;
                if (number > 2) {
                    while (i * i++ < number) {
                        if (number % i == 0) {
                            res = false;
                            break;
                        }
                    }
                    --i;
                }
            }
        }
        else {
            System.out.println(res + " " + i);
        }
        input.close();
        System.exit(exitCode);
    }
}
