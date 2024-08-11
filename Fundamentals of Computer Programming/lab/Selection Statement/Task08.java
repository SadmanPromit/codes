
public class Task08 {
	public static void main(String[] args) {
		final double POUND_PER_KILOGRAM = 2.2;
		System.out.println("Kilograms\tPounds\t|\tPounds\tKilograms");
		for (int i = 1, j = 20; i <= 199 && j <= 515; i += 2, j += 5) {
			System.out.printf("%d\t\t%3.1f\t|\t%d\t%3.2f\n",i , i * POUND_PER_KILOGRAM, j, j / POUND_PER_KILOGRAM);
		}
	}

}
