package ex04;

class TransactionNotFoundException extends RuntimeException {
    public TransactionNotFoundException(String msg) {
        super(msg);
    }
}

class Node {
	Node prev; 
	Node next;
	Transaction t;

	public Node(Node prev, Node next, Transaction t) {
		this.prev = prev;
		this.next = next;
		this.t = t;
	}
}

public class TransactionsLinkedList implements TransactionsList {

	private int size;
	private Node first;
	private Node last;

	public TransactionsLinkedList() {
        this.size = 0;
		this.first = null;
		this.last = null;
    }

	@Override
	public void	add(Transaction t) {
		Node tmp;

		if (this.last == null){
			tmp = new Node(null, null, t);
			this.last = tmp;
			this.first = tmp;
		} else {
			tmp = new Node(this.last, null, t);
			this.last.next = tmp;
			this.last = tmp;
		}
		this.size++;
	}

	@Override
	public Transaction	remove(String id) {
		Node tmp = this.first;

		while (tmp != null) {
			if (tmp.t.getId().equals(id)) {
				if (tmp.prev != null) {
					tmp.prev.next = tmp.next;
				} else {
					this.first = null;
				}
				if (tmp.next != null) {
                	tmp.next.prev = tmp.prev;
				} else {
					this.last = null;
				}
				this.size--;
				return tmp.t;
			}
			tmp = tmp.next;
		}
		throw new TransactionNotFoundException("Transaction not found");
	}

	public Transaction[] toArray() {
        Transaction[] arr = new Transaction[this.size];
        Node tmp = this.first;
        for (int i = 0; i < this.size; ++i) {
            arr[i] = tmp.t;
            tmp = tmp.next;
        }
        return arr;
    }

	public int getSize() {
        return this.size;
    }
}



