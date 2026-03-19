package testProject2;

import java.io.IOException;

public class Test2 {

	public static void main(String[] args) {		
		/*
		int n = 5;
		for(int i=1; i<=n; i++)
		{
			for(int j=n; j>i; j--)
			{
				System.out.print(" ");
			}
			for(int j=1; j<=i; j++)
			{
				System.out.print("*");
			}
			System.out.println("");
		}
		*/
		
		/*
		int input = 0;
		
		System.out.println("문장을 입력하세요.\n입렵을 마치려면 x를 입력하세요.");
		do {
			try {
				input = System.in.read();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println((char)input);
		} while(input!=-1 && input!='x');
		System.out.println("end");
		*/
		
		
		Loop1: for(int i=2; i<=9; i++)
		{
			for(int j=1; j<=9; j++)
			{
				if(j==5)
					break Loop1;
				System.out.println(i+ "*" + j + "=" + i*j);
			}
			System.out.println("");
		}
	}
}
