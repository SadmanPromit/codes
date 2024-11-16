import java.util.Scanner;
public class Task05 {
	public static void main(String[] args) {
		System.out.println("The amount invested: ");
		Scanner input = new Scanner(System.in);
		double investmentAmount = input.nextDouble();
		System.out.println("Annual interest rate: ");
		double annualInterestRate = input.nextDouble();
		input.close();
		double monthlyInterestRate = annualInterestRate / 1200;
		
		System.out.println("Years Future Value");
		for (int years = 1; years <= 30; years++) {
			System.out.printf("%d %.2f\n", years, futureInvestmentValue(investmentAmount, monthlyInterestRate, years));
		}
		
	}
	
	public static double futureInvestmentValue(double investmentAmount, double monthlyInterestRate, int years) {
		return investmentAmount * Math.pow(1 + monthlyInterestRate, years * 12);
	}

}
