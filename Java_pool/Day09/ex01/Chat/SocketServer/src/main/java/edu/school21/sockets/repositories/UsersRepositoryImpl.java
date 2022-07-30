package edu.school21.sockets.repositories;

import edu.school21.sockets.models.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import javax.sql.DataSource;
import java.util.List;
import java.util.Optional;

@Component("usersRepository")
public class UsersRepositoryImpl implements UsersRepository {
    private final JdbcTemplate jdbcTemplate;

    @Autowired
    public UsersRepositoryImpl(@Qualifier("hikariDataSource") DataSource dataSource) {
        this.jdbcTemplate = new JdbcTemplate(dataSource);
    }

    @Override
    public Optional<User> findById(Long id) {
        try {
            return this.jdbcTemplate.query("select * from users where id = ?;", new Object[]{id},
                    new BeanPropertyRowMapper<>(User.class)).stream().findAny();
        } catch (EmptyResultDataAccessException e) {
            return Optional.empty();
        }
    }

    @Override
    public List<User> findAll() {
        return this.jdbcTemplate.query("select * from users;", new BeanPropertyRowMapper<>(User.class));
    }

    @Override
    public void save(User entity) {
        this.jdbcTemplate.update("insert into users(login, password) values(?, ?)",
                entity.getLogin(), entity.getPassword());
    }

//    @Override
//    public void save(User entity) {
//        String sql = "INSERT INTO users(login, password) VALUES(?, ?);";
//        this.jdbcTemplate.queryForObject(sql, Long.class, entity.getLogin(), entity.getPassword());
//    }

    @Override
    public void update(User entity) {
        this.jdbcTemplate.update("update users set login = ?, password = ? where id = ?;",
                entity.getLogin(), entity.getPassword(), entity.getId());
    }

    @Override
    public void delete(Long id) {
        this.jdbcTemplate.update("delete from users where id = ?;", id);
    }

    @Override
    public Optional<User> findByUsername(String login) {
        try {
            User tmp = this.jdbcTemplate.query("select * from users where login = ?;",
                    new Object[]{login}, new BeanPropertyRowMapper<>(User.class)).stream().findAny().orElse(null);
            return tmp != null ? Optional.of(tmp) : Optional.empty();
        } catch (EmptyResultDataAccessException e) {
            return Optional.empty();
        }
    }
}

