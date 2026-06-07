package assignment01;

import java.util.*;

public class Assignment04 {

	public static void main(String[] args) {
		Object[] objarr = {"1", new Integer(1), "2", "2", "3", "3", "4", "4", "4"};
		Set set = new HashSet();
		
		for(int i=0; i<objarr.length; i++) {
			set.add(objarr[i]);  // HadhSet에 objArr의 요소들을 저장한다.
			System.out.print(objarr[i] + " ");
		}
		System.out.println();
		
		System.out.println(set);		

	}

}
