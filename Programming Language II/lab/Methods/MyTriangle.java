import java.util.Scanner;
public class MyTriangle {
	public static void main(String[] args) {
		System.out.println("Enter three sides of a triangle: ");
		Scanner input = new Scanner(System.in);
		double side1 = input.nextDouble();
		double side2 = input.nextDouble();
		double side3 = input.nextDouble();
		input.close();
		System.out.println(isValid(side1, side2, side3) ? "Area: " + area(side1, side2, side3) : "The input is invalid.");
	}
	public static boolean isValid(double side1, double side2, double side3) {
		return side1 + side2 > side3 && side2 + side3 > side1 && side3 + side1 > side2 ? true : false;
	}
	
	public static double area(double side1, double side2, double side3) {
		double s = (side1 + side2 + side3) / 2;
		return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
	}

}
