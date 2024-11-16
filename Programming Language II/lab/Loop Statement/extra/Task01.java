import java.util.Scanner;
public class Task01 {
	public static void main(String[] args) {
		System.out.println("Loan Amount: ");
		Scanner input = new Scanner(System.in);
		int loanAmount = input.nextInt();
		System.out.println("Number of Years: ");
		int numberOfYears = input.nextInt();
		System.out.println("Annual Interest Rate: ");
		int annualInterestRate  = input.nextInt();
		input.close();
		double monthlyInterestRate = annualInterestRate / 1200.0;
		//Using mortgage formula
		double monthlyPayment = loanAmount * monthlyInterestRate / (1 - (Math.pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
		double totalPayment = monthlyPayment * 12 * numberOfYears;
		System.out.printf("Monthly Payment: %.2f\n", monthlyPayment);
		System.out.printf("Total Payment: %.2f\n", totalPayment);
		
		double interest, principal, balance = loanAmount;
		System.out.println("Payment#\tInterest\tPrincipal\tBalance");
		for (int i = 1; i <= numberOfYears * 12; i++) {
			interest = monthlyInterestRate * balance;
			principal = monthlyPayment - interest;
			balance = balance - principal;
			System.out.printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", i, interest, principal, balance);
		}
		
		
	}

}
