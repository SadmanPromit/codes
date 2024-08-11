import java.util.Scanner;
import java.util.ArrayList;
public class Task05 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the number of the points: ");
		int n = input.nextInt();
		ArrayList<MyPoint> points = new ArrayList<>();
		System.out.println("Enter the coordinates of the points: ");
		for (int i = 0; i < n; i++)
			points.add(new MyPoint(input.nextDouble(), input.nextDouble()));
		input.close();
		System.out.println("The total area is " + getPolygonArea(points));
	}
	public static double getPolygonArea(ArrayList<MyPoint> points) {
		double sum1 = 0;
		double sum2 = 0;
		for (int i = 0; i < points.size(); i++) {
			MyPoint p1 = points.get(i);
			MyPoint p2 = points.get((i + 1) % points.size());
			sum1 += p1.getX() * p2.getY();
			sum2 += p1.getY() * p2.getX();
		}
		return .5 * Math.abs(sum1 - sum2);
	}

}
