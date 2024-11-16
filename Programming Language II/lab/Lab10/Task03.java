import java.util.Scanner;
import java.util.ArrayList;
public class Task03 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter 5 numbers: ");
		ArrayList<Double> list = new ArrayList<>();
		for (int i = 0; i < 5; i++)
			list.add(input.nextDouble());
		input.close();
		System.out.println("Sum: " + sum(list));			
	}
	public static double sum(ArrayList<Double> list) {
		double sum = 0;
		for (int i = 0; i < list.size(); i++)
			sum += list.get(i);
		return sum;
	}

}
