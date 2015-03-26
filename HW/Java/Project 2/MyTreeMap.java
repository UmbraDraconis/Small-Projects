/**
 *	TreeMap implemented as Binary Search Tree
 */
import java.util.Set;

public class MyTreeMap<K extends Comparable<K>,V> {
	private BinaryTree<Element> map;
	private Set<K> keys;  // to return keys in order
	private int size;
		
	public boolean containsKey(K key) {
		if (key == null)
			throw new NullPointerException();
		return keys.contains(key);
	}
	public V put(K key, V value) {
		BinaryTree<Element> node = map.getRoot(), parent;
		if (node == null) {
			map = new BinaryTree<Element>(new Element(key, value));
			keys = new TreeSet<K>();
		}
		else {
			if (
		}
		
		keys.add(key);
		size++;
		return value;
	}
	public V get(K key) {
		BinaryTree<Element> p = getNode(key);
		return (p == null ? null : p.getValue());
	}
	final BinaryTree<Element> getNode(K key) {
		BinaryTree<Element> p = map.getRoot();
		while (p != null) {
			int cmp = key.compareTo(p.key);
			if (cmp < 0)
				p = p.getLeft();
			else if (cmp > 0)
				p = p.getRight();
			else return p;
		}
		return null;
	}
	public V remove(K key)
	public int size() {
		return size;
	}
	public int height() {
		return height(map);
	}
	public String toString() {
		return key + "=" + value;
	}
	public Set<K> keySet() {
		return keys;
	}

// Element class
	private class Element
	{
		private K key;
		private V value;
		
		public Element(K key, V value) {
			this.key = key;
			this.value = value;
		}
		public K getKey() {
			return key;
		}
		public V getValue() {
			return value;
		}
		public int compareTo(Element that) {
			return (this.key).compareTo(that.key);
		}
		
		public String toString() {
			return "[" + key + "," + value + "]";
		}
	}
	
// private methods implementing BST operations search, insert, delete, inorder
// reference: http://en.wikipedia.org/wiki/Binary_search_tree
//
	private Element search(Element element, BinaryTree<Element> tree) {
		if(tree == null || tree.getKey() = element.getKey())
			return tree;
		else if (element.getKey() < tree.getKey())
			return search(element, tree.getLeft());
		else if (element.getKey() > tree.getKey())
			return search(element, tree.getRight());
	}
	private Element insert(Element element)
	private Element insert(Element element, BinaryTree<Element> tree)
	private Element delete(BinaryTree<Element> tree, Element element, BinaryTree<Element> parent)
// make newChild the appropriate (left or right) child of parent, if parent exists
	private void promote(BinaryTree<Element> tree, BinaryTree<Element> parent, BinaryTree<Element> newChild)
	private void inorder(BinaryTree<Element> tree)
	private int height(BinaryTree<Element> tree) {
		if (node == null)
			return 0;
		else
			return 1 + Math.max(height(node.getLeft()), height(node.getRight));
	}