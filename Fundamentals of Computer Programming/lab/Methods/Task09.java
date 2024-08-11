import java.util.Scanner;
public class Task09 {
	public static void main(String[] args) {
		System.out.println("Enter the number of sides: ");
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		System.out.println("Enter the side: ");
		double side = input.nextDouble();
		input.close();
		System.out.println("The area of the polygon is " + area(n, side));
		
	}
	
	public static double area(int n, double side) {
		return 5 * Math.pow(side, 2) / (4 * Math.tan(Math.PI / 5));
	}

}
