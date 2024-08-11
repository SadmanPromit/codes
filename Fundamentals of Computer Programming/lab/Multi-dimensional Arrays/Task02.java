import java.util.Scanner;
public class Task02 {
	public static void main(String[] args) {
		double[][] m = getArray();
		System.out.println("Sum of the elements in the major diagonal is " + sumMajorDiagonal(m));
	}
	
	public static double[][] getArray(){
		Scanner input = new Scanner(System.in);
		double[][] m = new double[4][4];
		System.out.println("Enter a 4-by-4 matrix row by row: ");
		for (int i = 0; i < m.length; i++)
			for (int j = 0; j < m[i].length; j++)
				m[i][j] = input.nextDouble();
		input.close();
		return m;
	}
	
	public static double sumMajorDiagonal(double[][] m) {
		double sum = 0;
		for (int i = 0; i < m.length; i++)
			for (int j = 0; j < m.length; j++)
				if (i == j)
					sum += m[i][j];
		return sum;
	}

}
