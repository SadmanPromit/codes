
public class Task06 {
	public static void main(String[] args) {
		int lineCount = 1;
		for (int row = 1; row <= 128; row += row) {
			for (int i = 7; i >= lineCount; i--)
				System.out.print("  ");
			for (int i = 1; i <= row; i += i)
				System.out.print(i + " ");
			for (int i = row / 2; i >= 1; i /= 2)
				System.out.print(i + " ");
			System.out.println();
			lineCount++;
		}
	}

}
