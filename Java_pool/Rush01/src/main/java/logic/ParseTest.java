package logic;

import com.beust.jcommander.Parameter;
import com.beust.jcommander.Parameters;

import java.io.IOException;
import java.util.Scanner;

@Parameters(separators = "=")
public class ParseTest {

    @Parameter(names = "--enemiesCount", required = true)
    private int enemiesCount;
    @Parameter(names = "--wallsCount", required = true)
    private int wallsCount;
    @Parameter(names = "--size", required = true)
    private int mapSquareSize;
    @Parameter(names = "--profile", required = true)
    private String gameMode;

    public ParseTest() {
    }

    public void argsPrinter() {
        System.out.println(enemiesCount + " | " + wallsCount + " | " + mapSquareSize + " | " + gameMode);
    }

}

