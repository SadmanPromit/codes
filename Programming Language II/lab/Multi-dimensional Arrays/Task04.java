import java.util.Scanner;

public class Task04 {
	public static void main(String[] args) {
		int[] largest = locateLargest(getArray());
		System.out.println("The location of the largest element is at (" + largest[0] + ", " + largest[1] + ")");
	}
	
	public static double[][] getArray(){
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of rows and columns of the array: ");
		double[][] m = new double[input.nextInt()][input.nextInt()];
		System.out.println("Enter the array: ");
		for (int i = 0; i < m.length; i++)
			for (int j = 0; j < m[i].length; j++)
				m[i][j] = input.nextDouble();
		input.close();
		return m;
	}
	
	public static int[] locateLargest(double[][] a) {
		double max = 0;
		int[] largest = {0, 0};
		for (int i = 0; i < a.length; i++)
			for (int j = 0; j < a[i].length; j++)
				if (a[i][j] > max) {
					max = a[i][j];
					largest[0] = i;
					largest[1] = j;
				}
		return largest;
	}

}
