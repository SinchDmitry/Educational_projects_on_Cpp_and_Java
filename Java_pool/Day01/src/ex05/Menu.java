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
                    case 1 : addNewUser();
                        break;
                    case 2 : viewUserBalance(input);
                        break;
                    case 3 : performTransaction();
                        break;
                    case 4 : viewAllTransactions(input);
                        break;
                    case 5 :
                        if (_mode) {
                            removeTransactionByID(input);
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
                System.out.println("====================================================================");
            } else {
                throw new WrongNumOfCommand("Error : wrong number of command");
            }
        }
    }

    public void addNewUser() {
        Scanner input = new Scanner(System.in);
        String tmpName;
        int    tmpBalance;
        while (true) {
            try {
                tmpName = input.nextLine();
            } catch (NoSuchElementException e) {
                System.out.println("Error : input arguments");
                continue;
            }
            String[] inputData = tmpName.split("\\s+");
            if (inputData.length != 2){
                System.out.println("Error : this command accept only two arguments");
                continue;
            } else {
                try {
                    tmpBalance = Integer.parseInt(inputData[1]);
                } catch (NumberFormatException e) {
                    System.out.print("Error: balance must be a number");
                    continue;
                }
                System.out.println("User with ID = " +
                        _clients.addNewUser(inputData[0], tmpBalance) + " is added");
            }
            break;
        }
    }

    public void viewUserBalance(Scanner input) {
        int tmpId;
        while (true) {
            System.out.println("Enter a user ID");
            if (input.hasNextLine()) {
                try {
                    tmpId = input.nextInt();
                } catch (NoSuchElementException e) {
                    System.out.println("Error: user ID must be a number");
                    continue;
                }
                try {
                    System.out.printf("%s - %d\n", _clients.getUserName(tmpId),
                            _clients.getBalance(tmpId));
                } catch (RuntimeException e) {
                    System.out.printf("Error: %s", e.getMessage());
                    continue;
                }
                break;
            } else {
                System.out.println("Error : input arguments");
            }
        }
    }

    public void performTransaction() {
        Scanner input = new Scanner(System.in);
        String  tmpName;
        int[]   inputIntData = new int[3];
        while(true) {
            System.out.println("Enter a sender ID, a recipient ID, and a transfer amount");
            try {
                tmpName = input.nextLine();
            } catch (NoSuchElementException e) {
                System.out.println("Error : input arguments");
                continue;
            }
            String[] inputData = tmpName.split("\\s+");
            if (inputData.length != 3){
                System.out.println("Error : this command accept only two arguments");
                continue;
            } else {
                int i = 0;
                try {
                    for (; i < 3; ++i) {
                        inputIntData[i] = Integer.parseInt(inputData[i]);
                    }
                } catch (NumberFormatException e) {
                    switch (i) {
                        case 0 : System.out.print("Error: sender ID must be a number");
                        case 1 : System.out.print("Error: recipient ID must be a number");
                        case 2 : System.out.print("Error: amount must be a number");
                    }
                    continue;
                }
                try {
                    _clients.doTransaction(inputIntData[0], inputIntData[1], inputIntData[2]);
                    System.out.println("The transfer is complete");
                } catch (RuntimeException e) {
                    System.out.printf("Error : %s\n", e.getMessage());
                }
            }
            break;
        }
    }

    public void viewAllTransactions(Scanner input) {
        int             tmpId;
        Transaction[]   usersTr;
        while (true) {
            System.out.println("Enter a user ID");
            if (input.hasNextLine()) {
                try {
                    tmpId = input.nextInt();
                } catch (NoSuchElementException e) {
                    System.out.println("Error: user ID must be a number");
                    continue;
                }
                try {
                    usersTr = _clients.getTransactionList(tmpId);
                    for (int i = 0; i < usersTr.length; ++i) {
                        User tmp = usersTr[i].getRecipient();
                        System.out.printf("To %s(id = %d) %d with id = %s\n",
                                tmp.getName(), tmp.getId(), usersTr[i].getAmount(),
                                usersTr[i].getId());
                    }
                    break;
                } catch (RuntimeException e) {
                    System.out.printf("Error: %s. ", e.getMessage());
                }
            }
        }
    }

    public void removeTransactionByID(Scanner input) {
        int             tmpId;
        String          tmpTrId;
        Transaction[]   usersTr;
        Transaction     removedTr;
        while (true) {
            System.out.println("Enter a user ID and a transfer ID");
            if (input.hasNextLine()) {
                try {
                    tmpId = input.nextInt();
                } catch (NoSuchElementException e) {
                    System.out.println("Error: user ID must be a number");
                    continue;
                }
                try {
                    tmpTrId = input.next();
                } catch (NoSuchElementException e) {
                    System.out.println("Error: transaction ID must be in string format");
                    continue;
                }
                try {
                    removedTr = _clients.removeTr(tmpId, tmpTrId);
                    System.out.printf("Transfer to %s(id = %d) %d removed\n",
                            removedTr.getRecipient().getName(), removedTr.getRecipient().getId(),
                            -removedTr.getAmount());
                    break;
                } catch (RuntimeException e) {
                    System.out.printf("Error: %s. ", e.getMessage());
                }
            }
        }
    }

    public boolean checkTransaction(Transaction[] userTr, String trId) {
        for (int i = 0; i < userTr.length; ++i ) {
            if (userTr[i].getId().equals(trId)) {
                return true;
            }
        }
        return false;
    }

    public void checkTransferValidity() {
        System.out.println("Check results:");
        Transaction[] errTr = _clients.checkCorrectTr();
        for (int i = 0; i < errTr.length; ++i) {
            User tmp = errTr[i].getRecipient();
            Transaction[] recTr = tmp.getTransactionArray();
            if (!checkTransaction(recTr, errTr[i].getId())) {
                tmp = errTr[i].getSender();
            }
            System.out.printf("%s(id = %d) has an unacknowledged transfer id = %s for %d\n",
                    tmp.getName(), tmp.getId(), errTr[i].getId(), errTr[i].getAmount());
        }
    }
}
