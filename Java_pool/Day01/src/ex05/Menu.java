package ex05;

import java.util.Scanner;
import java.util.NoSuchElementException;

class WrongNumOfArgs extends RuntimeException {
    public WrongNumOfArgs(String msg) {
        super(msg);
    }
}

class WrongNumOfCommand extends RuntimeException {
    public WrongNumOfCommand(String msg) {
        super(msg);
    }
}

public class Menu {
    private boolean _mode = false;
    private final TransactionsService _clients;

    public Menu(TransactionsService clients) {
        _clients = clients;
    }

    public void checkMode(String[] args) {

        if (args.length == 1) {
            if (args[0].equals("--profile=dev")) {
                _mode = true;
                System.out.println("App works in developer mode");
            } else if (args[0].equals("--profile=production")) {
                System.out.println("App works in production mode");
            } else {
                throw new WrongNumOfArgs("Error : wrong input arguments");
            }
        } else {
            throw new WrongNumOfArgs("Error : wrong input arguments");
        }
        _mode = true;
    }

    public void printMenu() {
        System.out.println("1. Add a user");
        System.out.println("2. View user balance");
        System.out.println("3. Perform a transfer");
        System.out.println("4. View all transactions for a specific user");
        if (_mode) {
            System.out.println("5. DEV - remove a transfer by ID");
            System.out.println("6. DEV - check transfer validity");
            System.out.println("7. Finish execution");
        } else {
            System.out.println("5. Finish execution");
        }
    }

    public void commandExecutor (Scanner input) {
        while (true) {
            printMenu();
            if (input.hasNextInt()) {
                switch (input.nextInt()) {
                    case 1 : addNewUser(input);
                        break;
                    case 2 : viewUserBalance();
                        break;
                    case 3 : performTransaction();
                        break;
                    case 4 : viewAllTransactions();
                        break;
                    case 5 :
                        if (_mode) {
                            removeTransactionByID();
                        } else {
                            input.close();
                            System.exit(0);
                        }
                        break;
                    case 6 : checkTransferValidity();
                        break;
                    case 7 :
                        input.close();
                        System.exit(0);
                        break;
                    default :
                        throw new WrongNumOfCommand("Error : wrong number of command");
                }
            } else {
                throw new WrongNumOfCommand("Error : wrong number of command");
            }
        }
    }

    public void addNewUser(Scanner input) {
        while (true) {
            String tmpName;
            int    tmpBalance
            try {
                tmpName = input.nextLine();
            } catch (NoSuchElementException e) {
                continue;
            }
            String[] inputData = tmpName.split("\\s+");
            if (inputData.length == 0) {
                System.out.println("Error : Set Name");
                continue;
            } else if (inputData.length == 1) {
                System.out.println("Error : Set Balance");
                continue;
            } else if (inputData.length > 2){
                System.out.println("Error : This command accept only two arguments");
                continue;
            } else {
                try {
                    tmpBalance = Integer.parseInt(inputData[1]);
                } catch (NumberFormatException e) {
                    System.out.print("Error: Balance must be a number");
                    continue;
                }
                System.out.println("User with ID = " +
                        _clients.addNewUser(inputData[0], tmpBalance) + " is added");
            }
            break;
        }
    }

    public void viewUserBalance() {

    }

    public void performTransaction() {

    }

    public void viewAllTransactions() {

    }

    public void removeTransactionByID() {}

    public void checkTransferValidity() {}
}
