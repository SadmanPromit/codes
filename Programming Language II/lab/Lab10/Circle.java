
public class Circle extends GeometricObject {
	private double radius;
	public Circle() {
		radius = 1.0;
	}
	public Circle(double radius) {
		this.radius = radius;
	}
	public Circle(double radius, String color, boolean filled) {
		super(color, filled);
		this.radius = radius;
	}
	public double getRadius() {
		return radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	public double getArea() {
		return Math.PI * radius * radius;
	}
	public double getPerimeter() {
		return 2 * Math.PI * radius;
	}
	public double getDiameter() {
		return 2 * radius;
	}
	@Override
	public String toString() {
		return "Circle's radius=" + radius + ", Area=" + getArea() + ", Perimeter=" + getPerimeter()
				+ ", Diameter=" + getDiameter() + ", Color=" + getColor() + ", Filled=" + isFilled()
				+ ", DateCreated=" + getDateCreated();
	}

}
