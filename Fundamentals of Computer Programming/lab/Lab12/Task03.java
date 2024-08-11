import java.util.*;
public class Task03 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter string: ");
		System.out.println(bin2Dec(input.nextLine()));
		input.close();
	}
	
	public static int bin2Dec(String binaryString) throws NumberFormatException {
		if (!isBinary(binaryString))
			throw new NumberFormatException(binaryString + " is not a binary number");
		int demical = 0;
		int power = 0;
		for (int i = binaryString.length() - 1; i >= 0; i--) {
			if (binaryString.charAt(i) == '1')
				demical += Math.pow(2, power);
			power++;
		}
		return demical;
	}
	
	public static boolean isBinary(String binaryString) {
		for (char input: binaryString.toCharArray()) {
			if (input != '0' && input != '1')
				return false;
		}
		return true;
	}

}
