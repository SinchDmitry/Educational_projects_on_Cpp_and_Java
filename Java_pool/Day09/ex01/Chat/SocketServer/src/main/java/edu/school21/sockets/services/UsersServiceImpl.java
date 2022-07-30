package edu.school21.sockets.services;

import edu.school21.sockets.models.Message;
import edu.school21.sockets.models.User;
import edu.school21.sockets.repositories.MessageRepository;
import edu.school21.sockets.repositories.UsersRepository;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Component;

import java.time.LocalDateTime;
import java.util.Optional;

@Component("usersService")
public class UsersServiceImpl implements UsersService{
    private UsersRepository uRep;
    private MessageRepository mRep;
    private PasswordEncoder encoder = new BCryptPasswordEncoder(4);

    public UsersServiceImpl(@Qualifier("usersRepository") UsersRepository usersRepository,
                            @Qualifier("messageRepository") MessageRepository messageRepository) {
        this.uRep = usersRepository;
        this.mRep = messageRepository;
    }

    @Override
    public boolean signUp(String username, String password) {
        String encoded = encoder.encode(password);
        User tmp = new User(null, username, encoded);
        Optional<User> exist = uRep.findByUsername(username);
        if (!exist.isPresent()) {
            uRep.save(tmp);
            return true;
        }
        System.out.println("Error : failed to create new user " + username + ". Username already exists");
        return false;
    }
    @Override
    public boolean signIn(String username, String password) {
        Optional<User> exist = uRep.findByUsername(username);
        if (exist.isPresent()) {
            if (encoder.matches(password, exist.get().getPassword())) {
                return true;
            }
        }
        System.out.println("Error : failed to create new user " + username + ". Username already exists");
        return false;
    }

    @Override
    public void saveMessage(String user, String message) {
        Message msg = new Message(null, user, message, LocalDateTime.now());
        mRep.save(msg);
    }
}
