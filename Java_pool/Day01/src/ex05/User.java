package ex05;

class User{
    private int         _balance;
    private final int   _id;
    private String      _name;
	TransactionsList _tList;

    public  User(String name, int balance) {
        _id = UserIdsGenerator.getInstance().generateId();
        _name = name;
        _balance = balance;
		_tList = new TransactionsLinkedList();
        if (balance < 0) {
            _balance = 0;
        }
	}

	public  int getId() {
        return _id;
    }

    public  String getName() {
        return _name;
    }

    public  int getBalance() {
        return _balance;
    }

	public  void setName(String name) {
		_name = name;
	}

	public  void setBalance(int balance) {
		if (balance >= 0) {
			_balance = balance;
		}
	}

	public Transaction[] getTransactionArray() {
        return _tList.toArray();
    }
	
    public Transaction removeTransaction(String id) {
		return _tList.remove(id);
    }

	public void addTransaction(Transaction t) {
		_tList.add(t);
	}

    @Override
    public String toString() {
        return String.format("\tname : %-8s | id : %d\n\tcash : %d\n",
            this.getName(), this.getId(), this.getBalance());
    }
}
