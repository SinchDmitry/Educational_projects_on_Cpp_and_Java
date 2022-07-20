package ex00;

public class Program {
    public static void  main(String[] args) {
        User dima = new User("Dimka", 200);
        User sber = new User("SberBank", 100000);
        Transaction tOne = new Transaction(sber, dima, Transaction.Operation.credit, -50000);
        Transaction tTwo = new Transaction(sber, dima, Transaction.Operation.debit, 60000);

        System.out.println(dima);
        System.out.println(sber);
        System.out.println(tOne);
        System.out.println(tOne);
        dima.setName("Dmitriy Georgievich");
        dima.setBalance(dima.getBalance() + 19800);
        System.out.println(dima);
        System.out.println(tTwo);
        System.out.println(tTwo);
        dima.setName("dimka");
        System.out.println(dima);
    }   
}