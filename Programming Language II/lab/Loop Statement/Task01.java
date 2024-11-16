import java.util.Scanner;
public class Task01 {
	public static void main(String[] args) {
		System.out.println("Enter an integer, the input ends if it is 0: ");
		int countPositives = 0;
		int countNegatives = 0;
		float total = 0;
		Scanner input = new Scanner(System.in);
		int num = input.nextInt();
		while (num != 0) {
			total += num;
			if (num > 0)
				countPositives++;
			else
				countNegatives++;
			num = input.nextInt();
		}
		input.close();
		float average = total / (countPositives + countNegatives);
		System.out.println("The number of positives is " + countPositives);
		System.out.println("The number of negatives is " + countNegatives);
		System.out.println("The total is " + total);
		System.out.println("The average is " + average);
			
	}

}
