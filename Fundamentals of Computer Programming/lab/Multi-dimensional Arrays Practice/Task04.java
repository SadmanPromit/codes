import java.util.Scanner;
public class Task04 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter password: ");
		String password = input.nextLine();
		input.close();
		System.out.println(isValid(password) ? "Valid Password" : "Invalid Password");
		
	}
	
	public static boolean isValid(String password) {
		if (password.length() < 8)
			return false;
		int countDigit = 0;
		for (int i = 0; i < password.length(); i++) {
			if (Character.isLetter(password.charAt(i)))
				continue;
			else if (Character.isDigit(password.charAt(i)))
				countDigit++;
			else
				return false;
		}
		if (countDigit < 2)
			return false;
		else
			return true;
	}

}
