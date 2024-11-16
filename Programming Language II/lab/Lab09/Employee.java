import java.util.Date;

public class Employee extends Person {
	private String office;
	private double salary;
	private java.util.Date dateHired;
	public Employee(String name) {
		this(name, "none", 0, new java.util.Date());
	}
	public Employee(String name, String office, double salary, Date dateHired) {
		super(name);
		this.office = office;
		this.salary = salary;
		this.dateHired = dateHired;
	}
	public String getOffice() {
		return office;
	}
	public void setOffice(String office) {
		this.office = office;
	}
	public double getSalary() {
		return salary;
	}
	public void setSalary(double salary) {
		this.salary = salary;
	}
	public java.util.Date getDateHired() {
		return dateHired;
	}
	public void setDateHired(java.util.Date dateHired) {
		this.dateHired = dateHired;
	}
	public String toString() {
		return "Class name: " + this.getClass().getName() + " person's name: " + getName();
	}

}
