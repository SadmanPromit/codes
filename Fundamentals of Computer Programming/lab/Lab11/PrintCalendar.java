import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;
public class PrintCalendar {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter full year (e.g., 2012): ");
		int year = input.nextInt();
		System.out.println("Enter month as number between 1 and 12: ");
		int month = input.nextInt();
		input.close();
		GregorianCalendar calendar = new GregorianCalendar(year, month - 1, 1);
		String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		System.out.println();
		for (int i = 0; i < 29 / 2 - (months[calendar.get(Calendar.MONTH)].length() / 2 + 5 / 2); i++)
			System.out.print(" ");
		System.out.println(months[calendar.get(Calendar.MONTH)] + " " + calendar.get(Calendar.YEAR));
		System.out.println("    ---------------------");
		System.out.println(" Sun Mon Tue Wed Thu Fri Sat");
		System.out.println();
		for (int i = 1; i < calendar.get(Calendar.DAY_OF_WEEK); i++)
			System.out.print("    ");
		while (calendar.get(Calendar.DATE) < calendar.getActualMaximum(Calendar.DATE)) {
			if (calendar.get(Calendar.DAY_OF_WEEK) == 7)
				System.out.printf("%4d\n", calendar.get(Calendar.DATE));
			else
				System.out.printf("%4d", calendar.get(Calendar.DATE));
			calendar.add(Calendar.DATE, 1);
		}
		System.out.printf("%4d", calendar.get(Calendar.DATE));
	}

}
