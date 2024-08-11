import java.util.Scanner;
public class Task05 {
	public static void main(String[] args) {
		System.out.println("Enter the number of lines: ");
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		input.close();
		for (int row = 1; row <= n; row++) {
			for (int i = n - row; i >= 1; i--)
				System.out.print("  ");
			for (int i = row; i >= 2; i--)
				System.out.print(i + " ");
			for (int i = 1; i <= row; i++)
				System.out.print(i + " ");
			System.out.println();
		}
	}

}
