package edu.school21.sockets.services;

public interface UsersService {
    public boolean signUp(String username, String password);
    public boolean signIn(String username, String password);
    public void saveMessage(String user, String message);

}