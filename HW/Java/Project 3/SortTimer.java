public class SortTimer {
	private long comparisons, moves, time;
	
	public SortTimer() {
		time = System.nanoTime();
		moves = 0;
		comparisons = 0;
	}

	public void reset() {
		comparisons = 0;
		moves = 0;
		time = System.nanoTime();
	}
	public void addComparison() {
		comparisons++;
	}
	public void addComparisons(int n){
		comparisons += n;
	}
	public void addMove() {
		moves++;
	}
	public void addMoves(int n) {
		moves += n;
	}
	public long getComparisons() {
		return comparisons;
	}
	public long getMoves() {
		return moves;
	}
	public long getElapsedTime(){
		return (System.nanoTime() - time) / 1000;
	}
}