import java.util.Scanner;
public class Task08 {
	public static void main(String[] args) {
		System.out.println("Enter speed and acceleration: ");
		Scanner input = new Scanner(System.in);
		int v = input.nextInt();
		double a = input.nextDouble();
		input.close();
		double length = (v * v) / (2 * a);
		System.out.println("The minimum runway length for this airplane is " + length);
	}

}
