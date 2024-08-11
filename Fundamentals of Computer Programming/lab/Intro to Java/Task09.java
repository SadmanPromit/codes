import java.util.Scanner;
public class Task09 {
	public static void main(String[] args) {
		System.out.println("Enter weight in pounds: ");
		Scanner input = new Scanner(System.in);
		double weight = input.nextDouble() * 0.45359237;
		System.out.println("Enter height in inches: ");
		double height = input.nextDouble() * 0.0254;
		input.close();
		double bmi = weight / (height * height);
		System.out.println("BMI is " + bmi);
	}

}
