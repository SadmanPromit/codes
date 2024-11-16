import java.util.Scanner;
public class Task01 {
	public static void main(String[] args) {
		System.out.print("Enter two characters: ");
		Scanner input = new Scanner(System.in);
		String str = input.next();
		input.close();
		char major = str.charAt(0);
		char status = str.charAt(1);
		if (major == 'M' || major == 'C' || major == 'I') {
			if (status == '1' || status == '2' || status == '3' || status == '4') {
				switch (major) {
					case 'M': System.out.print("Mathematics ");
							break;
					case 'C': System.out.print("Computer ");
							break;
					case 'F': System.out.print("Information ");
							break;
				}
				switch (status) {
				case '1': System.out.print("Freshman");
						break;
				case '2': System.out.print("Sophomore");
						break;
				case '3': System.out.print("Junior");
						break;
				case '4': System.out.print("senior");
						break;
				}
			}
		}
	}

}
