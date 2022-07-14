package ex02;

public class Program {
    private static int readArgument(String arg, String prefix) {
        System.out.println(arg);
        if (arg.startsWith(prefix)) {
            try {
                System.out.println(arg);
                int count = Integer.parseInt(arg.substring(prefix.length()));
                return count;
            } catch (NumberFormatException e) {
                System.err.printf("%s is not a number\n", arg);
            }
        } else {
            System.out.println("Error : miss wright prefix to count");
        }
        return -1;
    }

    private static ArraySum parseInitData(String[] args) {
        String  prefix1 = "--arraySize=";
        String  prefix2 = "--threadsCount=";
        if (args.length != 2) {
            System.out.println("Error : wrong number of arguments");
        } else {
            int     arraySize = readArgument(args[0], prefix1);
            int     threadCounter = readArgument(args[1], prefix2);
            if (arraySize > 0) {
                if (threadCounter > 0) {
                    return new ArraySum(arraySize, threadCounter);
                }
            } else {
                System.out.println("Error : miss right prefix to count");
            }
        }
        return null;
    }

    public static void main(String[] args) {
        ArraySum array = parseInitData(args);

        System.exit(0);
    }
}
