
public class Task02 {
	public static void main(String[] args) {
		int count = 0;
		for (int number = 2; number <= 1000; number++) {
			boolean isPrime = true;
			for (int i = 2; i < number; i++) {
				if (number % i == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				System.out.print(number + " ");
				count++;
				if (count % 8 == 0)
					System.out.println();
			}
		}
	}

}
