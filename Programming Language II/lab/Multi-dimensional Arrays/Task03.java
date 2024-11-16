
public class Task03 {
	public static void main(String[] args) {
		int[][] m = new int[4][4];
		for (int i = 0; i < m.length; i++)
			for (int j = 0; j < m.length; j++)
				m[i][j] = (int)(Math.random() * 2);
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m[i].length; j++)
				System.out.print(m[i][j]);
			System.out.println();
		}
		int largestRowSum = 0;
		int largestColumnSum = 0;
		int largestRowIndex = 0;
		int largestColumnIndex = 0;
		for (int i = 0; i < m.length; i++) {
			int rowSum = 0;
			int columnSum = 0;
			for (int j = 0; j < m[i].length; j++) {
				rowSum += m[i][j];
				columnSum += m[j][i];
			}
			if (rowSum > largestRowSum) {
				largestRowSum = rowSum;
				largestRowIndex = i;
			}
			if (columnSum > largestColumnSum) {
				largestColumnSum = columnSum;
				largestColumnIndex = i;
			}
		}
		System.out.println("The largest row index: " + largestRowIndex);
		System.out.println("The largest column index: " + largestColumnIndex);
	}

}
