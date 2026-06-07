package assignment01;

import java.util.*;

public class Assignment05 {

	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		list.add("111");  // void add(Object obj)
		list.add("222");
		list.add("333");
		list.add("222");  // 중복 요소 추가 가능
		list.add(333);  // List.add(new Integer(333);
		System.out.println(list);
		
		list.add(0, "000");  // void add(int index, Object obj)
		System.out.println(list);
		
		System.out.println("index=" + list.indexOf("333"));
		
		list.remove("333");
		System.out.println(list);
		
		System.out.println(list.remove("333"));
		System.out.println(list);
		System.out.println("index=" + list.indexOf("333"));
		
		for(int i=0; i<list.size(); i++) {
			list.set(i,  i+"");  // Object set(int index, Object obj)
		}
		
		System.out.print("{");
		for(int i=0; i<list.size(); i++) {
			System.out.print(list.get(i) + ", ");  // Object get(int index)
		}
		System.out.println("}");
		
		for(int i=list.size()-1; i>=0; i--) {
			list.remove(i);  // Object remove(int index)
		}
		System.out.println(list);
		
	}

}
