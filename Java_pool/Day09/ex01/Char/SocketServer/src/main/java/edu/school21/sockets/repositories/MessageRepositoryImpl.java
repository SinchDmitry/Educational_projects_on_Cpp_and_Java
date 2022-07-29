package edu.school21.sockets.repositories;

import edu.school21.sockets.models.Message;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import javax.sql.DataSource;
import java.util.List;
import java.util.Optional;

@Component("messageRepository")
public class MessageRepositoryImpl implements MessageRepository {
    private final JdbcTemplate jdbcTemplate;

    @Autowired
    public MessageRepositoryImpl(@Qualifier("hikariDataSource") DataSource dataSource) {
        this.jdbcTemplate = new JdbcTemplate(dataSource);
    }


    @Override
    public Optional<Message> findById(Long id) {
        try {
            return this.jdbcTemplate.query("select * from messages where id = ?;", new Object[]{id},
                    new BeanPropertyRowMapper<>(Message.class)).stream().findAny();
        } catch (EmptyResultDataAccessException e) {
            return Optional.empty();
        }
    }

    @Override
    public List<Message> findAll() {
        return this.jdbcTemplate.query("select * from messages;", new BeanPropertyRowMapper<>(Message.class));
    }

    @Override
    public void save(Message entity) {
        this.jdbcTemplate.update("insert into messages(author, message, data) values(?, ?, ?)",
                entity.getAuthor(), entity.getMessage(), entity.getData());
    }

    @Override
    public void update(Message entity) {
        this.jdbcTemplate.update("update messages set author = ?, message = ?, " +
                        "data = ? where id = ?;",
                entity.getAuthor(), entity.getMessage(), entity.getData(), entity.getId());
    }

    @Override
    public void delete(Long id) {
        this.jdbcTemplate.update("delete from messages where id = ?;", id);
    }
}
