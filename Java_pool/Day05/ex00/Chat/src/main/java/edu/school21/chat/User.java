package edu.school21.chat;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class User {
    private int            id;
    private String         login;
    private String         password;
    private List<Chatroom> createdRooms;
    private List<Chatroom> joinedRooms;

    public User() {
    }

    public User(int id, String login, String password, List<Chatroom> adminRooms, List<Chatroom> joinRooms) {
        this.id = id;
        this.login = login;
        this.password = password;
        this.createdRooms = adminRooms;
        this.joinedRooms = joinRooms;
    }

    /* getters */

    public int getId() {
        return id;
    }

    public String getLogin() {
        return login;
    }

    public String getPassword() {
        return password;
    }

    public List<Chatroom> getJoinedRooms() {
        return joinedRooms;
    }

    public List<Chatroom> getCreatedRooms() {
        return createdRooms;
    }

    /* setters */

    public void setId(int id) {
        this.id = id;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    /* override functions */

    @Override
    public boolean equals (Object o) {
        if (this != o) {
            boolean res = false;
            if (o instanceof User) {
                res = Objects.equals(id, ((User) o).id) && Objects.equals(login, ((User) o).login) &&
                        Objects.equals(password, ((User) o).password) && Objects.equals(createdRooms,
                        ((User) o).createdRooms) && Objects.equals(joinedRooms, ((User) o).joinedRooms);
            }
            return res;
        }
        return true;
    }

    @Override
    public String toString() {
        return  "{ id : " + id + ",\n" +
                "login : " + login + ",\n" +
                "password : " + password +  ",\n" +
                "createdRooms : " + //////// RoomList //////// + ",\n" +
                "joinedRooms : " + /////// RoomList //////// + "}";
    }

}
