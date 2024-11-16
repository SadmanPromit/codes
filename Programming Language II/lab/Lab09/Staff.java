
public class Staff extends Employee {
	private String title;
	public Staff(String name) {
		this(name, "none");
	}
	public Staff(String name, String title) {
		super(name);
		this.title = title;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String toString() {
		return "Class name: " + this.getClass().getName() + " person's name: " + getName();
	}

}
