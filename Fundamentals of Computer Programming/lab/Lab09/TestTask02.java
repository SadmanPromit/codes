
public class TestTask02 {
	public static void main(String[] args) {
		Person person = new Person("person");
		Student student = new Student("student");
		Employee employee = new Employee("employee");
		Faculty faculty = new Faculty("faculty");
		Staff staff = new Staff("staff");
		System.out.println(person.toString());
		System.out.println(student.toString());
		System.out.println(employee.toString());
		System.out.println(faculty.toString());
		System.out.println(staff.toString());
	}

}
