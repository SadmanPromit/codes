
public class Task04 {
	public static void main(String[] args) {
		int[] prime = new int[50];
		int index = 0;
		for (int i = 2; index < prime.length; i++) {
			if (isPrime(i)) {
				prime[index++] = i;
			}
		}
		for (int value: prime)
			System.out.print(value + " ");
		
	}
	
	public static boolean isPrime(int number) {
		for (int i = 2; i <= Math.sqrt(number); i++) {
			if (number % i == 0)
				return false;
		}
		return true;
	}

}
