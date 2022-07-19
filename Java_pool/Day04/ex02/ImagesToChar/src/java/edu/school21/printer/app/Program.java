package edu.school21.printer.app;

import edu.school21.printer.logic.ConvertFileCommander;
import com.beust.jcommander.JCommander;
import java.io.IOException;

public class Program {
        public static void main(String[] args) {
        String path = "/resources/image.bmp";
        ConvertFileCommander image = new ConvertFileCommander();
        try {
            JCommander.newBuilder()
                    .addObject(image)
                    .build()
                    .parse(args);
        } catch (Exception e) {
            System.out.println("Неверные арги!!!");
            return;
        }
        try {
            image.getImage(path);
        } catch (IOException e) {
            System.err.printf("Error : failed to read '%s': %s\n", args[0], e.getMessage());
        } catch (ConvertFileCommander.ConvertException e) {
            System.err.printf("Error : failed to convert '%s': %s\n", args[0], e.getMessage());
        }
    }
}
