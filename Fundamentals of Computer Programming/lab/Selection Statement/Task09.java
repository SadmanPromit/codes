import java.util.Scanner;
public class Task09 {
	public static void main(String[] args) {
		System.out.println("Enter the number of students: ");
		Scanner input = new Scanner(System.in);
		int numOfStudents = input.nextInt();
		int max1 = 0;
		int max2 = 0;
		String first = "";
		String second = "";
		for (int i = 1; i <= numOfStudents; i++) {
			System.out.println("Enter student's name and score: ");
			String name = input.next();
			int score = input.nextInt();
			if ( score > max1) {
				max2 = max1;
				max1 = score;
				second = first;
				first = name;
			}
			else if (score > max2) {
				max2 = score;
				second = name;
			}
		}
		input.close();
		System.out.println("Highest scorer is " + first + " and second highest scorer is " + second + ".");
	}

}
