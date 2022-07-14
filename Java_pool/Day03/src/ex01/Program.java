package ex01;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

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
                System.out.println("Error : miss wright prefix to count");
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        int count = parseInitData(args);
        BlockingQueue<String> queue = new LinkedBlockingQueue<>();

        Runnable eggTread = () -> {
            for (int i = 0; i < count; ++i) {
                try {
                    queue.put(Thread.currentThread().getName() + " - Egg");
                    Thread.sleep(25);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        Runnable henTread = () -> {
            for (int i = 0; i < count; ++i) {
                try {
                    queue.put(Thread.currentThread().getName() + " - Hen");
                    Thread.sleep(25);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };


        try {
            Thread egg = new Thread(eggTread);
            Thread hen = new Thread(henTread);
            egg.start();


            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            hen.start();

            egg.join();
            hen.join();
            System.out.println(queue.size());
            for (int i = 0; i < count * 2; ++i) {
                System.out.println(queue.take());
            }

        } catch (NumberFormatException e) {
            System.err.printf("Error : %s is not a number\n", args[0]);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.exit(0);
    }
}
