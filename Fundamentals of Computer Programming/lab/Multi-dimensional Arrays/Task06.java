
public class Task06 {
	public static void main(String[] args) {
		int[][] m = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
		shuffle(m);
		System.out.print("{");
		for (int i = 0; i < m.length; i++) {
			System.out.print("{");
			for (int j = 0; j < m[i].length; j++) {
				System.out.print(m[i][j] + ",");
			}
			System.out.print("}");
		}
		System.out.print("}");
	}
	
	public static void shuffle(int[][] m) {
		int[] temp = new int[2];
		for (int i = 0; i < m.length; i++) {
			int random = (int)(Math.random() * m.length);
			temp[0] = m[i][0];
			m[i][0] = m[random][0];
			m[random][0] = temp[0];
			temp[1] = m[i][1];
			m[i][1] = m[random][1];
			m[random][1] = temp[1];
		}
	}

}
