package school21.spring.service.repositories;

import javax.sql.DataSource;

import school21.spring.service.models.User;
import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.namedparam.BeanPropertySqlParameterSource;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;
import org.springframework.jdbc.core.namedparam.SqlParameterSource;

import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.Optional;

public class UsersRepositoryJdbcTemplateImpl implements UsersRepository {
    private NamedParameterJdbcTemplate jdbcTemplate;

    public UsersRepositoryJdbcTemplateImpl(DataSource dataSource) {
        this.jdbcTemplate = new NamedParameterJdbcTemplate(dataSource);
    }


    @Override
    public User findById(Long id) {
        String sql = "SELECT * FROM users WHERE id = :id;";

        Map namedParameters = Collections.singletonMap("id", id);

        try {
            return this.jdbcTemplate.queryForObject(sql, namedParameters, new BeanPropertyRowMapper<>(User.class));
        } catch (EmptyResultDataAccessException e) {
            return null;
        }
    }

    @Override
    public List<User> findAll() {
        String sql = "SELECT * FROM users;";

        return this.jdbcTemplate.query(sql, new BeanPropertyRowMapper<>(User.class));
    }

    @Override
    public void save(User entity) {
        String sql = "INSERT INTO users VALUES(:id, :email);";

        SqlParameterSource namedParameters = new BeanPropertySqlParameterSource(entity);

        this.jdbcTemplate.update(sql, namedParameters);
    }

    @Override
    public void update(User entity) {
        String sql = "UPDATE users SET email = :email WHERE id = :id;";

        SqlParameterSource namedParameters = new BeanPropertySqlParameterSource(entity);

        this.jdbcTemplate.update(sql, namedParameters);
    }

    @Override
    public void delete(Long id) {
        String sql = "DELETE FROM users WHERE id = :id;";

        Map namedParameters = Collections.singletonMap("id", id);

        this.jdbcTemplate.update(sql, namedParameters);
    }

    @Override
    public Optional<User> findByEmail(String email) {
        String sql = "SELECT * FROM users WHERE email = :email;";

        Map namedParameters = Collections.singletonMap("email", email);

        try {
            return Optional.ofNullable(this.jdbcTemplate.queryForObject(sql, namedParameters, new BeanPropertyRowMapper<>(User.class)));
        } catch (EmptyResultDataAccessException e) {
            return Optional.empty();
        }
    }
}
