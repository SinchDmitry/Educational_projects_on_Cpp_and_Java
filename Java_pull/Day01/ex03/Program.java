public class Program {
	public static void main(String[] args) {
		User dima = new User("Dimka", 1200);
        User paul = new User("Pauk", 50000);
		User alex = new User("Sanek", 1000);

		System.out.println(dima.toString());
        System.out.println(paul.toString());
		System.out.println(alex.toString());

        Transaction tOne = new Transaction(paul, alex, Transaction.Operation.debet, 1000);
		tOne.setBalance(paul, alex, 1000);
		System.out.println(tOne.toString());
        paul.addTransaction(tOne);
        alex.addTransaction(tOne);

        Transaction tTwo = new Transaction(paul, dima, Transaction.Operation.credit, -800);
		tTwo.setBalance(paul, dima, -800);
		System.out.println(tTwo.toString());
        paul.addTransaction(tTwo);
        dima.addTransaction(tTwo);

        System.out.println("Dima's transactions");
        Transaction[] dimaTr = dima.getTransactionArray();
        for (int i = 0; i < dimaTr.length; ++i) {
			System.out.printf("########### %d ###########\n", i);
            System.out.println(dimaTr[i].toString());
        }
		System.out.printf("########### END ###########\n");

        System.out.println("Paul's transactions");
        Transaction[] paulTr = paul.getTransactionArray();
        for (int i = 0; i < paulTr.length; ++i) {
			System.out.printf("########### %d# ##########\n", i);
            System.out.println(paulTr[i].toString());
        }
		System.out.printf("########### END ###########\n");

        System.out.println("Verni sotku");
        Transaction[] alexTr = alex.getTransactionArray();
        for (int i = 0; i < alexTr.length; ++i) {
			System.out.printf("########### %d ###########\n", i);
            System.out.println(alexTr[i].toString());
        }
		System.out.printf("########### END ###########\n");

        System.out.println("Removing Paul's transactions by ID");
        String id =paulTr[1].getId();
        System.out.printf("ID: %s\n", id);
        paul.removeTransaction(id);

        System.out.println();
        System.out.println("Paul's transactions");
        paulTr = paul.getTransactionArray();
        for (int i = 0; i <paulTr.length; ++i) {
            System.out.println(paulTr[i].toString());
        }

        System.out.println("Removing Paul's transactions by same ID");
        System.out.printf("ID: %s\n", id);
        try {
            paul.removeTransaction(id);
        } catch (RuntimeException e) {
            System.out.printf("Caught TransactionNotFoundException: %s\n", e.getMessage());
        }
	}
}