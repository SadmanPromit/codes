import java.util.Scanner;
public class Task04 {
	public static void main(String[] args) {
		System.out.print("Enter a three-digit integer: ");
		Scanner input = new Scanner(System.in);
		int num = input.nextInt();
		input.close();
		int firstDigit = num % 10;
		int lastDigit = num / 100;
		if (firstDigit == lastDigit)
			System.out.println(num + " is a palindrome");
		else
			System.out.println(num + " is not a palindrome");
	}

}
