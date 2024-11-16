
public class Task02 {
	public static void main(String[] args) {
		int tuition = 10000;
		int total = 0;
		for (int i = 1; i <= 14; i++) {
			tuition += tuition * 5 / 100;
			if (i == 10)
				System.out.println("Tuition after ten years: " + tuition);
			if (i > 10)
				total += tuition;
		}
		System.out.println("Total cost: " + total);
	}

}
