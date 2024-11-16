
public class Task05 {
	public static void main(String[] args) {
		int[][] m = {{4, 2},{1, 7},{4, 5},{1, 2},{1, 1},{4, 1}};
		sort(m);
		System.out.print("{");
		for (int i = 0; i < m.length; i++) {
			System.out.print("{");
			for (int j = 0; j < m[i].length; j++)
				System.out.print(m[i][j] + ",");
			System.out.print("}");
		}
		System.out.print("}");
	}
	
	public static void sort(int m[][]) {
		for (int i = 0; i < m.length - 1; i++)
			for (int j = 0; j < m.length - i - 1; j++)
					if (m[j][0] > m[j + 1][0] || (m[j][0] == m[j + 1][0] && m[j][1] > m[j + 1][1])) {
						int temp = m[j][0];
						m[j][0] = m[j + 1][0];
						m[j + 1][0] = temp;
						temp = m[j][1];
						m[j][1] = m[j + 1][1];
						m[j + 1][1] = temp;
					}
	}

}
