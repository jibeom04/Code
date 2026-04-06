package testProject3;

public class Assignment1_1 {

	public static void main(String[] args) {
		TV t = new TV();
		t.color = new String("Black");
		t.power = false;
		t.channel = 20;
		t.volume = 50;
		t.power();
		t.channelDown();
		t.volumeUp();
		
		System.out.println(t.color);
		System.out.println(t.power ? "On":"Off");
		System.out.println(t.channel);
		System.out.println(t.volume);
	}

}

class TV {
	String color;                      // 색상
	boolean power;                     // 전원 상태
	int channel;                       // 채널
	int volume;                        // 소리 크기
	final int MAX_VOLUME = 100;        // 최대 소리 크기
	final int MIN_VOLUME = 0;          // 최소 소리 크리
	
	
	void power() { power = !power; }              // TV를 켜거나 끄는 기능을 하는 메서드
	void channelUp() { ++channel; }               // TV의 채널을 높이는 기능을 하는 매서드
	void channelDown() { --channel; }             // TV의 채널을 낮추는 기능을 하는 매서드
	void volumeUp() {                             // TV의 소리를 높이는 기능을 하는 매서드(100 미만일떄)
		if(volume >= MAX_VOLUME) { return; }
		++volume;
	}
	void volumeDown() {                           // TV의 소리를 낮추는 기능을 하는 매서드(0 초과일떄)
		if(volume <= MIN_VOLUME) { return; }
		--volume;
	}
}