import java.util.Scanner;
public class Task07 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double[][] m = new double[3][3];
		System.out.println("Enter a 3-by-3 matrix row by row: ");
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				m[i][j] = input.nextDouble();
		input.close();
		System.out.println("It is" + (isMarkovMatrix(m) ? " " : " not ") + "a Markov matrix");
	}
	
	public static boolean isMarkovMatrix(double[][] m) {
		for (int i = 0; i < m.length; i++) {
			double sum = 0;
			for (int j = 0; j < m[i].length; j++) {
				if (m[i][j] < 0)
					return false;
				sum += m[j][i];
			}
			if (sum != 1)
				return false;
		}
		return true;
	}

}
