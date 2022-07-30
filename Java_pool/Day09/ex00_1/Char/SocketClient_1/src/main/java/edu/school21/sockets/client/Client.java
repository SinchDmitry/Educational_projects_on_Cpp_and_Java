package edu.school21.sockets.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    private Socket socket = new Socket();

    public boolean connect(int port) {
        try {
            socket.connect(new InetSocketAddress(port));
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public void run() {
        Scanner s = new Scanner(System.in);
        try (
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
             ) {
            String input, output;
            while ((input = in.readLine()) != null) {
                System.out.println(input);
                if (input.equals("Successful!")) {
                    while (true) {
                        if ((input = in.readLine()) == "exit") {
                            break;
                        }
                    }
                    close();
                    break;
                } else if (input.startsWith("ERROR")) {
                    break;
                }
                output = s.nextLine();
                out.println(output);
            }
        } catch (IOException e) {
            System.out.printf("ERROR: %s\n", e.getMessage());
        }
    }

    public void close() {
        try {
            socket.close();
        } catch (IOException e) {}
    }
}
