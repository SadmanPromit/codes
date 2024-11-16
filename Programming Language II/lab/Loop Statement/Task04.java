import java.util.Scanner;
public class Task04 {
	public static void main(String[] args) {
		System.out.println("Enter an integer: ");
		Scanner input = new Scanner(System.in);
		int number = input.nextInt();
		input.close();
		int index = 2;
		while (index < number) {
			if (number % index == 0) {
				System.out.print(index + ", ");
				number /= index;
			}
			else
				index++;
		}
		System.out.print(number + ".");
	}

}
