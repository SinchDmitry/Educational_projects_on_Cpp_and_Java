package edu.school21.chat.repositories;

import edu.school21.chat.models.Chatroom;
import edu.school21.chat.models.Message;
import edu.school21.chat.models.User;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Optional;

public class MessagesRepositoryJdbcImpl implements MessagesRepository {
    private DataSource dataSource;
    private String     messageInfo;

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
}
