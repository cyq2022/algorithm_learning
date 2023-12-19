package code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *     µ¥Á´±í
 * @author JiangYa
 *
 */
public class Main{
	
	private static final int N =100010; 
	private static int head;
	private static int[] e = new int[N];
	private static int[] ne = new int[N];
	private static int idx;
	
	private static void init() {
		head = -1;
		idx = 0;
	}
	
	private static void addToHead(int val) {
		e[idx] = val;
		ne[idx] = head;
		head = idx;
		idx++;
	}
	
	private static void remove(int k) {
		ne[k] = ne[ne[k]];
	}
	
	private static void add(int k,int val) {
		e[idx] = val;
		ne[idx] = ne[k];
		ne[k] = idx;
		idx ++;
	}
	
	public static void main(String[] args) throws Exception, IOException  {		
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		
		int m = Integer.parseInt(bufferedReader.readLine());
		
		init();
		
		while(m-- > 0) {
			String[] s = bufferedReader.readLine().split(" ");
			
			if(s[0].equals("H")) {
				int val = Integer.parseInt(s[1]);
				addToHead(val);
			}
			
			if(s[0].equals("I")) {
				int k = Integer.parseInt(s[1]);
				int val = Integer.parseInt(s[2]);
				add(k - 1,val);
			}
			
			if(s[0].equals("D")) {
				int k = Integer.parseInt(s[1]);
				
				if(k == 0) head = ne[head];
				else remove(k - 1);
			}
		}
		
		for(int i = head; i != -1; i = ne[i])
			System.out.print(e[i] + " ");
	}
}
