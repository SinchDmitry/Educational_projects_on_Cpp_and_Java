package ex03;

class TransactionNotFoundException extends RuntimeException {
    public TransactionNotFoundException(String msg) {
        super(msg);
    }
}

public class TransactionsLinkedList implements TransactionsList {

	static class Node {
		public Node _prev;
		public Node _next;
		public Transaction  _t;

		public Node(Node prev, Node next, Transaction t) {
			_prev = prev;
			_next = next;
			_t = t;
		}
	}

	private int 	_size;
	private Node 	_first;
	private Node 	_last;

	private void setNewExtremeVal(Node input, String type) {
		if (type.equals("first")) {
			_first = input;
			_first._prev = null;
		} else if (type.equals("last")) {
			_last = input;
			_last._next = null;
		}

	}

	public TransactionsLinkedList() {
        _size = 0;
		_first = null;
		_last = null;
    }

	@Override
	public void	add(Transaction t) {
		Node tmp;

		if (_last == null){
			tmp = new Node(null, null, t);
			_last = tmp;
			_first = tmp;
		} else {
			tmp = new Node(_last, null, t);
			_last._next = tmp;
			_last = tmp;
		}
		_size++;
	}

	@Override
	public Transaction	remove(String id) {
		Node tmp = _first;

		while (tmp != null) {
			if (tmp._t.getId().equals(id)) {
				System.out.println("I found and remove " + id + " transaction");
				if (tmp == _first) {
					System.out.println("It's first");
					if (tmp == _last) {
						System.out.println("It's last");
						_last = null;
						_first = null;
					} else {
						setNewExtremeVal(tmp._next, "first");
					}
				} else if (tmp == _last) {
					System.out.println("It's last");
					setNewExtremeVal(tmp._prev, "last");
				} else {
					tmp._prev._next = tmp._next;
					tmp._next._prev = tmp._prev;
				}
				_size--;
				return tmp._t;
			}
			tmp = tmp._next;
		}
		throw new TransactionNotFoundException("Transaction not found");
	}

	@Override
	public Transaction[] toArray() {
		if (this.getSize() != 0) {
			Transaction[] arr = new Transaction[this.getSize()];
			Node tmp = _first;
			for (int i = 0; i < this.getSize(); ++i) {
				arr[i] = tmp._t;
				tmp = tmp._next;
			}
        	return arr;
		} else {
			System.out.println("It's empty");
			return (null);
		}
    }

	public int getSize() {
        return _size;
    }
}



