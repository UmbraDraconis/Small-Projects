package guiTest;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Gui extends Frame /*implements ActionListener*/{
	private Label lblCount;
	private JFrame frame;
	/*private TextField tfCount;
	private Button btnCount;
	private int count = 0;*/
	
	public Gui () {
		frame = new JFrame();
		
		setLayout(new FlowLayout());
		
		setTitle("Test GUI");
		setSize(300, 200);
		setMenuBar(new MenuBar());
		/*
		lblCount = new Label("Counter");
		add(lblCount);
		
		tfCount = new TextField("0", 10);
		tfCount.setEditable(false);
		add(tfCount);
		
		btnCount = new Button("Count");
		add(btnCount);
		
		btnCount.addActionListener(this);
		*/
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		
		setVisible(true);
	}
	/*
	public void actionPerformed(ActionEvent evt) {
		++count;
		tfCount.setText(count + "");
	}*/
	public static void main(String[] args) {
		Gui g = new Gui();
	}
}
