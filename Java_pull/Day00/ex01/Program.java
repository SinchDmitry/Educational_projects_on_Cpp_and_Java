import java.util.Scanner;

public class Program {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		boolean	result = true;
		int		i = 1;
		int		code = 0;
		int		number = 0;

		if (input.hasNextInt()){
			number = input.nextInt();
		}else{
			System.err.println("Illegal Argument");
			code = -1;
		}
		if (code != -1){
			if (number <= 1){
				System.err.println("Illegal Argument");
				code = -1;
			}else if (number == 2){
				System.out.println(result + " " + 1);
			}else{
				while (i * i < number){
					i++;
					if (number % i == 0){
						result = false;
						break ;
					}
				}
				i -= 1;
				System.out.println(result + " " + i);
			}
		}
		input.close();
		System.exit(code);
	}
}
