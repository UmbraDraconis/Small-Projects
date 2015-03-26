import graph.*;
import java.io.IOException;

public class Main {

	public static void main(String[] args){
		if(args.length < 1)
			exit();
		ExtendedDfsGraph graph = null;
		try {
		graph = new ExtendedDfsGraph(args[0]);
		} catch (IOException e) {
			System.out.println(e.getMessage());
			System.exit(0);
		}
		System.out.println(graph);
		System.out.println("Edges: ");
		graph.dfs(0);
	}
	
	private static void exit() {
		System.out.println("java Main (file_name)");
		System.exit(0);
	}
}
