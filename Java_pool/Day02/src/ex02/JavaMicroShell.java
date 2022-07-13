package ex02;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class JavaMicroShell {
    private Path _homeDirPath;

    public JavaMicroShell(){
        _homeDirPath = null;
    }

    public boolean setHomeDirPath(String path, String prefix) {
        String tmpPath = path.substring(prefix.length());
        _homeDirPath = Paths.get(tmpPath).toAbsolutePath().normalize();
        if (_homeDirPath.toFile().exists()) {
            if (_homeDirPath.toFile().isDirectory()) {
                return true;
            }
            System.err.println("Error : " + path + " folder is not a directory");
            return false;
        }
        System.err.println("Error : " + path + " folder doesn't exist");
        return false;
    }

    public Path getHomeDirPath() {
        return _homeDirPath;
    }

    public void executeCmd() {
        Scanner input = new Scanner(System.in);
        String  cmd;
        while (true)  {
            if (input.hasNextLine()) {
                cmd = input.nextLine();
                if (cmd.split("\\s+")[0].equals("exit")) {
                    break;
                }
                switch (cmd.split("\\s+")[0]) {
                    case ("ls") : makeLs(cmd); break;
                    case ("pwd") : makePwd(); break;
                    case ("cd") : makeCd(cmd); break;
                    case ("mv") : makeMv(cmd); break;
                    default: System.err.println("Error : unknown command"); break;
                }
            }
        }
        input.close();
    }

    public void makePwd () {
        System.out.println(getHomeDirPath());
    }

    public void makeCd(String cmd) {
        if (cmd.equals("cd")) {
            System.err.println("Error : cd has no folder name specified");
        } else if (cmd.split("\\s+").length > 2) {
            System.err.println("Error : cd has too many arguments");
        } else {
            setHomeDirPath(cmd.split("\\s+")[1], "");
        }
    }

    public void makeMv(String cmd) {
        if (cmd.split("\\s+").length != 3) {
            System.err.println("Error : mv has incorrect number of arguments");
        } else {
            Path from = Paths.get(cmd.split("\\s+")[1]).toAbsolutePath().normalize();
            if (from.toFile().exists()) {
                if (from.toFile().isDirectory()) {
                    System.err.println("Error : " + cmd.split("\\s+")[1] + " is a directory");
                } else {
                    Path to = Paths.get(cmd.split("\\s+")[2]).toAbsolutePath().normalize();
                    if (to.toFile().exists()) {
                        if (!to.toFile().isDirectory()) {
                                System.err.println("Error : " + cmd.split("\\s+")[1] + " already exist");
                        } else {
                            to = Paths.get(to + "/" + from.toFile().getName());
                        }
                    }
                    if (!from.toFile().renameTo(to.toFile())) {
                        System.err.println("Error : cannot move file");
                    }
                }
            } else {
                System.err.println("Error : " + cmd.split("\\s+")[1] + " doesn't exist");
            }
        }
    }

    public void makeLs(String cmd) {
        if (!cmd.equals("ls")) {
            System.err.println("Error : ls doesn't need any arguments");
        } else {
            try {
                File[] file = _homeDirPath.toFile().listFiles();
                if (file != null) {
                    for (File value : file) {
                        System.out.printf("%s %d %s\n", value.getName(),
                                Files.size(value.toPath()), "KB");
                    }
                }
            } catch (IOException e) {
                System.err.println(e.getMessage());
            }

        }
    }
}
