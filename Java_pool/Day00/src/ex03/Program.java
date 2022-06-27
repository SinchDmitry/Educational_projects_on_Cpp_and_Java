package ex03;
import java.util.Scanner;

public class Program {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String  word;
        long    data = 0;
        int     week = 0;

        for (int num = 1; num < 19; ++num) {
            if (input.hasNextLine()) {
                word = input.next();
                if (!word.equals("Week")) {
                    if (word.equals("42")) {
                       break;
                    }
                    errorEnd();
                } else if (input.hasNextInt()) {
                    week = input.nextInt();
                    if (week == num) {
                        data = data + findMin(week, input);
                    } else {
                        errorEnd();
                    }
                } else {
                    errorEnd();
                }
            } else {
                errorEnd();
            }
        }
        printArrow(data, week);
        input.close();
        System.exit(0);
    }

    private static void errorEnd() {
        System.err.println("Illegal Argument");
        System.exit(-1);
    }

    private static short findMin(int week, Scanner input) {
        int     tmp;
        short   minScore = 10;

        for (short i = 0; i < 5; i++) {
            if (input.hasNextInt()) {
                tmp = input.nextInt();
                if (tmp > 0 && tmp < 10) {
                    if (minScore > tmp) {
                        minScore = (short)tmp;
                    }
                } else {
                    errorEnd();
                }
            } else {
                errorEnd();
            }
        }
        for (int i = 0; i < week - 1; i++) {
            minScore *= 10;
        }
        return (minScore);
    }

    private static void printArrow(long data, int week) {
        for (int i = 1; i <= week; i++) {
            System.out.print("Week " + i + " ");
            for (int j = 0; j < data % 10; j++) {
                System.out.print("=");
            }
            System.out.println(">");
            data /= 10;
        }
    }
}
