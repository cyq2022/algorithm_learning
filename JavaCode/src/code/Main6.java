package code;

import java.io.*;


public class Main6 {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer st = new StreamTokenizer(br);
	
	static final int N = 1000010;
	static int n;
	static int a[] = new int[N] ;
	static int q[] = new int[N] ; // 队列 存a的下标 
	

	public static void main(String[] args)throws Exception {

		int n = readInt();
		int k = readInt();
		for(int i = 0; i < n; i ++)a[i] = readInt();
		
		int hh = 0, tt = -1;
		
		for(int i = 0 ; i < n; i++)
		{
			// 判断队头是否滑出
			if(hh <= tt && q[hh] < i - k + 1)
			{
				hh++; 
			}
			
			while(hh <= tt && a[q[tt]] >= a[i])
			{
				tt--;
			}
			q[++tt] = i;
			if(i + 1 >= k)
			{
				bw.write(a[q[hh]] + " ");
			}
		}
		
		bw.newLine();
		
		hh = 0; tt = -1;
		for(int i = 0; i < n; i++)
		{
			if(hh <= tt && q[hh] < i - k + 1) hh++;
			
			while(hh <= tt && a[q[tt]] <= a[i]) tt--;
			
			q[++tt] = i;
			
			if(i + 1 >= k) 
				bw.write(a[q[hh]] + " ");
		}
		
		
		bw.flush();
		br.close();
		bw.close();
	}
	
	static int readInt() throws IOException {
		st.nextToken();
		return (int)st.nval;
	}
}
