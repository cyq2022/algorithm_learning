package code;

import java.io.*;


public class Main4 {
	private static final int N = 100010;
	private static int q[] = new int[N];
	private static int hh = 0;
	private static int tt = -1;
	//  tt队尾插入元素  hh队头弹出元素
	private static BufferedReader reader = 
			new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		int m = Integer.parseInt(reader.readLine());
		
		while(m -- > 0)
		{
			String str[] = reader.readLine().split(" ");
			String op = str[0];
			
			if("push".equals(op))
			{
				int x = Integer.parseInt(str[1]);
				q[++tt] = x;
			}
			if("pop".equals(op))
			{
				hh++;
			}
			if("empty".equals(op))
			{
				System.out.println(
						tt < hh ? "YES" : "NO"
						);
			}
			if("query".equals(op))
			{
				System.out.println(q[hh]);
			}
		}
	}
}
