import java.util.Scanner;
import java.util.ArrayList;
public class Task02 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the array size n: ");
		int n = input.nextInt();
		input.close();
		int[][] m = new int[n][n];
		for (int i = 0; i < m.length; i++)
			for (int j = 0; j < m[i].length; j++)
				m[i][j] = (int)(Math.random() * 2);
		System.out.println("The random array is");
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m[i].length; j++)
				System.out.print(m[i][j]);
			System.out.println();
		}
		ArrayList<Integer> row = new ArrayList<>();
		ArrayList<Integer> column = new ArrayList<>();
		getLargestRow(m, row);
		getLargestColumn(m, column);
		System.out.println("The largest row index: " + row);
		System.out.println("The largest column index: " + column);
	}
	public static void getLargestRow(int[][] m, ArrayList<Integer> row) {
		int largest = 0;
		for (int i = 0; i < m.length; i++) {
			int occurrence = 0;
			for (int j = 0; j < m[i].length; j++)
				if (m[i][j] == 1)
					occurrence++;
			if (occurrence > largest) {
				largest = occurrence;
				row.clear();
				row.add(i);
			}
			else if (occurrence == largest)
				row.add(i);
		}
	}
	public static void getLargestColumn(int[][] m, ArrayList<Integer> column) {
		int largest = 0;
		for (int i = 0; i < m.length; i++) {
			int occurrence = 0;
			for (int j = 0; j < m[i].length; j++)
				if (m[j][i] == 1)
					occurrence++;
			if (occurrence > largest) {
				largest = occurrence;
				column.clear();
				column.add(i);
			}
			else if (occurrence == largest)
				column.add(i);
		}
	}

}
