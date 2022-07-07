package ex05;

class IncorrectTransactionException extends RuntimeException {
    public IncorrectTransactionException(String msg) {
        super(msg);
    }
}
public class TransactionsService {
    private int _length = 0;
    private final UsersList _users;

    public UsersList getUsers() {
        return _users;
    }

    public TransactionsService() {
        _users = new UsersArrayList();
    }

    public int getLength() {
        return _length;
    }

    public int addNewUser(String name, int balance) {
        User newUser = new User(name, balance);
        _users.add(newUser);
        _length++;
        return newUser.getId();
    }

    public int getBalance (int id) {
        return _users.getArId(id).getBalance();
    }

    public void doTransaction ( int idSender, int idRecipient, int amount) {
        User sender = _users.getArId(idSender);
        User recipient = _users.getArId(idRecipient);

        if (amount > 0 && sender.getBalance() < amount ||
                amount < 0 && recipient.getBalance() < -amount) {
            throw new IncorrectTransactionException("Insufficient funds");
        }

        Transaction.Operation type = amount < 0 ? Transaction.Operation.debit
                : Transaction.Operation.credit;
        Transaction trSender = new Transaction(sender, recipient, type, -amount);
        Transaction trRecipient = trSender.analogTransaction(trSender);

        sender.addTransaction(trSender);
        sender.setBalance(sender.getBalance() - amount);
        recipient.addTransaction(trRecipient);
        recipient.setBalance(recipient.getBalance() + amount);
    }

    public Transaction[] getTransactionList(int id) {
        return _users.getArId(id).getTransactionArray();
    }

    private boolean checkTwoUsersOp(User objContact, Transaction objTr) {
        Transaction[] contactTr = objContact.getTransactionArray();
        for (int k = 0; k < contactTr.length; ++k) {
            if (contactTr[k].getId().equals(objTr.getId())) {
                return true;
            }
        }
        return false;
    }

    public Transaction[] checkCorrectTr() {
        TransactionsList tmp = new TransactionsLinkedList();
        for (int i = 0; i < _users.getSize(); ++i) {
            User obj = _users.getIndex(i);
            Transaction[] objTr = obj.getTransactionArray();
            for (int j = 0; j < objTr.length; ++j) {
                User objContact = objTr[j].getSender();
                if (objContact.getId() == obj.getId()) {
                    objContact = objTr[j].getRecipient();
                }
                if (!checkTwoUsersOp(objContact, objTr[j])) {
                    tmp.add(objTr[j]);
                }
            }
        }
        return tmp.toArray();
    }

    public void removeTr(int id, String trId) {
        _users.getArId(id).removeTransaction(trId);
    }
}
