import java.util.Scanner;
public class Task03 {
	public static void main(String[] args) {
		System.out.println("Enter ten numbers: ");
		Scanner input = new Scanner(System.in);
		int[] number = new int[10];
		int index = 0;
		for (int i = 0; i < number.length; i++) {
			int num = input.nextInt();
			if (isNew(number, num))
			number[index++] = num;
		}
		input.close();
		System.out.println("The number of distinct number is " + index);
		System.out.print("The distinct numbers are: ");
		for (int i = 0; i < index; i++)
			System.out.print(number[i] + " ");
	}
	
	public static boolean isNew(int[] number, int num) {
		for (int value: number) {
			if (num == value)
				return false;
		}
		return true;
	}

}
