class UserIdsGenerator {
    private static UserIdsGenerator singleton = null;
    private int                     id;

    private UserIdsGenerator() {
        this.id = 1;
    }          

    public static UserIdsGenerator getInstance() {
        if (singleton == null) {
			singleton = new UserIdsGenerator();
		}
        return singleton;
    }

    public int generateId() {
        return this.id++;
    }
}            