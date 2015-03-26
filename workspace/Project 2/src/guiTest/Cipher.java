package guiTest;
import java.util.Scanner;

public class Cipher {
	
	private String cText;
	private String pText;
	
	public void encrypt(String plainText, String key) {
		final int plainSize = plainText.length();
		final int keySize = key.length();
		final StringBuilder cipherText = new StringBuilder(plainSize);
		
		for(int i = 0; i < plainSize; i ++) {
			cipherText.append((char)((plainText.charAt(i) + key.charAt(i % keySize)) % 26));
		}
		cText = cipherText.toString();
	}
	
	public void decrypt(String cipherText, String key) {
		final int cipherSize = cipherText.length();
		final int keySize = key.length();
		final StringBuilder plainText = new StringBuilder(cipherSize);
		
		for(int i = 0; i < cipherSize; i++) {
			plainText.append((char)((cipherText.charAt(i) - key.charAt(i % keySize) % 26)));
		}
		
		pText = plainText.toString();
	}
	
	public String getCipher() {
		return cText;
	}
	
	public String getPlain() {
		return pText;
	}
	
	public static void main(String[] args) {
		Cipher c = new Cipher();
		Scanner kb = new Scanner(System.in);
		String input1, input2, result;
		
		System.out.println("PlainText: ");
		input1 = kb.nextLine();
		System.out.println("Key");
		input2 = kb.nextLine();
		
		c.encrypt(input1, input2);
		result = c.getCipher();
		
		System.out.println("Cipher: " + result);
		
		System.out.println("CipherText: ");
		input1 = kb.nextLine();
		System.out.println("Key");
		input2 = kb.nextLine();
		
		c.decrypt(input1, input2);
		result = c.getPlain();
		System.out.println("Plain: " + result);
	}
}
