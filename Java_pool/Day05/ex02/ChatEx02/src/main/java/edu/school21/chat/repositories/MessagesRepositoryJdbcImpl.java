package edu.school21.chat.repositories;

import edu.school21.chat.models.Chatroom;
import edu.school21.chat.models.Message;
import edu.school21.chat.models.User;

import javax.sql.DataSource;
import java.sql.*;
import java.util.Optional;

public class MessagesRepositoryJdbcImpl implements MessagesRepository {
    private DataSource dataSource;
    private String     messageInfo;

    public class NotSavedSubEntityException extends RuntimeException {
        public NotSavedSubEntityException(String msg) {
            super(msg);
        }
    }

    public MessagesRepositoryJdbcImpl(DataSource dataSource) {
        this.dataSource = dataSource;
    }

    @Override
    public Optional<Message> findById(Long id) {
        try {
            Connection conSQL = dataSource.getConnection();
            conSQL.setSchema("chat");
            String requestText = "select chat.message.*, chat.user.login as user_login, " +
                    "chat.user.password as user_password, chat.chatroom.name as room_name" +
                    " from chat.user, chat.chatroom, chat.message where chat.message.author_id = chat.user.id" +
                    " and chat.message.room_id = chat.chatroom.id and chat.message.id = ?;";
            PreparedStatement request = conSQL.prepareStatement(requestText);
            request.setLong(1, id);
            ResultSet res = request.executeQuery();
            if (!res.next()) {
                System.err.println("Error : no message with this id in base");
                return Optional.empty();
            }

            User user = new User();
            Chatroom room = new Chatroom();
            Message msg = new Message(id, user, room, null, null);
            msg.setMessage(res.getString("text"));
            msg.setData(res.getTimestamp("time").toLocalDateTime());
            user.setId(res.getLong("author_id"));
            user.setLogin(res.getString("user_login"));
            user.setPassword(res.getString("user_password"));
            room.setId(res.getLong("room_id"));
            room.setRoomName(res.getString("room_name"));

            return Optional.of(msg);
        } catch (SQLException e) {
            System.err.printf("%s\n", e.getMessage());
        }
        return Optional.empty();
    }

    @Override
    public void save(Message message) {
        if (message.getAuthor().getId() == null || message.getChatroom().getId() == null) {
            throw new NotSavedSubEntityException("Error : ID is null");
        }
        try {
            Connection conSQL = dataSource.getConnection();
            conSQL.setSchema("chat");
            String requestText = "insert into chat.message (author_id, room_id, text, time) " +
                    "values (?, ?, ?, ?) returning id;";
            PreparedStatement request = conSQL.prepareStatement(requestText);
            request.setLong(1, message.getAuthor().getId());
            request.setLong(2, message.getChatroom().getId());
            request.setString(3, message.getMessage());
            request.setTimestamp(4, Timestamp.valueOf(message.getData()));
            ResultSet res = request.executeQuery();
            if (!res.next()) {
                throw new NotSavedSubEntityException("Error : failed to save message");
            }
            message.setId(res.getLong(1));
        } catch (SQLException e) {
            throw new NotSavedSubEntityException(e.getMessage());
        }
    }
}
