package ex00;

public class Program {
    private static int parseInitData(String[] args) {
        String  prefix = "--count=";
        if (args.length != 1) {
            System.out.println("Error : wrong number of arguments");
        } else {
            if (args[0].startsWith(prefix)) {
                try {
                    int count = Integer.parseInt(args[0].substring(prefix.length()));
                    return count;
                } catch (NumberFormatException e) {
                    System.err.printf("%s is not a number\n", args[0]);
                }
            } else {
                System.out.println("Error : miss right prefix to count");
            }
        }
        return -1;
    }
    public static void main(String[] args) {

        int count = parseInitData(args);
        Runnable eggTread = new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < count; ++i) {
                    System.out.println("Egg");
                    try {
                        Thread.sleep(1);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        Runnable hanTread = new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < count; ++i) {
                    System.out.println("Hen");
                    try {
                        Thread.sleep(1);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        };

        try {
            Thread egg = new Thread(eggTread);
            Thread han = new Thread(hanTread);
            han.start();
            egg.start();
            egg.join();
            han.join();
            for (int i = 0; i < count; ++i) {
                System.out.println("Human");
            }
        } catch (NumberFormatException e) {
            System.err.printf("Error : %s is not a number\n", args[0]);
        } catch (InterruptedException e) {
            System.err.println("Error : thread was interrupted");
        }
        System.exit(0);
    }
}
