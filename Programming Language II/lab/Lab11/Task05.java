
public class Task05 {
	public static void main(String[] args) {
		Circle circle1 = new Circle(3.5);
		Circle circle2 = new Circle(22.33);
		Rectangle rectangle1 = new Rectangle(5.54, 34.44);
		Rectangle rectangle2 = new Rectangle(21, 15.31);
		System.out.println("The total area of the four objects are: " + sumArea(new GeometricObject[] {circle1, circle2, rectangle1, rectangle2}));
	}
	
	public static double sumArea(GeometricObject[] a) {
		double sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += a[i].getArea();
		}
		return sum;
	}
	
}
