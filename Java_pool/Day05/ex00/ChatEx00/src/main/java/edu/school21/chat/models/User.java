package edu.school21.chat.models;

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
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return id == user.id && login.equals(user.login) && password.equals(user.password)
                && createdRooms.equals(user.createdRooms) && joinedRooms.equals(user.joinedRooms);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, login, password, createdRooms, joinedRooms);
    }

//    @Override
//    public String toString() {
//        return  "id : " + id + ",\n" +
//                "login : " + login + ",\n" +
//                "password : " + password +  ",\n" +
//                "createdRooms : " + createdRooms + ",\n" +
//                "joinedRooms : " + joinedRooms;
//    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", login='" + login + '\'' +
                ", password='" + password + '\'' +
                ", createdRooms=" + createdRooms +
                ", joinedRooms=" + joinedRooms +
                '}';
    }
}
