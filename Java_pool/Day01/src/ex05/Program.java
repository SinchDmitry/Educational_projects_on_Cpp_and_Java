package ex05;

import java.util.Scanner;

public class Program {
	public static void main(String[] args) {
        TransactionsService clients = new TransactionsService();
        Menu app = new Menu(clients);
        Scanner input = new Scanner(System.in);

        app.checkMode(args);
        app.commandExecutor(input);
    }
}