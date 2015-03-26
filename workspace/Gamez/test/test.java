
public abstract class test {
	
	private String name;
	private int idNum;
	private int year;
	
	public test(String name, int idNum, int year) {
		this.name = name;
		this.idNum = idNum;
		this.year = year;
	}
	
	public String toString() {
		String str;
		
		str = "Name: " + name
			+ "\nID Number: " + idNum
			+ "\nYear Admitted: " + year;
		return str;
	}
	
	public abstract int getRemainingHours();
}
