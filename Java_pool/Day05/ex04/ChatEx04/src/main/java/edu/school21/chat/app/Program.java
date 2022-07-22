package edu.school21.chat.app;

import com.zaxxer.hikari.HikariDataSource;
import edu.school21.chat.models.User;
import edu.school21.chat.repositories.UsersRepository;
import edu.school21.chat.repositories.UsersRepositoryJdbcImpl;

import java.util.List;

public class Program {
    public static HikariDataSource hikariInit () {
        HikariDataSource ds = new HikariDataSource();
        ds.setJdbcUrl("jdbc:postgresql://localhost:5432/postgres");

//        ds.setUsername("postgres");
//        ds.setPassword("postgres");
//        ds.addDataSourceProperty( "cachePrepStmts" , "true" );
//        ds.addDataSourceProperty(  "prepStmtCacheSize" , "250" );
//        ds.addDataSourceProperty(  "prepStmtCacheSqlLimit" , "2048" );
        return ds;
    }


    public static void main(String[] args) {
        HikariDataSource source = hikariInit();
        UsersRepository usersRep = new UsersRepositoryJdbcImpl(source);
        List<User> all = usersRep.findAll(2, 4);
        for (User u : all) {
            System.out.println(u);
        }
    }
}
