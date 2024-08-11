import java.util.Scanner;
public class Task03 {
	public static void main(String[] args) {
		System.out.println("Enter an integer: ");
		Scanner input = new Scanner(System.in);
		int number = input.nextInt();
		input.close();
		System.out.println(number + (isPalindrome(number) ? " is " : " is not ") + "a palindrome.");
	}
	
	public static int reverse(int number) {
		int reversedNumber = 0;
		while (number > 0) {
			reversedNumber = reversedNumber * 10 + number % 10;
			number /= 10;
			
		}
		return reversedNumber;
	}
	public static boolean isPalindrome(int number) {
		return number == reverse(number) ? true : false;
	}

}
