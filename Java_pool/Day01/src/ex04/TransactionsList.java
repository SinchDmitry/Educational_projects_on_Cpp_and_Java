package ex04;

interface TransactionsList {
    void add(Transaction t);
    Transaction remove(String id);
    Transaction[] toArray();
}