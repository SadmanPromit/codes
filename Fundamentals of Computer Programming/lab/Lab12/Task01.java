import java.util.InputMismatchException;
import java.util.Scanner;
public class Task01 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int num1 = 0, num2 = 0;
		boolean continueInput = true;
		do {
			try {
				System.out.println("Enter two integers: ");
				num1 = input.nextInt();
				num2 = input.nextInt();
				input.close();
				continueInput = false;
			}
			catch (InputMismatchException ex){
				System.out.println("Try again. Incorrect input: an integer is required.");
				input.nextLine();
			}
		} while (continueInput);
		System.out.println("Sum: " + (num1 + num2));
	}

}
