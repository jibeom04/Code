package testProject5;

public class Test3 {

	public static void main(String[] args) {
		Buyer buyer = new Buyer();
		
		buyer.buy(new Tv());
		buyer.buy(new Computer());
		buyer.buy(new Audio());
	}

}

class Product {
	int price = 0;
	int bounsPoint = 0;
}

class Tv extends Product {
	public Tv() {
		price = 100;
		bounsPoint = 2;
	}
}

class Computer extends Product {
	public Computer() {
		price = 100;
		bounsPoint = 3;
	}
}

class Audio extends Product {
	public Audio() {
		price = 50;
		bounsPoint = 1;
	}
}

class Buyer {
	int money = 1000;
	int bounsPoint = 0;
	
	void buy(Product p) {
		this.money -= p.price;
		this.bounsPoint += p.bounsPoint;
		System.out.println("money: " + this.money + " bounsPoint: " + this.bounsPoint);
		
	}
}