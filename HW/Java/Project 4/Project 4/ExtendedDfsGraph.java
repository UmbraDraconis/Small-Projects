import graph.*;
import java.io.*;
import java.util.ArrayList;

public class ExtendedDfsGraph extends DfsGraph {
	ArrayList<Integer> ancestor[];
	
	public ExtendedDfsGraph(String name) throws IOException{
		super(name);
		ancestor = new ArrayList[getOrder()];
	}
	public void doMarked(int v, int w) {
		if(ancestor[v] != null && ancestor[v].contains(w))
			System.out.println(getEdge(v,w) + ": back");
		else if(ancestor[w].contains(v))
			System.out.println(getEdge(v,w) + ": forward");
		else
			System.out.println(getEdge(v,w) + ": cross");
	}
	public void doUnmarked(int v, int w) {
		System.out.println(getEdge(v,w) + ": tree");
		
		ArrayList<Integer> parent = new ArrayList<>();
		parent.add(v);
		if(ancestor[v] != null)
			parent.addAll(ancestor[v]);
		ancestor[w] = parent;
	}
}