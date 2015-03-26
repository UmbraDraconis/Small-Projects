/*
// This class implements the sorting algorithm Insertion Sort.
// The class with sort an array of doubles using this specific algorithm.
*/
public class InsertionSort implements SortAlgorithm {
	// This is the method that sorts an array of doubles.
	public void sort(double[] n, SortTimer t){
		for (int i = 1; i < n.length; i++){
			double cValue = n[i];
			for(int j = i - 1; j >= 0; j--) {
				if(cValue < n[j]){
					n[j+1] = n[j];
					n[j] = cValue;
					t.addMoves(2);
				}
				t.addComparison();
			}
		}
	}
}