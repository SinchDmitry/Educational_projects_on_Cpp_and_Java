package edu.school21.chat.repositories;

import edu.school21.chat.models.User;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class UsersRepositoryJdbcImpl implements UsersRepository {
    private DataSource dataSource;

    public UsersRepositoryJdbcImpl(DataSource dataSource) {
        this.dataSource = dataSource;
    }

    @Override
    public List<User> findAll(int page, int size) {
        int offset = page * size;
        int limit = size;
        if (offset != 0) {
            offset -= 1;
        } else {
            limit -= 1;
        }
        if (size <= 0 || page < 0) {
            return null;
        }
        List<User> arr = new ArrayList<>();
        String reqSQL = "select * from chat.user limit " + limit + " offset " + offset + ";";
        try {
            Connection con = dataSource.getConnection();
            con.setSchema("chat");
            PreparedStatement request = con.prepareStatement(reqSQL);
            ResultSet res = request.executeQuery();
            while (res.next()) {
                arr.add(new User(res.getLong("id"), res.getString("login"),
                        res.getString("password"), new ArrayList<>(), new ArrayList<>()));
            }
        } catch (SQLException e) {
            System.err.printf("%s\n", e.getMessage());
        }
        return arr;
    }
}
