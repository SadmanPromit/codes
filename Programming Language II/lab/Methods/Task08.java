import java.util.Scanner;
public class Task08 {
	public static void main(String[] args) {
		System.out.println("Enter milliseconds: ");
		Scanner input = new Scanner(System.in);
		long millis = input.nextLong();
		input.close();
		System.out.println("Converted to hours, minutes, and seconds as hours:minutes:seconds " + convertMillis(millis));
	}
	
	public static String convertMillis(long millis) {
		long seconds = millis / 1000;
		long hours = seconds / (60 * 60);
		seconds %= (60 * 60);
		long minutes = seconds / 60;
		seconds %= 60;
		return hours + ":" + minutes + ":" + seconds;
	}

}
