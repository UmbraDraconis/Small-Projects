/**
 * Chapter 2 of CS 141 book
 */

/**
 * @author Dknight
 *
 */
import javax.swing.JOptionPane;
public class C2 {
	public static void main(String[] args) {
		JOptionPane.showMessageDialog(null, "Hello World");
		String name = JOptionPane.showInputDialog("What is your first name: ");
		JOptionPane.showMessageDialog(null, name);
	}
}
