
public class Loan {
	private double loanAmount;
	private int numberOfYears;
	private double annualInterestRate;
	private java.util.Date loanDate;
	public Loan() {
		this(1000, 1, 2.5);
	}
	public Loan(double loanAmount, int numberOfYears, double annualInterestRate) {
		this.loanAmount = loanAmount;
		this.numberOfYears = numberOfYears;
		this.annualInterestRate = annualInterestRate;
		loanDate = new java.util.Date();
	}
	public double getLoanAmount() {
		return loanAmount;
	}
	public void setLoanAmount(double loanAmount) {
		this.loanAmount = loanAmount;
	}
	public int getNumberOfYears() {
		return numberOfYears;
	}
	public void setNumberOfYears(int numberOfYears) {
		this.numberOfYears = numberOfYears;
	}
	public double getAnnualInterestRate() {
		return annualInterestRate;
	}
	public void setAnnualInterestRate(double annualInterestRate) {
		this.annualInterestRate = annualInterestRate;
	}
	public java.util.Date getLoanDate() {
		return loanDate;
	}
	public double getMonthlyPayment() {
		double monthlyInterestRate = annualInterestRate / 1200;
		return loanAmount * monthlyInterestRate / (1 - (Math.pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
	}
	public double getTotalPayment() {
		return getMonthlyPayment() * numberOfYears * 12;
	}
	@Override
	public String toString() {
		return "LoanAmount=" + loanAmount + ", numberOfYears=" + numberOfYears + ", annualInterestRate="
				+ annualInterestRate + ", loanDate=" + loanDate + ", MonthlyPayment=" + getMonthlyPayment()
				+ ", TotalPayment=" + getTotalPayment();
	}

}
