import java.util.Scanner;
public class Task01 {
	public static void main(String[] args) {
		System.out.println("Enter a, b and c: ");
		Scanner input = new Scanner(System.in);
		int a = input.nextInt();
		int b = input.nextInt();
		int c = input.nextInt();
		input.close();
		if ((b * b - 4 * a * c) > 0) {
			double r1 = (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
			double r2 = (-b - Math.sqrt(b * b - 4 * a * c)) / (2 * a);
			System.out.println("The two roots are " + r1 + " and " + r2);
		}
		else if ((b * b - 4 * a * c) == 0) {
			double r = (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
			System.out.println("The root is: " + r);
		}
		else
			System.out.println("The equation has no real roots.");
	}

}
