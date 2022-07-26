package ex05;

import java.util.Scanner;

public class Program {
	public static void main(String[] args) {
        TransactionsService clients = new TransactionsService();
        Menu app = new Menu(clients);
        Scanner input = new Scanner(System.in);

        try {
                app.checkMode(args);
                app.commandExecutor(input);
        } catch (Exception e) {
                System.err.println(e.getMessage());
                input.close();
                System.exit(-1);
        }
        input.close();
        System.exit(0);
    }
}