import java.util.Scanner;
import java.lang.String;
public class Task03 {
	public static void main(String[] args) {
		System.out.println("Enter a string: ");
		Scanner input = new Scanner(System.in);
		String s = input.nextLine();
		input.close();
		int length = s.length();
		char[] c = s.toCharArray();
		System.out.println("The length is " + length);
		System.out.println("The character at even places are: ");
		for (int i = 0; i < length; i+=2){
			System.out.println(c[i]);
		}
	}

}
