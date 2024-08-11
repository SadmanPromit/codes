import java.util.Scanner;
public class TestTriangle {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the three sides of the triangle: ");
		double side1 = input.nextDouble();
		double side2 = input.nextDouble();
		double side3 = input.nextDouble();
		System.out.println("Enter a color: ");
		String color = input.next();
		System.out.println("Enter filled: ");
		boolean filled = input.nextBoolean();
		input.close();
		Triangle triangle = new Triangle(side1, side2, side3);
		triangle.setColor(color);
		triangle.setFilled(filled);
		System.out.println("Area: " + triangle.getArea() + " perimeter: " + triangle.getPerimeter() + " color: " + triangle.getColor() + " filled: " + triangle.isFilled());
	}

}
