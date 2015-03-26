/*
	This is the QuickSort class that implements the quick sort algorithm to sort
	an array.
*/

public class QuickSort implements SortAlgorithm{
	private SortTimer t;
	
	public void sort(double[] n, SortTimer t) {
		this.t = t;
		quicksort(n, 0, n.length - 1);
	}
	private void quicksort(double[] n, int left, int right) {
		if(left >= right)
			return;
		else {
			int pos = partition(n, left, right, (left + right) / 2);
			
			quicksort(n, left, pos - 1);
			quicksort(n, pos + 1, right);
		}
	}
	private int partition(double[] n, int left, int right, int pIndex) {
		int pos = left;
		
		swap(n, right, pIndex);
		for (int i = left; i <= right - 1; i++) {
			if(n[i] <= n[right]) {
				swap(n, i, pos);
				t.addComparison();
				pos++;
			}
		}
		swap(n, right, pos);
		return pos;
	}
	private void swap(double[] n, int first, int second) {
		double temp;
		temp = n[first];
		n[first] = n[second];
		n[second] = temp;
		t.addMoves(2);
	}
}