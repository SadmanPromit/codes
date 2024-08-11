import java.util.Scanner;
public class Task01 {
	public static int sumDigits(long n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}
	public static void main(String[] args) {
		System.out.println("Enter a number: ");
		Scanner input = new Scanner(System.in);
		long n = input.nextLong();
		input.close();
		System.out.print("Sum is: " + sumDigits(n));
	}

}
