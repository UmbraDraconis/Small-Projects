import java.util.Random;
import java.util.Scanner;

public class Sorter {
	public static void main(String[] args) {
		Random rand = new Random();
		Scanner scan = new Scanner(System.in);
		SortAlgorithm s = null;
		
		int input, arraySize = 1;
		double[] array;
		
		displayMenu();
		input = scan.nextInt();
		switch (input) {
			case 1:		
				s = new SelectionSort();
				break;
			case 2:		
				s = new InsertionSort();
				break;
			case 3:		
				s = new HeapSort();
				break;
			case 4:		
				s = new QuickSort();
				break;
			default:
				System.out.println("Invalid choice.");
				System.exit(0);
				break;
		}
		
		System.out.println("Array size: ");
		input = scan.nextInt();
		SortTimer t = new SortTimer();
		for (int i = 0; i < input; i++) {
			arraySize *= 10;
			array = new double[arraySize];
			for (int j = 0; j < arraySize; j++)
				array[j] = rand.nextDouble();
			t.reset();
			s.sort(array, t);
			displayTimer(arraySize, t);
		}
	}
	
	public static void displayTimer(int arraySize, SortTimer t) {
		System.out.printf("%12s %12s %12s %12s", "Array Size", "Comparisons", "Moves", "Time");
		System.out.printf("\n%12d %12d %12d %12d", arraySize, t.getComparisons(), t.getMoves(), t.getElapsedTime());
		System.out.println("\n");
	}
	
	public static void displayArray(double[] array) {
		for(int i = 0; i < array.length; i++)
			System.out.printf("%.3f ", array[i]);
		System.out.println();
	}
	
	public static void displayMenu() {
		System.out.println("*****Sort Option Menu*****\n"
						 + "* 1. Selection Sort      *\n"
						 + "* 2. Insertion Sort      *\n"
						 + "* 3. Heap Sort           *\n"
						 + "* 4. Quick Sort          *\n");
	}
}