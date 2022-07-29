package edu.school21.sockets.server;

import edu.school21.sockets.services.UsersService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

@Component
public class Server {
    private final UsersService service;
    private ServerSocket socket;

    @Autowired
    public Server(UsersService service) {
        this.service = service;
    }

    public boolean listen(int port) {
            try {
                socket = new ServerSocket(port);
            } catch (IOException e) {
                return false;
            }
            return true;
    }

    public void run() {
        if (socket == null) {
            return;
        }
        while (true) {
            try (
                Socket user = socket.accept();
                InputStreamReader stream = new InputStreamReader(user.getInputStream());
                BufferedReader input = new BufferedReader(stream);
                PrintWriter output = new PrintWriter(user.getOutputStream(), true);
            ) {
                output.println("Hello from Server!");
                String tmp = input.readLine();
                String username;
                String password;
                if (tmp.equals("signUp")) {
                    output.println("Enter username:");
                    if ((username = input.readLine()) != null) {
                        output.println("Enter password:");
                        if ((password = input.readLine()) != null) {
                            if (service.signUp(username, password)) {
                                output.println("Successful!");
                            } else {
                                output.println("Error : failed to sign up");
                            }
                        }
                    }
                } else if (tmp.equals("exit")) {
                    break;
                } else {
                    System.err.println("Error : wrong command");
                }
            } catch (IOException e) {
                System.err.println("Error");
            }
        }
    }
}
