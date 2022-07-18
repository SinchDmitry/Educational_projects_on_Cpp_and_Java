package edu.school21.printer.logic;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class ConvertFile {
    public ConvertFile() {
    }

    public static class ConvertException extends RuntimeException {
        public  ConvertException(String msg) {
            super(msg);
        }
    }

    public static char[][] toCharArray(String filename)
            throws IOException, ConvertException {
        BufferedImage img = ImageIO.read(new File(filename));
        char[][] tmp = new char[img.getWidth()][img.getHeight()];
        for (int i = 0; i < img.getWidth(); ++i) {
            for (int j = 0; j < img.getHeight(); ++j) {
                if (img.getRGB(i, j) == Color.BLACK.getRGB()) {
                    tmp[i][j] = 'o';
                } else if (img.getRGB(i, j) == Color.WHITE.getRGB()) {
                    tmp[i][j] = '.';
                } else {
                    throw new ConvertException("incorrect image");
                }
            }
        }
        return tmp;
    }
}
