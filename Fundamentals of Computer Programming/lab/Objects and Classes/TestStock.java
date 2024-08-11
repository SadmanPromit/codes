
public class TestStock {
	public static void main(String[] args) {
		Stock stock = new Stock("ORCL", "Oracle Corporation");
		stock.previousClosingPrice = 34.5;
		stock.currentPrice = 34.35;
		System.out.println("Price-change percentage: " + stock.getChangePercent());
	}

}
