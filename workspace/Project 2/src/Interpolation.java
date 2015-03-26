/*
 * 
 * @author Simon Lam
 * This project 
 *
 */
import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;

public class Interpolation {

	public static void main(String[] arg) {
		Scanner kb = new Scanner(System.in);
		String inputFile;
		System.out.println("Input file name:");
		inputFile = kb.nextLine();
		Interpolation i = new Interpolation();
		i.interpolate(inputFile);
		i.exit();
	}
	
	public void interpolate(String fileName) {
		setList(fileName);
		setPyramid();
		displayPyramid();
		displayUnSimPoly();
		displaySimPoly();
	}
	
	private void displaySimPoly() {
		double[] a = new double[x.length]; // holds the coefficient of the simplified polynomial
		double[] initial = new double[x.length];
		double[] mult = new double[2];
		double[] result = new double[x.length];
		int counter;
		
		mult[1] = 1;
		
		for(int i = 0; i < x.length; i++) { // create array of coefficients to display in a simplified polynomial
			if(i == 0) {
				a[0] += pList.get(0).get(0);
			} else {
				mult[0] = -x[i-1];
				if(i == 1) {
					if(i == 1) {
						for(int j = 0; j < mult.length; j++) {
							result[j] = mult[j];
						}
					}
				} else {
					counter = 0;
					for(int j = 0; j < i-1; j++) {
						result[j + 1] = mult[0] * initial[counter + 1] + mult[1] * initial[counter];
						counter++;
					}
	
					result[0] = mult[0] * initial[0];//tail coefficient
					result[i] = mult[1] * initial[i-1];//head coefficient
				}
				for(int j = 0; j < result.length; j++) { // adds the values from result into a
					a[j] += (pList.get(i).get(0) * result[j]);
					initial[j] = result[j];
				}
			}
		}
		counter = 0;
		System.out.println("\nSimplified Polynomial Interpolation:\n");
		for(int i = 0; i < a.length; i++) { // Displays the simplified polynomial
			counter++;
			if(a[i] == 0)
				continue;
			else {
				System.out.printf("%.2f", a[i]);
				if(i > 0) {
					System.out.printf("x^%d", counter - 1);
				}
				if(checkRemainingS(i, a))
					System.out.println();
				else
					System.out.print(" + ");
			}
		}
	}
	
	private boolean checkRemainingS(int i, double[] a) {
		if(i == a.length - 1)
			return true;
		for(int j = i+1; j < a.length; j++) {
			if(a[j] != 0) {
				return false;
			}
		}
		return true;
	}
	
	private void displayUnSimPoly() {
		System.out.println("\nPolynomial Interpolation Unsimplified:\n");
		for(int i = 0; i < x.length; i++) {
			if(pList.get(i).get(0) == 0)
				continue;
			else {
				System.out.printf("%.2f", pList.get(i).get(0));
				for(int j = 0; j < i; j++) {
					if(x[j] == 0)
						System.out.print("(x)");
					else if(x[j] < 0)
						System.out.printf("(x + %.2f)", Math.abs(x[j]));
					else
						System.out.printf("(x - %.2f)", x[j]);
				}
				if(checkRemainingU(i))
					System.out.println();
				else
					System.out.print(" + ");
			}
		}
	}
	
	private boolean checkRemainingU(int i) {
		if(i == x.length - 1)
			return true;
		for(int j = i+1; j < x.length; j++) {
			if(pList.get(j).get(0) != 0)
				return false;
		}
		return true;
	}
	
	private void displayPyramid() {
		System.out.println("Divided Difference Pyramid:\n");
		for(int i = 0; i <= pList.get(0).size(); i++) {
			if(i == 0) {
				System.out.printf("%3s\t", "x");
			} else {
				System.out.printf("%3s%d%s\t", "f", i - 1, "(x)");
			}
		}
		System.out.println();
		for(int i = 0; i < x.length; i++) {
			System.out.printf("%6.2f\t", x[i]);
			for(int j = 0; j < pList.get(i).size(); j++) {
				System.out.printf("%6.2f\t", pList.get(j).get(i));
			}
			System.out.println();
		}
	}
	
	private void setPyramid() {
		double tempx, tempy;
		int counter = 0;
		
		for(int i = 0; i <= x.length; i++) { // index of array x and fx
			pList.add(new ArrayList<Double>());
			counter++;
			for(int j = 0; j < pList.get(i).size() - 1; j++) {
				tempx = x[j + counter] - x[j];
				tempy = pList.get(i).get(j + 1) - pList.get(i).get(j);
				pList.get(i+1).add(tempy / tempx);
			}
		}
	}
	
	private void setList(String fileName) {
		ArrayList<Double> fileList = new ArrayList<>();
		
		fileList = getList(fileName);
		x = new double[fileList.size() / 2];
		pList.add(new ArrayList<Double>());
		
		for(int i = 0; i < fileList.size() / 2; i++) {
			x[i] = fileList.get(i);
		}
		for(int i = fileList.size() / 2; i < fileList.size(); i++) {
			pList.get(0).add(fileList.get(i));
		}
	}

	private ArrayList<Double> getList(String fileName) {
		Scanner inputFile;
		
		ArrayList<Double> list = new ArrayList<Double>();
		
		try{
			inputFile = new Scanner(new File(fileName));
			
			while(inputFile.hasNextDouble()) {
				list.add(inputFile.nextDouble());
			}
			
			inputFile.close();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			exit();
		}
		return list;
	}
	
	private void exit() {
		System.out.println("Program terminating.");
		System.exit(0);
	}
	
	private ArrayList<ArrayList<Double>> pList = new ArrayList<ArrayList<Double>>();
	private double[] x;
	
}