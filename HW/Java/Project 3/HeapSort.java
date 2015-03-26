/*
	This is the class where the sorting algorithm HeapSort is.
	This class with make a Heap of the array then return a sorted array.
 */
public class HeapSort implements SortAlgorithm{
	private int size;
	private SortTimer t;

	// This method will sort the array using the HeapSort algorithm.
	public void sort(double[] n, SortTimer t) {
		this.t = t;
		size = n.length;
		
		heapify(n);
		
		for(int i = 1; i < n.length; i++) {
			poll(n);
		}
	}
	
	// This method will make the array into a heap.
	private void heapify(double[] n) {
		for(int k = n.length / 2 - 1; k >= 0; k--) {
			siftDown(n, k);
		}
	}
	
	// This method will recursively sort the heap to in descending order.
	private void siftDown(double[] n, int parent) {
		int left = (2 * parent) + 1;
		int right = (2 * parent) + 2;
		int max = parent;
		
		if(left < size) {
			if(n[left] > n[max])
				max = left;
			t.addComparison();
		}
		if(right < size) {
			if(n[right] > n[max])
				max = right;
			t.addComparison();
		}
		if(max != parent) {
			double temp = n[parent];
			n[parent] = n[max];
			n[max] = temp;
			t.addMoves(2);
			siftDown(n, max);
		}
	}
	
	// This method will pull the max value from the heap and sort the heap.
	private double poll(double[] n) {
		double value = n[0];
		n[0] = n[size - 1];
		n[size - 1] = value;
		t.addMoves(2);
		
		size--;
		siftDown(n, 0);
		return value;		
	}
}