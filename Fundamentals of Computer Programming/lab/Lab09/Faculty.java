
public class Faculty extends Employee {
	private String officeHours;
	private String rank;
	public Faculty(String name) {
		this(name, "none", "none");
	}
	public Faculty(String name, String officeHours, String rank) {
		super(name);
		this.officeHours = officeHours;
		this.rank = rank;
	}
	public String getOfficeHours() {
		return officeHours;
	}
	public void setOfficeHours(String officeHours) {
		this.officeHours = officeHours;
	}
	public String getRank() {
		return rank;
	}
	public void setRank(String rank) {
		this.rank = rank;
	}
	public String toString() {
		return "Class name: " + this.getClass().getName() + " person's name: " + getName();
	}

}
