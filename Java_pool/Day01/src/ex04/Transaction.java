package ex04;

import java.util.UUID;

class Transaction {
    enum    Operation   {
        debet,
        credit
    };
    private final String    _id;
    private final User _recipient;
    private final User _sender;
    private int             _amount;
    private String          _opName;

    public  Transaction(User recipient, User sender, Operation type, int amount) {
        _recipient = recipient;
        _sender = sender;
        _id = UUID.randomUUID().toString();
        _amount = 0;
        _opName = "INCOME";
        if ((type == Operation.debet && amount > 0 && recipient.getBalance() > amount) ||
            (type == Operation.credit && amount < 0 && recipient.getBalance() > (-1) * amount)) {
            _amount = amount;
        }
        if (type == Operation.debet){
            _opName = "OUTCOME";
        }
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

    @Override
    public String toString() {
        return String.format("\nNew transaction registred :\n\tid : %s | %s -> %s | sum : %d$ | type : %s\nNew balanse:\n\t%10s : %d\n\t%10s : %d\n", 
            this.getId(), this.getSender().getName(), this.getRecipient().getName(), this.getAmount(),
            this.getOpName(), this.getSender().getName(), this.getSender().getBalance(),
            this.getRecipient().getName(), this.getRecipient().getBalance());
    }
}
