package ex01;

class UserIdsGenerator {
    private static UserIdsGenerator _singleton = null;
    private int                     _id;

    private UserIdsGenerator() {
        _id = 1;
    }          

    public static UserIdsGenerator getInstance() {
        if (_singleton == null) {
			_singleton = new UserIdsGenerator();
		}
        return _singleton;
    }

    public int generateId() {
        return _id++;
    }
}            