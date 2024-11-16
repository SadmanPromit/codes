import java.util.Scanner;
public class Task04 {
	public static void main(String[] args) {
		System.out.println("Enter three numbers: ");
		Scanner input = new Scanner(System.in);
		double num1 = input.nextDouble();
		double num2 = input.nextDouble();
		double num3 = input.nextDouble();
		input.close();
		displaySortedNumbers(num1, num2, num3);
	}
	public static void displaySortedNumbers(double num1, double num2, double num3) {
		double temp;
		if (num2 < num1 && num2 < num3) {
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
		else if (num3 < num2 && num3 < num1) {
			temp = num1;
			num1 = num3;
			num3 = temp;
		}
		if (num3 < num2) {
			temp = num2;
			num2 = num3;
			num3 = temp;
		}
		System.out.println(num1 + " " + num2 + " " + num3);
	}

}
