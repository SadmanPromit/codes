import java.util.Scanner;
public class Task01 {
	public static void main(String[] args) {
		System.out.println("Enter ten integers: ");
		Scanner input = new Scanner(System.in);
		int[] num = new int[10];
		for (int i = 0; i < num.length; i++) {
			num[i] = input.nextInt();
		}
		input.close();
		
		for (int i = 10 - 1; i >= 0; i--) {
			System.out.println(num[i]);
		}
	}

}
