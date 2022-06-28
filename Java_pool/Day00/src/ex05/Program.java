package ex05;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] names = new String[10];
        int[][] dataOfLesson = new int[30][10];
        int namesLength = addStudents(input, names);
        int classesLength = addClasses(dataOfLesson, input);
        int[][] printableSchedule = addAttend(names, dataOfLesson, input,
                namesLength, classesLength);
        printResult(names, dataOfLesson, printableSchedule);
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
            }
        }
        return (i);
    }

    private static int addTime(int[][] dataOfLesson, int day, int time) {
        int numOfLessons = 0;
        for (; day < 30; day += 7) {
            int j = 0;
            for (; j < 10; ++j) {
                if (dataOfLesson[day][j] == 0) {
                    break;
                } else if (dataOfLesson[day][j] == time) {
                    errorEnd();
                }
            }
            if (j < 10) {
                dataOfLesson[day][j] = time;
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

    private static int calculateColumnNum(int[][] dataOfLesson, int timeNum, int dayNum) {
        int correctCheck = -1;
        int column = 0;
        for (int i = 0; i < 10; i++) {
            if (dataOfLesson[dayNum][i] == timeNum) {
                correctCheck = 0;
                break;
            }
        }
        if (correctCheck == -1) {
            errorEnd();
        } else {
            for (int i = 0; i < 30; i++) {
                int j = 0;
                for (; j < 10; j++) {
                    if (dataOfLesson[i][j] == 0) {
                        break;
                    }
                }
                column += j;
            }
        }
        return (column);
    }

    private static int[][] addAttend(String[] names, int[][] dataOfLesson, Scanner input,
                                     int height, int width) {
        int[][] attendArray = new int[height][width];
        String  tmpName;
        int     attendMarker = 0;
        int     timeNum = 0;
        int     dayNum = 0;
        int     stringSchedule = -1;
        for (;;) {
           if (input.hasNextLine() && !input.hasNextInt()) {
               tmpName = input.next();
               if (tmpName.equals(".")) {
                   break;
               } else {
                   for (int i = 0; i < height; i++) {
                       if (names[i].equals(tmpName)) {
                           stringSchedule = i;
                       }
                   }
                   if (stringSchedule == -1) {
                       errorEnd();
                   } else {
                       if (input.hasNextInt()) {
                           timeNum = input.nextInt();
                           if (timeNum < 1 || timeNum > 6) {
                               errorEnd();
                           } else if (input.hasNextInt()) {
                               dayNum = input.nextInt();
                               if (dayNum < 1 || dayNum > 30) {
                                   errorEnd();
                               } else {
                                   if (input.hasNextLine() && !input.hasNextInt()) {
                                       tmpName = input.next();
                                       if (tmpName.equals("HERE")) {
                                           attendMarker = 1;
                                       } else if (tmpName.equals("NOT_HERE")) {
                                           attendMarker = -1;
                                       } else {
                                           errorEnd();
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
               attendArray[stringSchedule][calculateColumnNum(dataOfLesson, timeNum, dayNum)] =
                       attendMarker;
           }
        }
        return  (attendArray);
    }

    private static void printResult(String[] names, int[][] dataOfLesson, int[][] printableSchedule) {

    }
}