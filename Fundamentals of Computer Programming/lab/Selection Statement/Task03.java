import java.util.Scanner;
public class Task03 {
	public static void main(String[] args) {
		System.out.println("Enter today's day: ");
		Scanner input = new Scanner(System.in);
		int day = input.nextInt();
		System.out.println("Enter the number of days elapsed since today: ");
		int dayAdd = input.nextInt();
		input.close();
		day = (day + dayAdd) % 7;
		switch (day) {
		case 0: System.out.println("Sunday");
				break;
		case 1: System.out.println("Monday");
				break;
		case 2: System.out.println("Tuesday");
				break;
		case 3: System.out.println("Wednesday");
				break;
		case 4: System.out.println("Thursday");
				break;
		case 5: System.out.println("Friday");
				break;
		case 6: System.out.println("Saturday");
				break;
		}
	}

}
