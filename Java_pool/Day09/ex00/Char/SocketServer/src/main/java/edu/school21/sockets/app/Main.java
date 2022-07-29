package edu.school21.sockets.app;

import edu.school21.sockets.config.SocketsApplicationConfig;
import edu.school21.sockets.server.Server;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Main {
    public static void main(String[] args) {
        int port = 0;
        if (args.length == 1) {
            String prefix = "--server-port=";
            if (args[0].startsWith(prefix)) {
                try {
                    port = Integer.parseInt(args[0].substring(prefix.length()));
                } catch (NumberFormatException e) {
                    System.err.println(e.getMessage());
                    return;
                }
                if (port > 0) {
                    try {
                        ApplicationContext context =
                                new AnnotationConfigApplicationContext(SocketsApplicationConfig.class);
                        Server server = context.getBean("server", Server.class);
                        if (server.listen(port)) {
                            System.out.println("Server starts successfully");
                            server.run();
                        }
                        System.out.println("Error : failed to start server");
                    } catch (Exception e) {
                        System.err.println(e.getMessage());
                    }
                }
            }
        }
    }
}
