
public class Circle2D {
	private double x;
	private double y;
	private double radius;
	Circle2D() {
		x = 0;
		y = 0;
		radius = 1;
	}
	public Circle2D(double x, double y, double radius) {
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
	public double getX() {
		return x;
	}
	public double getY() {
		return y;
	}
	public double getRadius() {
		return radius;
	}
	public double getArea() {
		return Math.PI * radius * radius;
	}
	public double getPerimeter() {
		return 2 * Math.PI * radius;
	}
	public boolean contains(double x, double y) {
		return distance(this.x, x, this.y, y) <= radius;
	}
	public boolean contains(Circle2D circle) {
		return distance(this.x, circle.x, this.y, circle.y) + circle.radius <= this.radius;
	}
	public boolean overlaps(Circle2D circle) {
		return this.radius + circle.radius >= distance(this.x, circle.x, this.y, circle.y);
	}
	public double distance(double x1, double y1, double x2, double y2) {
		return Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
	}

}
