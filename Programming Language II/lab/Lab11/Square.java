
public class Square extends GeometricObject implements Colorable {
	double side = 1;
	public Square() {
		
	}

	public Square(double side) {
		this.side = side;
	}

	public double getSide() {
		return side;
	}

	public void setSide(double side) {
		this.side = side;
	}

	@Override
	public void howToColor() {
		System.out.print("Color all four sides");
	}

	@Override
	public double getArea() {
		return side * side;
	}

	@Override
	public double getPerimeter() {
		return 4 * side;
	}

}
