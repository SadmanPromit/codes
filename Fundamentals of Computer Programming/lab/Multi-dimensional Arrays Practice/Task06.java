import java.util.Scanner;
public class Task06 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter n: ");
		long n = input.nextLong();
		input.close();
		System.out.println(sqrt(n));
	}
	
	public static double sqrt(long n) {
		double lastGuess;
		double nextGuess = 1;
		do {
			lastGuess = nextGuess;
			nextGuess = (lastGuess + n / lastGuess) / 2;
		} while (Math.abs(lastGuess - nextGuess) > 0.0001);
		return nextGuess;
	}

}
