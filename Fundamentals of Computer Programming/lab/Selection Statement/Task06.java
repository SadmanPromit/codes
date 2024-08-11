import java.util.Scanner;
public class Task06 {
	public static void main(String[] args) {
		System.out.println("Enter the three edes of a triangle: ");
		Scanner input = new Scanner(System.in);
		double a = input.nextDouble();
		double b = input.nextDouble();
		double c = input.nextDouble();
		input.close();
		if ((a + b > c) && (b + c > a) && (c + a > b))
			System.out.println("Perimeter: " + (a + b + c));
		else
			System.out.println("The input is invalid.");
	}

}
