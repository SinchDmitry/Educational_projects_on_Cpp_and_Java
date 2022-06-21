package ex02;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int		counter = 0;
        int     exitCode = 1;
        while (exitCode == 1) {
            int number;
            if (input.hasNextInt()) {
                if ((number = input.nextInt()) > 0) {
                    if (number == 42) {
                        System.out.println("Count of coffee-request - " + counter);
                        exitCode = 0;
                    } else if (num_value(sum(number))) {
                        ++counter;
                    }
                } else {
                    System.err.println("Illegal Argument");
                    exitCode = -1;
                }
            } else {
                System.err.println("Illegal Argument");
                exitCode = -1;
            }
        }
        input.close();
        System.exit(exitCode);
    }

    private static int sum(int value) {
        int	result = 0;
        while (value != 0) {
            result += value % 10;
            value /= 10;
        }
        return (result);
    }

    private static boolean num_value(int number) {
        if (number <= 1) {
            return (false);
        } else if (number != 2) {
            for (int i = 1; i * i < number; ++i) {
                if (number % (i + 1) == 0) { return (false); }
            }
        }
        return (true);
    }
}
