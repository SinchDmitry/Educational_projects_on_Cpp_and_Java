class User{
    private int         balance;
    private int         id;
    private String      name;
	TransactionsList	tList;

    public  User(String name, int balance) {
        this.id = UserIdsGenerator.getInstance().generateId();
        this.name = name;      
        this.balance = balance;
		this.tList = new TransactionsLinkedList();
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

	public Transaction[] getTransactionArray() {
        return this.tList.toArray();
    }
	
    public Transaction removeTransaction(String id) {
		return this.tList.remove(id);
    }

	public void addTransaction(Transaction t) {
		this.tList.add(t);
	}

    @Override
    public String toString() {
        return String.format("\tname : %-8s | id : %d\n\tcash : %d\n",
            this.getName(), this.getId(), this.getBalance());
    }
}
