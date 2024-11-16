
public class Circle {
	private double radius;
	private static int numberOfObjects;
	Circle() {
		
	}
	Circle(double radius) {
		this.radius = radius;
	}
	public double getRadius() {
		return radius;
	}
	public static int getNumberOfObjects() {
		return numberOfObjects;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}

}
