package code;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main3 {
	
	private static final int N = (int)1e5 + 10;
	private static int s[] = new int[N];
	private static int tt = 0;
	private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	
	private static void push(int x) 
	{
		s[++tt] = x;
	}
	
	private static void pop()
	{
		tt--;
	}
	
	private static boolean empty()
	{
		return tt == 0;
	}
	
	private static int query()
	{
		return s[tt];
	}
	
	
	public static void main(String[] args)  throws Exception
	{
		String op = null;
		int m = Integer.parseInt(reader.readLine());

		while( m-- > 0)
		{
			String str[] = reader.readLine().split(" ");
			op = str[0];
			
			switch(op)
			{
			case "push" :
				push(Integer.parseInt(str[1]));
				break;
			case "pop" :
				pop();
				break;
			case "empty" :
				System.out.println(empty() ? "YES" : "NO");
				break;
			case "query" :
				System.out.println(query());
				break;
			}
		}
	}
}
