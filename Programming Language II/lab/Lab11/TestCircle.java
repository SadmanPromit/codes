
public class TestCircle {
	public static void main(String[] args) {
		Circle circle1 = new Circle(2);
		Circle circle2 = new Circle(3);
		Circle circle3 = new Circle(2);
		System.out.println("Circle1 is" + (circle1.equals(circle2) ? " equals " : " is not equal ") + "to circle2.");
		System.out.println("Circle1 is" + (circle1.equals(circle3) ? " equals " : " is not equal ") + "to circle3.");
	}

}
