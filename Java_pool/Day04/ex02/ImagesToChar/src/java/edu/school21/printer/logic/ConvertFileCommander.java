package edu.school21.printer.logic;

import com.beust.jcommander.Parameter;
import com.diogonunes.jcdp.color.ColoredPrinter;
import com.diogonunes.jcdp.color.api.Ansi;
import com.beust.jcommander.Parameters;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;

@Parameters(separators = "=")
public class ConvertFileCommander {
    @Parameter(names = {"--white", "-b"}, arity = 1)
    private static String whitePixel;
    @Parameter(names = {"--black", "-w"}, arity = 1)
    private static String blackPixel;

    public ConvertFileCommander() {

    }

    public static class ConvertException extends RuntimeException {
        public  ConvertException(String msg) {
            super(msg);
        }
    }

    public static void getImage(String filename)
            throws IOException, ConvertException {
        try {
            Ansi.BColor.valueOf(whitePixel);
            Ansi.BColor.valueOf(blackPixel);
        }catch (Exception e) {
            System.out.println("Error : incorrect color");
            return;
        }
        ColoredPrinter cp = new ColoredPrinter.Builder(1, false)
                .foreground(Ansi.FColor.NONE).background(Ansi.BColor.NONE)   //setting format
                .build();
        if (ConvertFileCommander.class.getResource(filename) != null) {
            BufferedImage img = ImageIO.read(ConvertFileCommander.class.getResource(filename));
            char[][] tmp = new char[img.getWidth()][img.getHeight()];
            for (int i = 0; i < img.getWidth(); ++i) {
                for (int j = 0; j < img.getHeight(); ++j) {
                    if (img.getRGB(j, i) == Color.BLACK.getRGB()) {
                        cp.print(" ", Ansi.Attribute.NONE, Ansi.FColor.NONE, Ansi.BColor.valueOf(whitePixel));
                    } else if (img.getRGB(j, i) == Color.WHITE.getRGB()) {
                        cp.print(" ", Ansi.Attribute.NONE, Ansi.FColor.NONE, Ansi.BColor.valueOf(blackPixel));
                    } else {
                        throw new ConvertException("incorrect image");
                    }
                }
                System.out.println();
            }
        } else {
            System.err.println("Error : bad path to file");
        }
    }
}
