import java.util.Scanner;
public class Task08 {
	public static void main(String[] args) {
		System.out.println("Enter the initail deposit amount: ");
		Scanner input = new Scanner(System.in);
		int deposit = input.nextInt();
		double amount = (double)deposit;
		System.out.println("Enter annual percentage yield: ");
		double yield = input.nextDouble();
		System.out.println("Enter maturity period (number of months); ");
		int month = input.nextInt();
		input.close();
		System.out.println("Month CD Value");
		
		for (int i = 1; i <= month; i++) {
			amount += amount * yield / 1200;
			System.out.printf(i + " %.2f\n", amount);
		}
	}

}
