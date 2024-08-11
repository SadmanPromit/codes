import java.util.Scanner;
public class Task07 {
	public static void main(String[] args) {
		System.out.println("Enter the amout of water in kilograms: ");
		Scanner input = new Scanner(System.in);
		double m = input.nextDouble();
		System.out.println("Enter the initial temperatute: ");
		double initialTemperature = input.nextDouble();
		System.out.println("Enter the final temperature: ");
		double finalTemperature = input.nextDouble();
		input.close();
		double q = m * (finalTemperature - initialTemperature) * 4184;
		System.out.println("The energy needed is " + q);
	}

}
