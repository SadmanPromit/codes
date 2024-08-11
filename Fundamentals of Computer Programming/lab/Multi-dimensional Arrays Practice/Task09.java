import java.util.Scanner;
public class Task09 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String s = input.nextLine();
		input.close();
		System.out.println(sort(s));
	}
	
	public static String sort(String s) {
		char[] sToChar = s.toCharArray();
		for (int i = 0; i < sToChar.length - 1; i++)
			for (int j = 0; j < sToChar.length - i - 1; j++)
				if (sToChar[j] > sToChar[j + 1]) {
					char temp = sToChar[j];
					sToChar[j] = sToChar[j + 1];
					sToChar[j + 1] = temp;
				}
		return new String(sToChar);
	}

}
