package ex01;

public class Program {
    public static void  main(String[] args) {
        User dima = new User("Dimka", 200);
        User sber = new User("SberBank", 100000);

        System.out.println(dima);
        System.out.println(sber);

		for (int i = 0; i < 3; i++) {
			User anon = new User("Anonim" + i, 5000);
			System.out.println(anon);
		}
        
    }   
}