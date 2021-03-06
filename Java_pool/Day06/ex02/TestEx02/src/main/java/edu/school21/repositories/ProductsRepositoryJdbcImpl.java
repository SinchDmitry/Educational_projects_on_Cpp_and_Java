package edu.school21.repositories;

import edu.school21.models.Product;

import javax.sql.DataSource;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ProductsRepositoryJdbcImpl implements ProductsRepository {
    private final DataSource dataSource;

    public ProductsRepositoryJdbcImpl(DataSource dataSource) {
        this.dataSource = dataSource;
    }

    @Override
    public List<Product> findAll() {
        List<Product> allItems = new ArrayList<>();
        try {
            Connection conSQL = dataSource.getConnection();
            String requestText = "select * from shop";
            PreparedStatement request = conSQL.prepareStatement(requestText);
            ResultSet res = request.executeQuery();
            while (res.next()) {
                Product tmp = new Product(res.getLong(1),
                        res.getString(2), res.getInt(3));
                allItems.add(tmp);
            }
        } catch (SQLException e) {
            System.err.printf("%s\n", e.getMessage());
        }
        return allItems;
    }

    @Override
    public Optional<Product>   findById(Long id) {
        Product tmp = null;
        try {
            Connection conSQL = dataSource.getConnection();
            String requestText = "select  * from shop where id = ?;";
            PreparedStatement request = conSQL.prepareStatement(requestText);
            request.setLong(1, id);
            ResultSet res = request.executeQuery();
            if (!res.next()) {
                return Optional.empty();
            }
            tmp = new Product(res.getLong(1),
                    res.getString(2), res.getInt(3));
        } catch (SQLException e) {
            System.err.printf("%s\n", e.getMessage());
        }
        return Optional.of(tmp);
    }

    @Override
    public void save(Product product) {
        try {
            Connection conSQL = dataSource.getConnection();
            String requestText = "insert into shop (id, name, coast) " +
                    "values (?, ?, ?)";
            PreparedStatement request = conSQL.prepareStatement(requestText);
            request.setLong(1, product.getId());
            request.setString(2, product.getName());
            request.setInt(3, product.getCoast());
            request.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Save error");
        }
    }

    @Override
    public void update(Product product) {
        try {
            Connection conSQL = dataSource.getConnection();
            String requestText = "update shop set id = ?, name = ?, coast = ?" +
                    "where shop.id = ?;";
            PreparedStatement request = conSQL.prepareStatement(requestText);
            request.setLong(1, product.getId());
            request.setString(2, product.getName());
            request.setInt(3, product.getCoast());
            request.setLong(4, product.getId());
            request.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Update error");
        }
    }

    @Override
    public void delete(Long id) {
        try {
            Connection conSQL = dataSource.getConnection();
//            conSQL.setSchema("public");
            String requestText = "delete from shop where id = ?";
            PreparedStatement request = conSQL.prepareStatement(requestText);
            request.setLong(1, id);
            request.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Update error");
        }
    }
}
