import java.util.Scanner;
public class Task09 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of values: ");
		int index = input.nextInt();
		System.out.println("Enter the values: ");
		int[] values = new int[index];
		for (int i = 0; i < values.length; i++)
			values[i] = input.nextInt();
		input.close();
		System.out.println("The list has" + (isConsecutiveFour(values) ? " " : " no ") + "consecutive fours");
	}
	
	public static boolean isConsecutiveFour(int[] values) {
		for (int i = 0; i < values.length; i++) {
			int count = 0;
			for ( int j = 0; j < values.length && j != i; j++)
				if (values[j] == values[i]) {
					count++;
					if (count == 4)
						return true;
				}
		}
		return false;
	}

}
