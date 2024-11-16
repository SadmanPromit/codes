import java.util.Scanner;
public class Task10 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of rows in the matrix: ");
		int n = input.nextInt();
		int[][] m = new int[n][n];
		System.out.println("Enter the matrix row by row: ");
		for (int i = 0; i < m.length; i++)
			for (int j = 0; j < m[i].length; j++)
				m[i][j] = input.nextInt();
		input.close();
		int[] output = findLargestBlock(m);
		System.out.println("The maximum square submatrix is at (" + output[0] + ", " + output[1] + ") with size " + output[2]);
	}
	
	public static int[] findLargestBlock(int[][] m) {
		int highestSize = 0;
		int[] highestSquare = null;
		for (int row = 0; row < m.length; row++)
			for (int column = 0; column < m[row].length; column++) {
				int occurrence = getOccurrence(m, row, column);
				if (occurrence < 2)
					continue;
				if (scanPossibleSquare(m, row, column, occurrence) && occurrence > highestSize) {
					highestSize = occurrence;
					highestSquare = new int[] {row, column, occurrence};
				}
			}
		return highestSquare;
	}
	
	public static int getOccurrence(int[][] m, int row, int column) {
		int occurrence = 0;
		if (column == m[row].length - 1)
			return 0;
		for (int i = column; i < m[row].length; i++) {
			if (m[row][i] == 1)
				occurrence++;
		}
		return occurrence;
	}
	
	public static boolean scanPossibleSquare(int[][] m, int row, int column, int occurrence) {
		if (row + occurrence > m.length)
			return false;
		for (int i = row; i < row + occurrence; i++)
			for (int j = column; j < column + occurrence; j++)
				if (m[i][j] == 0)
					return false;
		return true;
	}

}
