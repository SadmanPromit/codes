
public class Task04 {
	public static void main(String[] args) {
		for (int number = 1; number <= 10000; number++) {
			int index = 1;
			int sumOfFactors = 0;
			while (number > index) {
				if (number % index == 0) {
					sumOfFactors += index;
				}
				index++;
			}
			if (sumOfFactors == number)
				System.out.println(number);
		}
	}

}
