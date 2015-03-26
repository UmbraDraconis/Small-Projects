
public class stud1 extends test{
	private final int MATH_HRS = 20;
	private final int CS_HRS = 40;
	private final int GE_HRS = 60;
	
	private int mathHrs, csHrs, geHrs;
	
	public stud1(String name, int idNum, int year) {
		super(name, idNum, year);
	}
	
	public void setMathHrs(int math) {
		mathHrs = math;
	}
	public void setCSHrs(int cs) {
		csHrs = cs;
	}
	public void setGEHrs(int ge) {
		geHrs = ge;
	}
	
	public int getRemainingHours() {
		int reqHrs, comHrs;
		
		reqHrs = MATH_HRS + CS_HRS + GE_HRS;
		comHrs = mathHrs + csHrs + geHrs;
		
		return reqHrs - comHrs;
	}
	
	public String toString() {
		String str;
		
		str = super.toString() + 
			"\nMajor: Computer Science" +
			"\nMath Hours Taken: " + mathHrs +
			"\nComputer Science Hours Taken: " + csHrs +
			"\nGeneral Ed Hours Taken: " + geHrs;
		
		return str;
	}
}
