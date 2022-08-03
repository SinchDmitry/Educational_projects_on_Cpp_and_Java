//package edu.school21.sockets.app;
//
//import edu.school21.sockets.client.Client;
//
//public class Main {
//    public static void main(String[] args) {
//        if (args.length != 1 || !args[0].startsWith("--port=")) {
//            System.out.println("Usage: Main --port=PORT");
//            return;
//        }
//
//        int port = 0;
//        try {
//            port = Integer.parseInt(args[0].substring("--port=".length()));
//        } catch (NumberFormatException e) {
//            System.out.println("Usage: Main --port=PORT");
//            return;
//        }
//
//        Client client = new Client();
//        if (client.connect(port)) {
//            System.out.println("Client starts successfully");
//            client.run();
//        } else {
//            System.out.println("Error connecting to server");
//        }
//
//    }
//}



package edu.school21.sockets.app;

import edu.school21.sockets.client.Client;

import java.io.IOException;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws IOException {
        if (args.length != 0) {
            try {
                Client client = new Client("localhost", Integer.parseInt(args[0].split("=")[1]));
                client.connection();
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}