public class test {
    public static void main(String[] args) {
        int[][] dataOfLesson = new int[30][1];
        print(dataOfLesson);
        add(dataOfLesson, 2, 666);
        print(dataOfLesson);
        System.out.println(dataOfLesson.length);
    }

    private static void add(int[][] dataOfLesson, int day, int val) {
        for (; day < 30; day += 7) {
            dataOfLesson[day][0] = val;
        }
    }

    public static void print(int[][] dataOfLesson) {
        for (int i = 0; i < 30; i++) {
            System.out.print(dataOfLesson[i][0] + " ");
        }
        System.out.println(" ");
    }
}
