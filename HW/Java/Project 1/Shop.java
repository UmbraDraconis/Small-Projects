import java.util.TreeMap;
import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;

public class Shop{
	public class Item{
		private String name;
		private double price;
		
		public Item(String name, double price){
			this.name = name;
			this.price = price;
		}
		
		public String getName(){
			return name;
		}
		public double getPrice(){
			return price;
		}
		public String toString(){
			return String.format("%12s %10.2f\n", getName(), getPrice());
		}		
	}
	
	TreeMap<String, ArrayList<Item>> shoppingCart = new TreeMap<>();
	TreeMap<String, Item> inventory = new TreeMap<>();
	
	// This method adds item to the inventory from the input file.
	public void addInventory(String name, double price) {
		inventory.put(name, new Item(name, price));
	}
	// This method adds an item to the shopping cart of a customer.
	public void add(String name, String itemName) {
		if(shoppingCart.containsKey(name) == false)
			shoppingCart.put(name, new ArrayList<Item>());
		shoppingCart.get(name).add(new Item(itemName, inventory.get(itemName).getPrice()));
		System.out.println("Added " + itemName + " to " + name + "'s cart.\n");
	}
	// This method deletes an item from the shopping cart of a customer
	public void delete(String name, String itemName) {
		if(shoppingCart.containsKey(name)) {
			Item tempItem = new Item(itemName, inventory.get(itemName).getPrice());
			if(shoppingCart.get(name).contains(tempItem)) {
				for(int j = 0; j < shoppingCart.get(name).size(); j++) {
					if(shoppingCart.get(name).equals(tempItem))
						shoppingCart.get(name).remove(j);
				}
				System.out.println("Deleted " + itemName +" from " + name + "'s cart.\n");
			}
		} else
			System.out.println(itemName + " was not found in " + name+ "'s cart.\n");
	}
	// This method views the items that are located in the shopping cart of a customer.
	public void view(String name) {
		if(shoppingCart.containsKey(name)) {
			System.out.println(name + " views " + name + "'s cart.\n");
			System.out.printf("%12s %10s\n", "Item Name", "Item Price");
			for(int j = 0; j < shoppingCart.get(name).size(); j++) {
				System.out.printf("%12s $%10.2f\n", shoppingCart.get(name).get(j).getName(), shoppingCart.get(name).get(j).getPrice());
			}
			System.out.println();
		} else
			System.out.println("There is no cart for " + name + ".\n");
	}
	// This method sums up the price of all the items in the cart and removes the cart from the TreeMap.
	public void checkout(String name) {
		if(shoppingCart.containsKey(name)) {
			double sum = 0;
			System.out.println(name + " checkout " + name + "'s cart.\n");
			System.out.printf("%12s %10s\n", "Item Name", "Item Price");
			for(int j = 0; j < shoppingCart.get(name).size(); j++) {
				System.out.printf("%12s $%10.2f\n", shoppingCart.get(name).get(j).getName(), shoppingCart.get(name).get(j).getPrice());
				sum = sum + shoppingCart.get(name).get(j).getPrice();
			}
			System.out.printf("\n%11s: $%10.2f\n\n", "SubTotal", sum);
			shoppingCart.remove(name);	
		} else System.out.println("There is no cart to check out.\n");
	}
	
	public static void main(String[] args) throws IOException {
		if(args.length < 2) argsExit();
		Scanner itemFile = new Scanner(new File(args[0]));
		Scanner orderFile = new Scanner(new File(args[1]));
		
		Shop shop = new Shop();
		
		while(itemFile.hasNextLine()){
			String itemName = itemFile.next();
			String itemPrice = itemFile.next().replace("$", "");
			shop.addInventory(itemName, Double.parseDouble(itemPrice));
		}
		itemFile.close();
		
		while(orderFile.hasNext()){
			String order = orderFile.next();
			String customer = orderFile.next();
			switch(order){
				case "add":
					shop.add(customer, orderFile.next());
					break;
				case "delete":
					shop.delete(customer, orderFile.next());
					break;
				case "view":
					shop.view(customer);
					break;
				case "checkout":
					shop.checkout(customer);
					break;
				default:
					System.out.println("Tested wrongly");
					break;
			}
		}
		orderFile.close();
		
		System.exit(0);
	}
	
	public static void argsExit(){
		System.out.println("java Shop (itemFile) (orderfile)");
		System.exit(0);
	}
}