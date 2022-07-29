package edu.school21.sockets.services;

import edu.school21.sockets.models.User;
import edu.school21.sockets.repositories.UsersRepository;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Component;

import java.util.Optional;

@Component("usersService")
public class UsersServiceImpl implements UsersService{
    private UsersRepository repository;
    private PasswordEncoder encoder = new BCryptPasswordEncoder(4);

    public UsersServiceImpl(@Qualifier("usersRepository") UsersRepository repository) {
        this.repository = repository;
    }

    @Override
    public boolean signUp(String username, String password) {
        String encoded = encoder.encode(password);
        User tmp = new User(null, username, encoded);
        Optional<User> exist = repository.findByUsername(username);
        if (!exist.isPresent()) {
            repository.save(tmp);
            return true;
        }
        return false;
    }
}
