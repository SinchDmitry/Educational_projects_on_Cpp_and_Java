package edu.school21.chat.models;

import java.util.List;
import java.util.Objects;

public class Chatroom {
    private int             id;
    private String          roomName;
    private User            godOfRoom;
    private List<Message>   messagesInRoom;

    public Chatroom(int id, String roomName, User godOfRoom, List<Message> messagesInRoom) {
        this.id = id;
        this.roomName = roomName;
        this.godOfRoom = godOfRoom;
        this.messagesInRoom = messagesInRoom;
    }

    public int getId() {
        return id;
    }

    public String getRoomName() {
        return roomName;
    }

    public User getGodOfRoom() {
        return godOfRoom;
    }

    public List<Message> getMessagesInRoom() {
        return messagesInRoom;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setRoomName(String roomName) {
        this.roomName = roomName;
    }

    public void setGodOfRoom(User godOfRoom) {
        this.godOfRoom = godOfRoom;
    }

    public void setMessagesInRoom(List<Message> messagesInRoom) {
        this.messagesInRoom = messagesInRoom;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Chatroom chatroom = (Chatroom) o;
        return id == chatroom.id && roomName.equals(chatroom.roomName) && godOfRoom.equals(chatroom.godOfRoom) && messagesInRoom.equals(chatroom.messagesInRoom);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, roomName, godOfRoom, messagesInRoom);
    }

    @Override
    public String toString() {
        return "Chatroom{" +
                "id=" + id +
                ", roomName='" + roomName + '\'' +
                ", godOfRoom=" + godOfRoom +
                ", messagesInRoom=" + messagesInRoom +
                '}';
    }
}
