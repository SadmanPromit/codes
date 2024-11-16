import java.util.Scanner;
public class Task07 {
	public static void main(String[] args) {
		System.out.println("Enter list: ");
		Scanner input = new Scanner(System.in);
		int[] number = new int[input.nextInt()];
		for (int i = 0; i < number.length; i++)
			number[i] = input.nextInt();
		input.close();
		System.out.println("The list is " + (isSorted(number) ? "already sorted" : "not sorted"));
	}
	
	public static boolean isSorted(int[] list) {
		for (int i = 0; i < list.length - 1; i++) {
			if (list[i] > list[i + 1])
				return false;
		}
		return true;
	}

}
