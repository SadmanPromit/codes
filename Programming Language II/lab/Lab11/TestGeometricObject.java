
public class TestGeometricObject {
	public static void main(String[] args) {
		GeometricObject[] geoShape = new GeometricObject[5];
		geoShape[0] = new Circle(5.5);
		geoShape[1] = new Square(10.28);
		geoShape[2] = new Triangle();
		geoShape[3] = new Circle();
		geoShape[4] = new Square();
		for (int i = 0; i < 5; i++) {
			System.out.print("Shape #" + (i + 1) + " area: " + geoShape[i].getArea());
			if (geoShape[i] instanceof Colorable) {
				System.out.print(" How to color: ");
				((Colorable)geoShape[i]).howToColor();
			}
			System.out.println();
		}
	}

}
