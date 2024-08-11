import java.util.Scanner;
public class Task06 {
	public static void main(String[] args) {
		System.out.println("Enter n: ");
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		input.close();
		printMatrix(n);
	}
	
	public static void printMatrix(int n) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				System.out.print((int)(Math.random() * 10) + " ");
			}
			System.out.println();
		}
	}

}
