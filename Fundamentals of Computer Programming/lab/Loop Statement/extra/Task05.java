import java.util.Scanner;
public class Task05 {
	public static void main(String[] args) {
		System.out.println("Enter numbers: ");
		Scanner input = new Scanner(System.in);
		int number;
		int max = 0;
		int count = 0;
		do {
			number = input.nextInt();
			if (number > max) {
				max = number;
				count = 1;
			}
			else if (number == max)
				count++;
		} while (number != 0);
		input.close();
		
		System.out.println("The largest number is " + max);
		System.out.println("The occurrence count of the largest number is " + count);
	}

}
