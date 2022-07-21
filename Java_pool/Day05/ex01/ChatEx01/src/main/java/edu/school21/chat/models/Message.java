package edu.school21.chat.models;

import java.time.LocalDateTime;
import java.util.Objects;

public class Message {
    private Long             id;
    private User            author;
    private Chatroom        chatroom;
    private String          message;
    private LocalDateTime   data;

    public Message(Long id, User author, Chatroom chatroom, String message, LocalDateTime data) {
        this.id = id;
        this.author = author;
        this.chatroom = chatroom;
        this.message = message;
        this.data = data;
    }

    public Long getId() {
        return id;
    }

    public User getAuthor() {
        return author;
    }

    public Chatroom getChatroom() {
        return chatroom;
    }

    public String getMessage() {
        return message;
    }

    public LocalDateTime getData() {
        return data;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setAuthor(User author) {
        this.author = author;
    }

    public void setChatroom(Chatroom chatroom) {
        this.chatroom = chatroom;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public void setData(LocalDateTime data) {
        this.data = data;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Message message1 = (Message) o;
        return id == message1.id && author.equals(message1.author) && chatroom.equals(message1.chatroom) && message.equals(message1.message) && data.equals(message1.data);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, author, chatroom, message, data);
    }

    @Override
    public String toString() {
        return "Message{" +
                "id=" + id +
                ", author=" + author +
                ", chatroom=" + chatroom +
                ", message='" + message + '\'' +
                ", data=" + data +
                '}';
    }

}
