
public class Student extends Person {
	private final String STATUS;
	public Student(String name) {
		this(name, "none");
	}
	public Student(String name, String STATUS) {
		super(name);
		this.STATUS = STATUS;
	}
	public String getSTATUS() {
		return STATUS;
	}
	public String toString() {
		return "Class name: " + this.getClass().getName() + " person's name: " + getName();
	}

}
