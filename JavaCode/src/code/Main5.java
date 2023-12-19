package code;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.StreamTokenizer;


public class Main5 {
	static final int N = 100010;
	static int stk[] = new int[N];
	static int tt = 0;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st =  new StreamTokenizer(br);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		st.nextToken();
		int m = (int)st.nval;
		
		while(m -- > 0)
		{
			st.nextToken();
			int x = (int)st.nval;
			while(tt > 0 && stk[tt] >= x)
			{
				tt--;
			}
			bw.write((tt > 0 ? stk[tt] : -1 ) + " ");
			stk[++tt] = x;
		}
		
		br.close();
		bw.close();
	}
}
