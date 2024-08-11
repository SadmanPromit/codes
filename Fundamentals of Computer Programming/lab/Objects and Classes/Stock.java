
public class Stock {
	String symbol;
	String name;
	double previousClosingPrice;
	double currentPrice;
	Stock(String symbol, String name) {
		this.symbol = symbol;
		this.name = name;
	}
	public double getChangePercent() {
		return currentPrice - previousClosingPrice;
	}

}
