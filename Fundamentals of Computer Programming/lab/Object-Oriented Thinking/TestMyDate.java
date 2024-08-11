
public class TestMyDate {
	public static void main(String[] args) {
		MyDate myDate1 = new MyDate();
		MyDate myDate2 = new MyDate(34355555133101L);
		System.out.println("Year: " + myDate1.getYear() + " Month: " + myDate1.getMonth() + " Day: " + myDate1.getDay());
		System.out.println("Year: " + myDate2.getYear() + " Month: " + myDate2.getMonth() + " Day: " + myDate2.getDay());
	}

}
