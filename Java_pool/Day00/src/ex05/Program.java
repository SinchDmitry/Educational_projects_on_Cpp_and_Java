package ex05;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] names = new String[10];
        int[][] dataOfLesson = new int[30][10];
        int namesLength = addStudents(input, names);
        int classesLength = addClasses(dataOfLesson, input);
//        for (int i = 0; i < 30; i++) {
//            for (int j = 0; j < 10; j++) {
//                System.out.printf("%10d" + "|", dataOfLesson[i][j]);
//            }
//            System.out.println("");
//        }
        int[][] printableSchedule = addAttend(names, dataOfLesson, input,
                namesLength, classesLength);
        printResult(names, dataOfLesson, printableSchedule, classesLength, namesLength);
    }

    private static void errorEnd() {
        System.err.println("Illegal Argument");
        System.exit(-1);
    }

    private static int addStudents(Scanner input, String[] names) {
        String tmp;
        int i = 0;
        for (; i < 10; i++) {
            if (input.hasNextLine() && !input.hasNextInt()) {
                tmp = input.next();
                if (tmp.length() > 10 || tmp.contains(" ")) {
                    errorEnd();
                } else if (tmp.equals(".")) {
                    break ;
                }
                names[i] = tmp;
            } else {
                errorEnd();
            }
        }
        return (i);
    }

    private static int addTime(int[][] dataOfLesson, int day, int time) {
        int numOfLessons = 0;
        for (; day < 30; day += 7) {
            int j = 0;
            for (; j < 10; ++j) {
                if (dataOfLesson[day - 1][j] == 0) {
                    break;
                } else if (dataOfLesson[day - 1][j] == time) {
                    errorEnd();
                }
            }
            if (j < 10) {
                dataOfLesson[day - 1][j] = time;
                numOfLessons++;
            } else {
                errorEnd();
            }
        }
        return (numOfLessons);
    }

    private static int addClasses(int[][] dataOfLesson, Scanner input) {
        String  tmpDay;
        int     tmpNum;
        int     numOfClasses = 0;
        for (int i = 0; i < 10; i++) {
            if (input.hasNextInt()) {
                tmpNum = input.nextInt();
                if (tmpNum < 1 || tmpNum > 6) {
                    errorEnd();
                }
                if (input.hasNextLine()) {
                    tmpDay = input.next();
                    switch (tmpDay) {
                        case ("MO"):
                            numOfClasses += addTime(dataOfLesson, 7, tmpNum);
                            break;
                        case ("TU"):
                            numOfClasses += addTime(dataOfLesson, 1, tmpNum);
                            break;
                        case ("WE"):
                            numOfClasses += addTime(dataOfLesson, 2, tmpNum);
                            break;
                        case ("TH"):
                            numOfClasses += addTime(dataOfLesson, 3, tmpNum);
                            break;
                        case ("FR"):
                            numOfClasses += addTime(dataOfLesson, 4, tmpNum);
                            break;
                        case ("SA"):
                            numOfClasses += addTime(dataOfLesson, 5, tmpNum);
                            break;
                        case ("SU"):
                            numOfClasses += addTime(dataOfLesson, 6, tmpNum);
                            break;
                        default:
                            errorEnd();
                    }
                } else if (input.hasNextLine() && input.next().equals(".")) {
                    break;
                } else {
                    errorEnd();
                }
            }
        }
        return (numOfClasses);
    }

    private static int[] calculateColumnNum(int[][] dataOfLesson, int timeNum, int dayNum) {
        int correctCheck = -1;
        int[] column = new int[2];
        int i = 0;
        for (; i < 10; i++) {
            if (dataOfLesson[dayNum - 1][i] == timeNum) {
                correctCheck = 0;
                break;
            }
        }
        if (correctCheck == -1) {
            errorEnd();
        } else {
            for (int k = 0; k < 30; k++) {
                int j = 0;
                for (; j < 10; j++) {
                    if (dataOfLesson[k][j] == 0) {
                        break;
                    }
                    if (k == dayNum - 1 && j == i) {
                        column[0] = column[1] + j;
                    }
                }
                column[1] += j;
            }
        }
        return (column);
    }

    private static int  checkMarker(Scanner input) {
        String  tmpName;
        if (input.hasNextLine() && !input.hasNextInt()) {
            tmpName = input.next();
            if (tmpName.equals("HERE")) {
                return (1);
            } else if (tmpName.equals("NOT_HERE")) {
                return (-1);
            } else {
                errorEnd();
            }
        } else {
            errorEnd();
        }
        return (0);
    }

    private static int  checkStudent(String[] names, Scanner input, String  tmpName, int height) {
        int     stringSchedule = -1;
        for (int i = 0; i < height; i++) {
            if (names[i].equals(tmpName)) {
                stringSchedule = i;
            }
        }
        if (stringSchedule == -1) {
            errorEnd();
        }
        return (stringSchedule);
    }

    private static int[][] addAttend(String[] names, int[][] dataOfLesson, Scanner input,
                                     int height, int width) {
        int[][] attendArray = new int[height][width];
        String  tmpName = input.next();
        int     attendMarker = 0;
        int     timeNum = 0;
        int     dayNum = 0;
        int     stringSchedule;
        for (;;) {
           if (input.hasNextLine() && !input.hasNextInt()) {
               tmpName = input.next();
               if (tmpName.equals(".")) {
                   break;
               } else {
                   stringSchedule = checkStudent(names, input, tmpName, height);
                   if (input.hasNextInt()) {
                       timeNum = input.nextInt();
                       if (timeNum < 1 || timeNum > 6) {
                           errorEnd();
                       } else if (input.hasNextInt()) {
                           dayNum = input.nextInt();
                           if (dayNum < 1 || dayNum > 30) {
                               errorEnd();
                           } else {
                               attendMarker = checkMarker(input);
                           }
                       } else {
                           errorEnd();
                       }
                   }
               }
               int[] columnSchedule = calculateColumnNum(dataOfLesson, timeNum, dayNum);
               attendArray[stringSchedule][columnSchedule[0]] = attendMarker;
           }
        }
        return  (attendArray);
    }

    private static String dayOfWeekCalculate(int day) {
        int tmp;
        for (int i = 7; i > 0; i--) {
            tmp = (day) % 7;
            switch (tmp) {
                case (0) : return " TU ";
                case (6) : return " MO ";
                case (5) : return " SU ";
                case (4) : return " SA ";
                case (3) : return " FR ";
                case (2) : return " TH ";
                case (1) : return " WE ";
            }
        }
        return ("ER");
    }

    private static void printFirstString(int[][] dataOfLesson) {
        int i = 0;
        System.out.print("          ");
        for (int k = 0; k < 30; k++) {
            for (int j = 0; j < 10; j++) {
                if (dataOfLesson[k][j] != 0) {
                    System.out.printf(dataOfLesson[k][j] + ":00" + dayOfWeekCalculate(k) + "%2d" + "|" , k + 1);
                }
            }
        }
        System.out.println("");
    }

    private static void printResult(String[] names, int[][] dataOfLesson, int[][] printableSchedule,
                                    int width, int height) {
        printFirstString(dataOfLesson);
        for (int i = 0; i < height; i++) {
            System.out.printf("%10s", names[i]);
            for (int j = 0; j < width; j++) {
                if (printableSchedule[i][j] != 0) {
                    System.out.printf("%10d" + "|", printableSchedule[i][j]);
                } else {
                    System.out.print("          " + "|");
                }
            }
            System.out.println("");
        }
    }
}
