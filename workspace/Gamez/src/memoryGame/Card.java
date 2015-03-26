package memoryGame;

public abstract class Card {
	private String symbol;
	private boolean status;
	
	public Card(String symbol) {
		this.symbol = symbol;
		status = false;
	}
	
	public abstract void setStatus();
	
	public abstract boolean getStatus();
	
	public abstract String getSymbol();
	
	public String toString() {
		String str;
		
		
		
		return str;
	}
}
