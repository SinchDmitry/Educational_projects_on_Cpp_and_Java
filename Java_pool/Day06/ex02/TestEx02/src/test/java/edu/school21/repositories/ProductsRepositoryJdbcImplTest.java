package edu.school21.repositories;

import edu.school21.models.Product;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabase;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ProductsRepositoryJdbcImplTest {
    private EmbeddedDatabase dataSource;

    ProductsRepository productsRepository;

    final List<Product> EXPECTED_FIND_ALL_PRODUCTS = new ArrayList<>(Arrays.asList(
            new Product(0L, "table", 1),
            new Product(1L, "mouse", 10),
            new Product(2L, "keyboard", 100),
            new Product(3L, "mac", 1000),
            new Product(4L, "TV", 10000))
    );
    final Product EXPECTED_FIND_BY_ID_PRODUCT = new Product(1L, "mouse", 10);
    final Product EXPECTED_UPDATED_PRODUCT = new Product(3L, "newMac", 2000);
    final Product EXPECTED_SAVE_PRODUCT =  new Product(5L, "faceID", 100000);
    final List<Product> EXPECTED_AFTER_DELETE_PRODUCTS = new ArrayList<>(Arrays.asList(
            new Product(0L, "table", 1),
            new Product(1L, "mouse", 10),
            new Product(3L, "mac", 1000),
            new Product(4L, "TV", 10000))
    );

    @BeforeEach
    void init()  {
        dataSource = new EmbeddedDatabaseBuilder()
                .setType(EmbeddedDatabaseType.HSQL)
                .addScript("schema.sql")
                .addScript("data.sql")
                .build();
        productsRepository = new ProductsRepositoryJdbcImpl(dataSource);
    }

    @Test
    void    testFindALL() {
        Assertions.assertEquals(EXPECTED_FIND_ALL_PRODUCTS, productsRepository.findAll());
    }

    @Test
    void    testFindByID() {
        Assertions.assertEquals(EXPECTED_FIND_BY_ID_PRODUCT, productsRepository.findById(1L).orElse(null));
    }

    @Test
    void    testWrongFindByID() {
        Assertions.assertNull(productsRepository.findById(10L).orElse(null));
    }

    @Test
    void    testSave() {
        productsRepository.save(new Product(5L, "faceID", 100000));
        Assertions.assertEquals(EXPECTED_SAVE_PRODUCT, productsRepository.findById(5L).orElse(null));
    }

    @Test
    void    testUpdate() {
        productsRepository.update(new Product(3L, "newMac", 2000));
        Assertions.assertEquals(EXPECTED_UPDATED_PRODUCT, productsRepository.findById(3L).orElse(null));
    }

    @Test
    void    testDelete() {
        productsRepository.delete(2L);
        Assertions.assertEquals(EXPECTED_AFTER_DELETE_PRODUCTS, productsRepository.findAll());
    }

    @Test
    void    testWrongDelete() {
        productsRepository.delete(10L);
        Assertions.assertEquals(EXPECTED_FIND_ALL_PRODUCTS, productsRepository.findAll());
    }
}
