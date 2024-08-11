import java.util.Scanner;
public class Task05 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String str = input.nextLine();
		input.close();
		System.out.println(countLetters(str));
	}
	
	public static int countLetters(String s) {
		int countLetter = 0;
		for (int i = 0; i < s.length(); i++) {
			if (Character.isLetter(s.charAt(i)))
				countLetter++;
		}
		return countLetter;
	}

}
