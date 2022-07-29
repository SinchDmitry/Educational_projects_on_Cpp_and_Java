package edu.school21.sockets.app;

import edu.school21.sockets.server.Server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;

public class Main {
    public static final LinkedList<Server> servers = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        int port = 0;
        if (args.length == 1 && args[0].startsWith("--server-port=")
                && args[0].split("=").length == 2) {
            try {
                port = Integer.parseInt(args[0].split("=")[1]);
            } catch (NumberFormatException e) {
                System.err.println(e.getMessage());
                return;
            }
            if (port > 0) {
                System.out.println("Server started!");
                ServerSocket serverSocket = new ServerSocket(port);
                try {
                    while (true) {
                        Socket socket = serverSocket.accept();
                       try {
                           servers.add(new Server(socket));
                       } catch (IOException e) {
                           socket.close();
                       }
                    }
                } catch (IOException e) {
                    System.err.println(e.getMessage());
                    serverSocket.close();
                }
            }
        }
    }
}
