import java.util.Scanner;
public class Task02 {
	public static void main(String[] args) {
		System.out.println("Enter an integer: ");
		Scanner input = new Scanner(System.in);
		long number = input.nextLong();
		input.close();
		System.out.println("The sum of all digits: " + sumDigits(number));
	}
	public static int sumDigits(long n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}

}
