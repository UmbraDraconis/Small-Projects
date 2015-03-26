import java.util.ArrayList;
import java.io.*;

import graph.*;

public class MyDfsGraph extends Graph{
	ArrayList<Integer> ancestor[];

	public MyDfsGraph (String fileName) throws IOException{
		super(fileName);
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
	public void dfs(int v) {
		markVertex(v);
		for(int w: getNeighbors(v)) {
			if(vertexMarked(w)) {
				doMarked(v,w);
			} else {
				doUnmarked(v,w);
				dfs(w);
			}
		}
	}
	
}
