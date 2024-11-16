import java.util.Scanner;
public class Task06 {
	public static void main(String[] args) {
		System.out.println("Enter the subtotal and gratuity rate: ");;
		Scanner input = new Scanner(System.in);
		int subtotal = input.nextInt();
		int gratuityRate = input.nextInt();
		input.close();
		double gratuity = gratuityRate * subtotal / 100.00;
		double total = subtotal + gratuity;
		System.out.println("The gratuity is " + gratuity + " and total is " + total);
	}

}
