import java.util.Scanner;
public class Task09 {
	public static void main(String[] args) {
		System.out.println("Enter the first string: ");
		Scanner input = new Scanner(System.in);
		String string1 = input.nextLine();
		System.out.println("Enter the second string: ");
		String string2 = input.nextLine();
		input.close();
		int index = 0;
		String prefix = "";
		
		while (string1.charAt(index) == string2.charAt(index)) {
			prefix += string1.charAt(index);
			index++;
		}
		if (prefix.length() > 0)
			System.out.println("The common prefix is " + prefix);
		else
			System.out.println("There is no common prefix between " + string1 + " and " + string2);
	}

}
