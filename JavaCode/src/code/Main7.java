package code;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

/**
 * kmp
 * @author JiangYa
 *
 */
public class Main7 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		//PrintWriter pw  = new PrintWriter(new OutputStreamWriter(System.out));
		StringBuilder  sb = new StringBuilder();
		
		/**
		 * 模式串
		 */
		int n = Integer.parseInt(br.readLine());
		String ps = br.readLine();
		char p[] = new char[n + 1];
        for (int i = 0; i < ps.length(); i++) {
            p[i+1] = ps.charAt(i);
        }
//		String str = " " + br.readLine();
//		char p[] = str.toCharArray();
//		
        
		/**
		 *  模板串
		 */
		int m = Integer.parseInt(br.readLine());
		String ss = br.readLine();
		char s[] = new char[m + 1];
        for (int i = 0; i < ss.length(); i++) {
            s[i+1] = ss.charAt(i);
        }
//		str = " " + br.readLine();
//		char s[] = str.toCharArray();  

		/**
		 * next数组
		 */
		int ne[] = new int[m]; 
		
		/**
		        构建next数组
		 */
		for(int i = 2,j = 0; i <= n; i ++)
		{
			while(j > 0 && p[i] != p[j + 1]) j = ne[j];
			
			if(p[i] == p[j + 1]) j++;
			
			ne[i] = j;
		}

		/**
		 * 匹配字符串
		 */
		for(int i = 1,j = 0; i <= m ; i ++)
		{
			while(j > 0 && s[i] != p[j + 1]) j = ne[j];
			
			if(s[i] == p[j + 1]) j++;
			
			if(j == n)
			{
				sb.append(i - j  + " ");
				//bw.write(i - j  + " ");
				j = ne[j];
			}
		}
		
		bw.write(sb.toString());
		bw.flush();
	}
}
