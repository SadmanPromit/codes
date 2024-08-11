import java.util.Scanner;
public class Task02 {
	public static boolean equals(int[][] m1, int[][] m2) {
		for (int i = 0; i < m1.length; i++) {
			for (int j = 0; j < m1[i].length; j++) {
				if (m1[i][j] != m2[i][j])
					return false;
			}
		}
		return true;
	}
	public static void main(String[] args) {
		System.out.println("Enter list1: ");
		int[][] m1 = new int[3][3];
		int[][] m2 = new int[3][3];
		Scanner input = new Scanner(System.in);
		for (int i = 0; i < m1.length; i++) {
			for (int j = 0; j < m1[i].length; j++) {
				m1[i][j] = input.nextInt();
			}
		}
		System.out.println("Enter list2: ");
		for (int i = 0; i < m2.length; i++) {
			for (int j = 0; j < m2[i].length; j++) {
				m2[i][j] = input.nextInt();
			}
		}
		input.close();
		if (equals(m1,m2))
			System.out.println("The two arrays are identical");
		else
			System.out.println("The two arrays are not identical");
			
	}

}
