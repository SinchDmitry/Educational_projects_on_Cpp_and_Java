package ex02;

public class Program {
    public static void  main(String[] args) {
		User dima = new User("Dimka", 200);
        User paul = new User("Pauk", 50000);
		UsersArrayList list = new UsersArrayList();

        System.out.println(dima);
        System.out.println(paul);
		list.add(dima);
		list.add(paul);
		System.out.println("id of last client : " + paul.getId());

		System.out.println("4 new clients, but we will add only Sanyok to base");
		for (int i = 0; i < 3; i++) {
			User anon = new User("Anonim" + i, 5000);
			System.out.println(anon);
		}

		User alex = new User("Sanek", 1000);
		System.out.println(alex);
		list.add(alex);
		System.out.println("Id of last client : " + alex.getId());
		System.out.println("We have __" + list.getSize() + "__ people in base");

		System.out.println("10 new clients from North Korea, we will add them to base");
		for (int i = 0; i < 10; i++) {
			User kim = new User("Kim" + i, 5);
			list.add(kim);
			System.out.println(kim);
		}

		System.out.println("We have __" + list.getSize() + "__ people in base");
		System.out.println("We have __" + (list.getCapacity() + 1) + "__ clients");

		System.out.println();
		System.out.println("Client numer = 1");
        System.out.println(list.getIndex(1).toString());

        System.out.println("Client with ID = 1");
        System.out.println(list.getArId(1).toString());

		System.out.println("Someone from Kim's");
        System.out.println(list.getArId(11).toString());

		System.out.println("Who da fook is dat guy?");
		try {
        	System.out.println(list.getArId(17));
		}
		catch (UserNotFoundException e) {
			System.out.printf("UserNotFoundException: %s\n", e.getMessage());
		}
	}  
}