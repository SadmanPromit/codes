import java.util.ArrayList;
public class Task01 {
	public static void main(String[] args) {
		ArrayList<Object> list = new ArrayList<>();
		list.add(new Loan());
		list.add(new java.util.Date());
		list.add("Hello World");
		list.add(new Circle());
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i).toString());
		}
	}

}
