class UserNotFoundException extends RuntimeException {
	public UserNotFoundException(String msg){
		super(msg);
	}
}

class UsersArrayList implements UsersList {
	private int	size;
	User[] 		array;

	public UsersArrayList() {
		this.size = 0;
		this.array = new User[10];
	}

	public void	add(User user) {
		if (this.size == this.array.length) {
			User[] tmp = this.array;
			this.array = new User[this.array.length + this.array.length / 2];
			for (int i = 0; i < size; i++) {
				this.array[i] = tmp[i];
			}
		}
		this.array[size] = user;
		this.size++;
	}

	public User getArId(int id) {
		for (int i = 0; i < this.size; i++) {
			if (id == this.array[i].getId()) {
				return this.array[i];
			}
		}
		throw new UserNotFoundException("User ID = " + id + " not found");
	}

	public User getIndex(int index) {
        return this.array[index];
    }

    public int getSize() {
        return this.size;
    }

    public int getCapacity() {
        return this.array.length;
    }
}
