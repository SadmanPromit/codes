import java.util.Scanner;
public class Task07 {
	public static void main(String[] args) {
		System.out.println("Enter the year and first day of the year: ");
		Scanner input = new Scanner(System.in);
		int year = input.nextInt();
		int firstDay = input.nextInt();
		input.close();
		int numberOfDaysInMonth = 0;
		
		for (int month = 1; month <= 12; month++) {
			switch (month) {
				case 1: System.out.print("January 1, " + year + " is ");
						numberOfDaysInMonth = 31;
						System.out.println(firstDay(firstDay));
						break;
				case 2: System.out.print("February 1, " + year + " is ");
						if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
							numberOfDaysInMonth = 29;
						else
							numberOfDaysInMonth = 28;
						System.out.println(firstDay(firstDay));
						break;
				case 3: System.out.print("March 1, " + year + " is ");
						numberOfDaysInMonth = 31;
						System.out.println(firstDay(firstDay));
						break;
				case 4: System.out.print("April 1, " + year + " is ");
						numberOfDaysInMonth = 30;
						System.out.println(firstDay(firstDay));
						break;
				case 5: System.out.print("May 1, " + year + " is ");
						numberOfDaysInMonth = 31;
						System.out.println(firstDay(firstDay));
						break;
				case 6: System.out.print("June 1, " + year + " is ");
						numberOfDaysInMonth = 30;
						System.out.println(firstDay(firstDay));
						break;
				case 7: System.out.print("July 1, " + year + " is ");
						numberOfDaysInMonth = 31;
						System.out.println(firstDay(firstDay));
						break;
				case 8: System.out.print("August 1, " + year + " is ");
						numberOfDaysInMonth = 31;
						System.out.println(firstDay(firstDay));
						break;
				case 9: System.out.print("September 1, " + year + " is ");
						numberOfDaysInMonth = 30;
						System.out.println(firstDay(firstDay));
						break;
				case 10: System.out.print("October 1, " + year + " is ");
						numberOfDaysInMonth = 31;
						System.out.println(firstDay(firstDay));
						break;
				case 11: System.out.print("November 1, " + year + " is ");
						numberOfDaysInMonth = 30;
						System.out.println(firstDay(firstDay));
						break;
				case 12: System.out.print("December 1, " + year + " is ");
						numberOfDaysInMonth = 31;
						System.out.println(firstDay(firstDay));
						break;
			}
			firstDay = (firstDay + numberOfDaysInMonth) % 7;
		}
	}
	
	public static String firstDay(int firstDay) {
		String firstDayString = "";
		switch (firstDay) {
			case 0: firstDayString = "Sunday"; break;
			case 1: firstDayString = "Monday"; break;
			case 2: firstDayString = "Tuesday"; break;
			case 3: firstDayString = "Wednesday"; break;
			case 4: firstDayString = "Thursday"; break;
			case 5: firstDayString = "Friday"; break;
			case 6: firstDayString = "Saturday"; break;
		}
		return firstDayString;
	}

}
