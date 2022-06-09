import java.util.Scanner;

public class Program {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int		number = 0;
		int		counter = 0;

		if (input.hasNextInt()){
			number = input.nextInt();
		}else{
			System.err.println("Illegal Argument");
			System.exit(-1);
		}
		while (number != 42){
			if (num_value(sum(number))){
				counter++;
			}
			number = input.nextInt();
		}
		System.out.println("Count of coffee-request - " + counter);
		input.close();
	}

	private static int sum(int value){
		int	result = 0;
	
		while (value != 0){
			result += value % 10;
			value /= 10;
		}
		return (result);
	}

	private static boolean num_value(int number){
		int		i = 1;
	
		if (number <= 1){
			return (false);
		}else if (number == 2){
			return (true);
		}else{
			while (i * i < number){
				i++;
				if (number % i == 0){
					return (false);
				}
			}
		}
		return (true);
	}
}
