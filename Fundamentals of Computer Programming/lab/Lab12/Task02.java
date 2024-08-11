import java.util.*;
public class Task02 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] arr = new int[100];
		for (int i = 0; i < 100; i++) {
			arr[i] = (int)(Math.random() * 10 * Math.random());
		}
		System.out.println("Enter the index of the array: ");
		try {
			System.out.println("The corresponding element value is: " + arr[input.nextInt()]);
		}
		catch (ArrayIndexOutOfBoundsException ex) {
			System.out.println("Out of Bounds");
		}
		input.close();
	}

}
