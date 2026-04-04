package testProject3;

public class Assignment1_1 {

	public static void main(String[] args) {
		TV t = new TV();
		t.color = "black";
		t.power = false;
		t.channel = 7;
		t.power();
		t.channelDown();
		
		System.out.println("TV의 색상은 " + t.color + "입니다. 현재 TV 전원 상태는 " + (t.power ? "On":"Off") + " 이고, 현재 채널은 " + t.channel + "입니다.");
	}

}

//class TV {
//	String color;    // 색상
//	boolean power;   // 전원 상태(on/off)
//	int channel;     // 채널
//	
//	
//	void power() { power = !power; }   // TV를 켜거나 끄는 기능을 하는 메서드
//	void channelUp() { ++channel; }    // TV의 채널을 높이는 기능을 하는 매서드
//	void channelDown() { --channel; }  // TV의 채널을 낮추는 기능을 하는 매서드
//
//}
