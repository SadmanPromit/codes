import java.util.Scanner;
public class Task06 {
	public static void main(String[] args) {
		System.out.println("Enter ten double values: ");
		Scanner input = new Scanner(System.in);
		double[] number = new double[10];
		for (int i = 0; i < number.length; i++)
			number[i] = input.nextDouble();
		input.close();
		System.out.println("The average is: " + average(number));
	}
		
	public static int average(int[] array) {
		int sum = 0;
		for (int i = 0; i < array.length; i++)
			sum += array[i];
		return sum / array.length;
	}
	public static double average(double[] array) {
		double sum = 0;
		for (int i = 0; i < array.length; i++)
			sum += array[i];
		return sum / array.length;
	}

}
