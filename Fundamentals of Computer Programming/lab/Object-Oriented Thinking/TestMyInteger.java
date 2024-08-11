
public class TestMyInteger {
	public static void main(String[] args) {
		MyInteger int1 = new MyInteger(23);
	    MyInteger int2 = new MyInteger(56);
	    MyInteger int3 = new MyInteger(2);
	    MyInteger int4 = new MyInteger(23);
	    System.out.println(int1.getValue() + " is even? " + int1.isEven());
	    System.out.println(int2.getValue() + " is odd? " + int2.isOdd());
	    System.out.println(int3.getValue() + " is prime? " + int3.isPrime());
	    System.out.println("Is 1 even? " + MyInteger.isEven(1));
	    System.out.println("Is 1 odd? " + MyInteger.isOdd(1));
	    System.out.println("Is 1 prime? " + MyInteger.isPrime(1));
	    System.out.println("Is " + int1.getValue() + " even? " + MyInteger.isEven(int1));
	    System.out.println("Is " + int2.getValue() + " odd? " + MyInteger.isOdd(int2));
	    System.out.println("Is " + int3.getValue() + " prime? " + MyInteger.isPrime(int3));
	    System.out.println("Is " + int1.getValue() + " equals 23? " + int1.equals(23));
	    System.out.println("Is " + int1.getValue() + " equals " + int4.getValue() + "? " + int1.equals(int4));
	    System.out.println(MyInteger.parseInt(new char[] {'1','2','3'}));
	    System.out.println(MyInteger.parseInt("123"));
	}

}
