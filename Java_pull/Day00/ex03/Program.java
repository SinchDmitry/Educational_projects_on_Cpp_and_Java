import java.util.Scanner;

public class Program {
	public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String  word;
        long    data = 0;
        int     week = 0;
        short   code = 0;
        int     tmp = 0;

        for (int num = 1; num < 19; num++){
            if (input.hasNextLine()){
                word = input.next();
            }else{
                code = errorEnd(); 
                break ;
            }
            if (word.equals("42")){
                break ;
            }else if (!word.equals("Week")){
                code = errorEnd(); 
                break ;
            }
            if (input.hasNextInt()){ 
                week = input.nextInt();
            }else{
                code = errorEnd(); 
                break ;
            }
            if (week == num){
                tmp = findMin(data, week, input, code);
                if (tmp != -1){
                    data = data + tmp;
                }else{
                    code = errorEnd();
                    break ;
                }
            }else{
                code = errorEnd();
                break ;
            }
            if (code == -1){
                break ;
            }
        }
        if (code != -1){
            printArrow(data, week);
        }
        input.close();
        System.exit(code);
    }

    private static short errorEnd(){
        System.err.println("Illegal Argument");
		return (-1);
    }

    private static short findMin(long data, int week, Scanner input, short code){
        int     tmp;
        short   minScore = 10;

        for (short i = 0; i < 5; i++){
            if (input.hasNextInt()){
                tmp = input.nextInt();
                if (tmp > 0 && tmp < 10){
                    if (minScore > tmp){
                        minScore = (short)tmp;
                    }
                }else{
                    code = -1; 
                    break ;
                }
            }
            else{
                code = -1; 
                break ;
            }
        }
        for (int i = 0; i < week - 1; i++){
            minScore *= 10;
        }
        if (code == -1){
            return (-1);
        }
        return (minScore);
    }
    private static void printArrow(long data, int week){
        for (int i = 1; i <= week; i++){
            System.out.print("Week " + i + " ");
            for (int j = 0; j < data % 10; j++){
                System.out.print("=");
            }
            System.out.println(">");
            data /= 10;
        }
    }
}
