package edu.school21.chat.repositories;

import edu.school21.chat.models.Message;

import javax.activation.DataSource;
import java.util.Optional;

public class MessagesRepositoryJdbcImpl implements MessagesRepository {
    private DataSource dataSource;
    public MessagesRepositoryJdbcImpl(DataSource dataSource) {
        this.dataSource = dataSource;
    }

    @Override
    public Optional<Message> findById(int id) {

        return Optional.empty();
    }
}
