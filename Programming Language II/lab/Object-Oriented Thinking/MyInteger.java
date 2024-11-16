
public class MyInteger {
	private int value;
	MyInteger(int value) {
		this.value = value;
	}
	public int getValue() {
		return value;
	}
	public boolean isEven() {
		return value % 2 == 0;
	}
	public boolean isOdd() {
		return value % 2 == 1;
	}
	public boolean isPrime() {
		if (value < 2)
			return false;
		for (int i = 2; i < value; i++)
			if (value % i == 0)
				return false;
		return true;
	}
	public static boolean isEven(int value) {
		return value % 2 == 0;
	}
	public static boolean isOdd(int value) {
		return value % 2 == 1;
	}
	public static boolean isPrime(int value) {
		if (value < 2)
			return false;
		for (int i = 2; i < value; i++)
			if (value % i == 0)
				return false;
		return true;
	}
	public static boolean isEven(MyInteger myInteger) {
		return myInteger.isEven();
	}
	public static boolean isOdd(MyInteger myInteger) {
		return myInteger.isOdd();
	}
	public static boolean isPrime(MyInteger myInteger) {
		return myInteger.isPrime();
	}
	public boolean equals(int value) {
		return this.value == value;
	}
	public boolean equals(MyInteger myInteger) {
		return this.value == myInteger.value;
	}
	public static int parseInt(char[] value) {
		int number = 0;
		for (int values: value) {
			number = number * 10 + Character.getNumericValue(values);
		}
		return number;
	}
	public static int parseInt(String s) {
		return parseInt(s.toCharArray());
	}

}
