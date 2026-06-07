package assignment01;

import java.util.*;

public class Assignment06 {

	public static void main(String[] args) {
		LinkedList list = new LinkedList();  // LinkedList 생성 (기본요소 크기 제한 없음)
		// 1. 요소 추가하기
		list.add("111");  // void add(Object obj)
		list.add("222");
		list.add("333");
		list.add("222");  // 중복 요소 추가 가능
		list.add(333);    // 오토박싱: list.add(new Integer(333));
		System.out.println(list);  // 출력: [111, 222, 333, 222, 333]
		// 2. 특정 인덱스에 삽입하기
		list.add(0, "000");  // void add(int index, Objecr obj)
		System.out.println(list);  // 출력: [000, 111, 222, 333, 222, 333]
		// 3. 요소 위치 찾기
		System.out.println("index=" + list.indexOf("333"));  // 출력: index=3
		// 4. 값으로 요소 삭제하기
		list.remove("333");  // 첫번째로 만나는 "333"을 삭제하고 true 반환
		System.out.println(list);  // 출력: [000, 111, 222, 222, 333]
		// 5. 요소를 전부 인덱스 번호 문자열로 변경하기
		for(int i=0; i<list.size(); i++) {
			list.set(i,  i+"");  // Object set(index, Object obj)
		}
		// 6. 하나씩 꺼내서 출력하기
		System.out.print("{");
		for(int i=0; i<list.size(); i++) {
			System.out.print(list.get(i) + ", ");  // Object get(int index)
		}
		System.out.println("}");
		// 7. 인덱스로 삭제하기(주의: 루프 안에서 내부 size가 줄어듦)
		for(int i=list.size()-1; i>=0; i--) {
			list.remove(i);  // Object remove(int index)
		}
		System.out.println(list);

	}

}
