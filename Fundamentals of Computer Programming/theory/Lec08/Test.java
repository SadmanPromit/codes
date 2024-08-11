import java.util.Scanner;
public class Test {
	public static void main(String[] args) {
		System.out.println("Enter radius of 50 circles: ");
		Circle[] myArr = new Circle[5];
		Scanner input = new Scanner(System.in);
		for (int i = 0; i < myArr.length; i++) {
			double r = input.nextDouble();
			myArr[i] = new Circle(r);
		}
		double maxRadius = 0;
		int circleIndex = 0;
		for (int i = 0; i < myArr.length - 1; i++) {
			if (myArr[i].getRadius() > myArr[i + 1].getRadius()) {
				maxRadius = myArr[i].getRadius();
				circleIndex = i;
			}
			else {
				maxRadius = myArr[i + 1].getRadius();
				circleIndex = i + 1;;
			}
		}
		System.out.println("Maximum radius is " + maxRadius + " and the index of the circle is " + circleIndex);
		input.close();
	}

}
