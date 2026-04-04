package testProject3;

public class Assignment3_2 {

	public static void main(String[] args) {
		MyMath mm = new MyMath();
		System.out.println("mm.add(3, 3) 결과: " + mm.add(3, 3));
		System.out.println("mm.add(3L, 3) 결과: " + mm.add(3L, 3));
		System.out.println("mm.add(3, 3L) 결과: " + mm.add(3, 3L));
		System.out.println("mm.add(3L, 3L) 결과: " + mm.add(3L, 3L));
		
		int[] a = {100, 200, 300};
		System.out.println("mm.add(a) 결과: " + mm.add(a));
	}
	
}

class MyMath {
	int add(int a, int b) {
		System.out.print("int add(int a, int b) - ");
		return a+b;
	}
	long add(int a, long b) {
		System.out.print("long add(int a, long b) - ");
		return a+b;
	}
	long add(long a, int b) {
		System.out.print("long add(long a, int b) - ");
		return a+b;
	}
	long add(long a, long b) {
		System.out.print("long add(long a, long b) - ");
		return a+b;
	}
	int add(int[] a) {
		System.out.print("int add(int[] a) - ");
		int result = 0;
		for(int i=0; i<a.length; i++) {
		result += a[i];
		}
		return result;
	}
}

/*
오버로딩: 하나의 클래스에 같은이름의 메서드를 여러개 정의하는것
조건
 - 메서드 이름이 같아야함
 - 매개변수의 타입 또는 개수가 달라야함 ( 변수의 이름만 다른것은 성림하지 않음 )
   ex) int sum(int a, int b) { return a + b }  << 변수의 타입과 개수는 같고 변수의 이름만 다르므로 메서드 오버로딩이 아님
       int sum(int x, int y) { return x + b }
   ex) int sum(int a, int b) { return a + b }  << 변수의 타입이 다르므로 메서드 오버로딩 조건 성립
       long sum(long a, long b) { return a + b; }
 - 매개변는 같고 리턴타입이 다른 경우는 성립하지 않음
   ex) int sum(int a, int b) { return a + b; }
       long sum(int a, int b) { return (long)(a + b); }
 - 같은기능을 하지만 처리하는 자료형이나 개수가 다를떄 메서드 오버르딩을 사용 ( ex: println )
*/