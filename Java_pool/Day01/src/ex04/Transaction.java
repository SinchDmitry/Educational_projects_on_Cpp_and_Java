package ex04;

import java.util.UUID;

class Transaction {
    enum    Operation   {
        debit,
        credit
    };
    private final String    _id;
    private User            _recipient;
    private User            _sender;
    private int             _amount;
    private String          _opName;

    public Transaction(User recipient, User sender, Operation type, int amount) {
        _recipient = recipient;
        _sender = sender;
        _id = UUID.randomUUID().toString();
        _amount = 0;
        _opName = "INCOME";
        if ((type == Operation.debit && amount > 0 && recipient.getBalance() > amount) ||
            (type == Operation.credit && amount < 0 && recipient.getBalance() > (-1) * amount)) {
            _amount = amount;
        }
        if (type == Operation.debit){
            _opName = "OUTCOME";
        }
    }

    public Transaction(Transaction copy) {
        _id = copy._id;
        _amount = copy._amount;
        _recipient = copy._recipient;
        _sender = copy._sender;
        _opName = copy._opName;
    }

    public String getId() {
        return _id;
    }

    public int getAmount() {
        return _amount;
    }

    public String getOpName() {
        return _opName;
    }

    public User getSender() {
        return _sender;
    }

    public User getRecipient() {
        return _recipient;
    }

    public void setBalance(User recipient, User sender, int amount) {
        sender.setBalance(sender.getBalance() - amount);
        recipient.setBalance(recipient.getBalance() + amount);
    }

    public Transaction analogTransaction(Transaction firstTr) {
        Transaction secondTr = new Transaction(firstTr);
        secondTr._amount = -firstTr._amount;
        secondTr._recipient = firstTr._sender;
        secondTr._sender = firstTr._recipient;
        secondTr._opName = secondTr._opName.equals("INCOME") ? "OUTCOME" : "INCOME";
        return secondTr;
    }

    @Override
    public String toString() {
        return String.format("\nTransaction registred :\n\tid : %s | %s -> %s | sum : %d$ | type : %s\nNew balanse:\n\t%10s : %d\n\t%10s : %d\n",
            this.getId(), this.getSender().getName(), this.getRecipient().getName(), this.getAmount(),
            this.getOpName(), this.getSender().getName(), this.getSender().getBalance(),
            this.getRecipient().getName(), this.getRecipient().getBalance());
    }
}
