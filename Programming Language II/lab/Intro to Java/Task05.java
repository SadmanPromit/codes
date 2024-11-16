import java.util.Scanner;
public class Task05 {
	public static void main(String[] args) {
		System.out.println("Enter a degree in Celsius: ");
		Scanner input = new Scanner(System.in);
		double celsius = input.nextDouble();
		input.close();
		double fahrenheit = (9.00 / 5) * celsius + 32;
		System.out.println(celsius + " Celsius is " + fahrenheit + " Fahrenheit");
	}

}
