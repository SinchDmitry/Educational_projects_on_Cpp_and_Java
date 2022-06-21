class User{
    private int         balance;
    private int         id;
    private String      name;

    public  User(String name, int balance) {
        this.id = UserIdsGenerator.getInstance().generateId();
        this.name = name;      
        this.balance = balance;
        if (balance < 0) {
            this.balance = 0;
        }
	}

	public  int getId() {
        return id;
    }

    public  String getName() {
        return name;
    }

    public  int getBalance() {
        return balance;
    }

    public  void setName(String name) {
        this.name = name;
    }

    public  void setBalance(int balance) {
        if (balance >= 0) {
            this.balance = balance;
        }
    }

    @Override
    public String toString() {
        return String.format("\tname : %-8s | id : %d\n\tcash : %d\n",
            this.getName(), this.getId(), this.getBalance());
    }
}
