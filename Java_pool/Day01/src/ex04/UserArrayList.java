package ex04;

import ex04.User;
import ex04.UsersList;

class UserNotFoundException extends RuntimeException {
    public UserNotFoundException(String msg) {
        super(msg);
    }
}

class UsersArrayList implements UsersList {
    private int	_size;
    User[] 		_array;

    public UsersArrayList() {
        _size = 0;
        _array = new User[10];
    }

    public void	add(User user) {
        if (_size == _array.length) {
            User[] tmp = _array;
            _array = new User[_array.length * 2];
            System.arraycopy(tmp, 0, _array, 0, _size);
        }
        _array[_size] = user;
        _size++;
    }

    public User getArId(int id) {
        for (int i = 0; i < _size; i++) {
            if (id == _array[i].getId()) {
                return _array[i];
            }
        }
        throw new UserNotFoundException("User ID = " + id + " not found");
    }

    public User getIndex(int index) {
        if (index <= _array.length - 1) {
            return _array[index];
        } else {
            throw new UserNotFoundException("User Index = " + id + " not found");
        }
    }

    public int getSize() {
        return _size;
    }

    public int getCapacity() {
        return _array.length;
    }
}
