package ex00;

class User{
    private static int  _actualId = 1;
    private int         _balance;
    private final int   _id;
    private String      _name;

    public  User(String name, int balance) {
        _id = _actualId++;
        _name = name;
        _balance = balance;
        if (_balance < 0) {
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

    @Override
    public String toString() {
        return String.format("Welcome to Vice sity!\n\tname : %-8s | id : %d\n\tcash : %d\n",
            this.getName(), this.getId(), this.getBalance());
    }
}
