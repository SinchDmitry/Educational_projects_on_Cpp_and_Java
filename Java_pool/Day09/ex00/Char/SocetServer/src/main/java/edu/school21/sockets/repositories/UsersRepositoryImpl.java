package edu.school21.sockets.repositories;

import edu.school21.sockets.models.User;
import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import javax.sql.DataSource;
import java.util.List;
import java.util.Optional;

public class UsersRepositoryImpl implements UsersRepository {
        private final JdbcTemplate jdbcTemplate;

        public UsersRepositoryImpl(DataSource dataSource) {
            this.jdbcTemplate = new JdbcTemplate(dataSource);
        }

        @Override
        public User findById(Long id) {
            try {
                return this.jdbcTemplate.query("select * from users where id = ?;", new Object[]{id},
                        new BeanPropertyRowMapper<>(User.class)).stream().findAny().orElse(null);
            } catch (EmptyResultDataAccessException e) {
                return null;
            }
        }

        @Override
        public List<User> findAll() {
            return this.jdbcTemplate.query("select * from users;", new BeanPropertyRowMapper<>(User.class));
        }

        @Override
        public void save(User entity) {
            this.jdbcTemplate.update("insert into users values(?, ?);", entity.getId(), entity.getEmail());
        }

        @Override
        public void update(User entity) {
            this.jdbcTemplate.update("update users set email = ? where id = ?;", entity.getEmail(), entity.getId());
        }

        @Override
        public void delete(Long id) {
            this.jdbcTemplate.update("delete from users where id = ?;", id);
        }

        @Override
        public Optional<User> findByEmail(String email) {
            try {
                User tmp = this.jdbcTemplate.query("select * from users where email = ?;",
                        new Object[]{email}, new BeanPropertyRowMapper<>(User.class)).stream().findAny().orElse(null);
                return tmp == null ? Optional.of(tmp) : Optional.empty();
            } catch (EmptyResultDataAccessException e) {
                return Optional.empty();
            }
        }
    @Override
    public Optional<User> findByUsername(String email) {
        return Optional.empty();
    }
}
