package edu.school21.chat.app;

import com.zaxxer.hikari.HikariDataSource;
import edu.school21.chat.models.Chatroom;
import edu.school21.chat.models.Message;
import edu.school21.chat.models.User;
import edu.school21.chat.repositories.MessagesRepositoryJdbcImpl;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Optional;
import java.util.Scanner;

public class Program {
    public static HikariDataSource hikariInit () {

//        HikariConfig con = new HikariConfig();
//        con.setJdbcUrl("jdbc:postgresql://localhost:5432/postgres");
//        con.setUsername("postgres");
//        con.setPassword("postgres");

        HikariDataSource ds = new HikariDataSource();
        ds.setJdbcUrl("jdbc:postgresql://localhost:5432/postgres");

//        ds.setUsername("postgres");
//        ds.setPassword("postgres");
//        ds.addDataSourceProperty( "cachePrepStmts" , "true" );
//        ds.addDataSourceProperty(  "prepStmtCacheSize" , "250" );
//        ds.addDataSourceProperty(  "prepStmtCacheSqlLimit" , "2048" );
        return ds;
    }

    public static void printByID(Optional<Message> IdMessage) {
        if (IdMessage.isPresent()) {
            String tmp = IdMessage.get().toString();
            tmp = tmp.substring(0, tmp.length() - 1)
                    .replace("Message{", "Message : {\n\t")
                    .replace(" author=User", "\n\tauthor=")
                    .replace(" chatroom=Chatroom", "\n\troom=")
                    .replace(" data=", "\n\tdata=")
                    .replace(" message=", "\n\ttext=") + "\n}";
            System.out.println(tmp);
        }
    }

    public static void createSavePrintUpdatePrint(Message msg, Scanner input, MessagesRepositoryJdbcImpl msgRep) {

        try {
            msgRep.save(msg);
        } catch (MessagesRepositoryJdbcImpl.NotSavedSubEntityException e) {
            System.out.println(e.getMessage());
            System.out.println();
        }
        System.out.println(msg.getId());
        System.out.println("Enter a message ID : ");
        if (input.hasNextLong()) {
            Long id = input.nextLong();
            Optional<Message> IdMessage = msgRep.findById(id);
            printByID(IdMessage);

            System.out.println("Update text in message");
            msg.setMessage(msg.getMessage() + " Mm?");

            try {
                msgRep.update(msg);
            } catch (MessagesRepositoryJdbcImpl.NotSavedSubEntityException e) {
                System.out.println(e.getMessage());
                System.out.println();
            }

            IdMessage = msgRep.findById(id);
            printByID(IdMessage);
        } else {
            System.err.println("Error : wrong type of input data");
            System.exit(-1);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        User somebody = new User(5L, "shreck", "boloto", new ArrayList<>(), new ArrayList<>());
        Chatroom boloto = new Chatroom(6L, "boloto", somebody, new ArrayList<>());
        Message msg = new Message(null, somebody, boloto, "My uje priehali?", null);
        System.out.println("Save new message");
        HikariDataSource source = hikariInit();
        MessagesRepositoryJdbcImpl msgRep = new MessagesRepositoryJdbcImpl(source);

        createSavePrintUpdatePrint(msg, input, msgRep);

        System.out.println("Update text in message");
        msg.setMessage(msg.getMessage() + " Mm?");
        System.out.println("Update data in message");
        msg.setData(LocalDateTime.now());

        try {
            msgRep.update(msg);
        } catch (MessagesRepositoryJdbcImpl.NotSavedSubEntityException e) {
            System.out.println(e.getMessage());
            System.out.println();
        }

        Optional<Message>IdMessage = msgRep.findById(msg.getId());
        printByID(IdMessage);
    }

}
