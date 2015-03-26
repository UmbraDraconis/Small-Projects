/*	
//	This class implements the algorithm of a Selection Sort to sort an array of doubles.
//  This class implements the Sort interface.
*/
public class SelectionSort implements SortAlgorithm {
	//This is the method that will sort the array of double integers.
	public void sort(double[] n, SortTimer t){
		for (int i = n.length - 1; i > 0; i--) {
			int maxIndex = i;
			for (int j = 0; j < i; j++) {
				if (n[maxIndex] < n[j])
					maxIndex = j;
				t.addComparison();
			}
			if(maxIndex != i) {
				double temp = n[i];
				n[i] = n[maxIndex];
				n[maxIndex] = temp;
				t.addMoves(2);
			}
		}
	}
}