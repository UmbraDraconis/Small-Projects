
public class stud2 extends test{
	private final int MATH_HRS = 20;
	private final int BIO_HRS = 40;
	private final int GE_HRS = 60;
	
	private int mathHrs, bioHrs, geHrs;
	
	public stud2(String name, int idNum, int year) {
		super(name, idNum, year);
	}
	
	public void setMathHrs(int math) {
		mathHrs = math;
	}
	public void setBioHrs(int bio) {
		bioHrs = bio;
	}
	public void setGEHrs(int ge) {
		geHrs = ge;
	}
	
	public int getRemainingHours() {
		int reqHrs, comHrs;
		
		reqHrs = MATH_HRS + BIO_HRS + GE_HRS;
		comHrs = mathHrs + bioHrs + geHrs;
		
		return reqHrs - comHrs;
	}
	
	public String toString() {
		String str;
		
		str = super.toString() + 
			"\nMajor: Biology" +
			"\nMath Hours Taken: " + mathHrs +
			"\nComputer Science Hours Taken: " + bioHrs +
			"\nGeneral Ed Hours Taken: " + geHrs;
		
		return str;
	}
}
