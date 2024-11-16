import java.util.Scanner;
public class Task08 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[][] m1 = new int[3][3];
		System.out.println("Enter list1: ");
		for (int i = 0; i < m1.length; i++)
			for (int j = 0; j < m1[i].length; j++)
				m1[i][j] = input.nextInt();
		int[][] m2 = new int[3][3];
		System.out.println("Enter list2: ");
		for (int i = 0; i < m2.length; i++)
			for (int j = 0; j < m2[i].length; j++)
				m2[i][j] = input.nextInt();
		input.close();
		System.out.println("The two arrays are" + (equals(m1, m2) ? " " : " not ") + "strictly identical");
	}
	
	public static boolean equals(int[][] m1, int[][] m2) {
		for (int i = 0; i < m1.length; i++)
			for (int j = 0; j < m1[i].length; j++)
				if (m1[i][j] != m2[i][j])
					return false;
		return true;
	}

}
