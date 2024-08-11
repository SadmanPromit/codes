import java.util.Scanner;
public class Task02 {
	public static void main(String[] args) {
		System.out.println("Enter the integers between 1 and 100: ");
		Scanner input = new Scanner(System.in);
		int index = 0;
		int[] number = new int[100];
		do {
			number[index] = input.nextInt();
		} while (number[index++] != 0);
		input.close();
		
		for (int i = 1; i <= 100; i++) {
			int count = 0;
			for (int j = 0; j <= number.length - 1; j++) {
				if (number[j] == i)
					count++;
			}
			if (count > 0) {
				System.out.println(i + " occurs " + count + (count == 1 ? " time " : " times"));
			}
		}
	}

}
