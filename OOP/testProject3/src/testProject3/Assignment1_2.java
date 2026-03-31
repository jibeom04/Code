package testProject3;

public class Assignment1_2 {

	public static void main(String[] args) {
		TV t1 = new TV();
		TV t2 = new TV();
		
		t1.channel = 7;
		t2.channel = 15;
		
		System.out.println("t1.channel: " + t1.channel);
		System.out.println("t2.channel: " + t2.channel);
		
		t2 = t1;
		
		System.out.println("t1.channel: " + t1.channel);
		System.out.println("t2.channel: " + t2.channel);
	}

}
