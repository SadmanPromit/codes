import java.util.Scanner;
public class Task03 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String[] city = new String[3];
		System.out.println("Enter the first city: ");
		city[0] = input.nextLine();
		System.out.println("Enter the second city: ");
		city[1] = input.nextLine();
		System.out.println("Enter the third city: ");
		city[2] = input.nextLine();
		input.close();
		for (int i = 0; i < 3 - 1; i++)
			for (int j = 0; j < 3 - i - 1; j++)
				if (city[j].charAt(0) > city[j + 1].charAt(0)) {
					String temp = city[j];
					city[j] = city[j + 1];
					city[j + 1] = temp;
				}
		System.out.println("The three cities in alphabetical order are " + city[0] + " " + city[1] + " " + city[2]);
	}

}
