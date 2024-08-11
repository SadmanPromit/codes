import java.util.*;
import java.io.*;
public class Task06 {
	public static void main(String[] args) throws Exception {
		File file = new File("Excercise12_15.txt");
		if (!file.exists()) {
			PrintWriter output = new PrintWriter(file);
			for (int i = 0; i < 100; i++) {
				output.print((int)(Math.random() * 100 * Math.random()) + " ");
			}
			output.close();
		}
		Scanner input = new Scanner(file);
		int[] num = new int[100];
		for (int i = 0; i < 100; i++) {
			num[i] = input.nextInt();
		}
		input.close();
		bubbleSort(num);
		for (int value: num)
			System.out.print(value + " ");
		
	}
	
	public static void bubbleSort(int[] num) {
		for (int i = 0; i < num.length - 1; i++)
			for (int j = 0; j < num.length - i - 1; j++)
				if (num[j] > num[j + 1]) {
					int temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
	}

}
