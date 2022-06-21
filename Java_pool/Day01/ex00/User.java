class User{
    private static int  actualId = 1;
    private int         balance;
    private int         id;
    private String      name;

    public  User(String name, int balance) {
        this.id = actualId++;
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
        return String.format("Welcome to Vice sity!\n\tname : %-8s | id : %d\n\tcash : %d\n",
            this.getName(), this.getId(), this.getBalance());
    }
}
