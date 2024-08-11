
public class TestRectangle {
	public static void main(String[] args) {
		Rectangle rectangle1 = new Rectangle(4, 40);
		Rectangle rectangle2 = new Rectangle(3.5, 35.9);
		System.out.println("Rectangle 1's width: " + rectangle1.width + ", height: " + rectangle1.height + ", area: " + rectangle1.getArea() + " and perimeter: " + rectangle1.getPerimeter());
		System.out.println("Rectangle 2's width: " + rectangle2.width + ", height: " + rectangle2.height + ", area: " + rectangle2.getArea() + " and perimeter: " + rectangle2.getPerimeter());
	}

}
