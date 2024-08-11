import java.util.Scanner;
public class Task01 {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		double[][] m = new double[3][4];
		System.out.println("Enter " + m.length + " rows and " + m[0].length + " columns: ");
		for (int i = 0; i < m.length; i++)
			for (int j = 0; j < m[i].length; j++)
				m[i][j] = input.nextDouble();
		System.out.println("Enter column index: ");
		int columnIndex = input.nextInt();
		input.close();
		System.out.println("Sum of the elements at column " + columnIndex + " is " + sumColumn(m, columnIndex));
		
	}

	public static double sumColumn(double[][] m, int columnIndex){
		double total = 0;
		for (int i = 0; i < m.length; i++){
			total += m[i][columnIndex];
		}
		return total;
	}

}
