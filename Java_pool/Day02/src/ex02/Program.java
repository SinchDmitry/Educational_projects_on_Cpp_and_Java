package ex02;

import java.nio.file.Paths;

public class Program{
    private static boolean checkInput(String[] args, String prefixPath) {
        if (args.length == 1) {
            if (!args[0].startsWith(prefixPath)) {
                System.out.println("Error : wrong directory name");
                return false;
            } else {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        String prefixPath = "--current-folder=";
        if (checkInput(args, prefixPath)) {
            JavaMicroShell manager = new JavaMicroShell();
            if (manager.setHomeDirPath(args[0], prefixPath)) {
                manager.executeCmd();
            }
        }
        System.exit(0);
    }
}
