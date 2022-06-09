import java.util.UUID;
import java.util.Locale.Category;

class Transaction {
    enum    Operation   {debet, credit};
    private UUID        id;
    private User        recipient;
    private User        sender;
    private int         amount;
    private Operation   type;
    private String      opName;     

    public  Transaction(User recipient, User sender, Operation type, int amount) {
        this.recipient = recipient;
        this.sender = sender;
        this.id = UUID.randomUUID();
        this.amount = 0;
        this.type = type;
        this.opName = "INCOME";
        if ((this.type == Operation.debet && amount > 0 && recipient.getBalance() > amount) || 
            (this.type == Operation.credit && amount < 0 && recipient.getBalance() > (-1) * amount)) {
            this.amount = amount;
        }
        if (this.type == Operation.debet){
            opName = "OUTCOME";
        }
    }

    public UUID getId() {
        return this.id;
    }

    public int getAmount() {
        return this.amount;
    }

    public String getOpName() {
        return this.opName;
    }

    public User getSender() {
        return this.sender;
    }

    public User getRecipient() {
        return this.recipient;
    }

    public void setBalance(User recipient, User sender, int amount) {
        sender.setBalance(sender.getBalance() - amount);
        recipient.setBalance(recipient.getBalance() + amount);
    }

    @Override
    public String toString() {
        setBalance(recipient, sender, amount);
        return String.format("\nNew transaction registred :\n\tid : %s | %s -> %s | sum : %d$ | type : %s\nNew balanse:\n\t%10s : %d\n\t%10s : %d\n", 
            this.getId(), this.getSender().getName(), this.getRecipient().getName(), this.getAmount(),
            this.getOpName(), this.getSender().getName(), this.getSender().getBalance(),
            this.getRecipient().getName(), this.getRecipient().getBalance());
    }
}
