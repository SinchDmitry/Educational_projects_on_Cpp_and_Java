package ex04;

public class Program {
	public static void main(String[] args) {
        TransactionsService clients = new TransactionsService();

        System.out.println("-Create Users-");

        clients.addNewUser("Dimka", 1200);
        clients.addNewUser("Pauk", 50000);
        clients.addNewUser("Sanek", 1000);

        for (int i = 0; i < clients.getLength(); ++i) {
                System.out.println(clients.getUsers().getIndex(i));
        }

        System.out.println("-Do transactions-");
        try {
                clients.doTransaction(2, 3, 1000);
                System.out.println("OK");
                clients.doTransaction(2, 1, 1000);
                System.out.println("OK");
                clients.doTransaction(3, 2, 1500);
                System.out.println("OK");
                clients.doTransaction(3, 1, 3000);
                System.out.println("OK");
        } catch (IncorrectTransactionException e) {
                System.out.printf("IncorrectTransactionException: %s\n", e.getMessage());
        }
        Transaction[] paulTr = clients.getTransactionList(2);
        for (int i = 0; i < paulTr.length; ++i) {
                System.out.println(paulTr[i].toString());
        }

        System.out.println("-Show num of illegal transactions-");
        Transaction[] errTr = clients.checkCorrectTr();
        System.out.println(errTr.length + " incorrect transactions registered");

        System.out.println("-Remove some transaction-");
        clients.removeTr(2, paulTr[1].getId());

        System.out.println("-Show num of illegal transactions-");
        errTr = clients.checkCorrectTr();
        System.out.println(errTr.length + " incorrect transactions registered");
    }
}