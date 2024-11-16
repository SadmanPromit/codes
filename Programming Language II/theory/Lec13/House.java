
public class House implements Cloneable, Comparable<House> {
	private int id;
	private double area;
	private java.util.Date whenBuilt;

	public House(int id, double area) {
		this.id = id;
		this.area = area;
		whenBuilt = new java.util.Date();
	}

	public int getId() {
		return id;
	}

	public double getArea() {
		return area;
	}

	public java.util.Date getWhenBuilt() {
		return whenBuilt;
	}
	
	@Override /** Override the protected clone method defined in the Object class, and strengthen its accessibility */
	public Object clone() throws CloneNotSupportedException {
		House newHouse = new House(id, area);
		newHouse.whenBuilt = whenBuilt;
		return newHouse;
	}

	@Override
	public int compareTo(House o) {
		// TODO Auto-generated method stub
		if (area > o.area)
			return 1;
		else if (area < o.area)
			return -1;
		else
			return 0;
	}

}
