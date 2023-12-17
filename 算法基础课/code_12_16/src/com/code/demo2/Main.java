package com.code.demo2;

import java.util.Scanner;
public class Main{
    static int[] e = new int[100010];
    static int[] ne = new int[100010];
    static int idx,head;
    public static void init(){
        idx = 0;
        head = -1;
    }
    //H向链表头插入一个数x；
    public static void add_head(int x){
        e[idx] = x;
        ne[idx] = head;
        head = idx++;
    }
    //I在第k位数后面插入一个数x
    public static void add(int k,int x){
        e[idx] = x;
        ne[idx] = ne[k];
        ne[k] = idx++;
    }
    //D删除第k个数后面得数
    public static void remove(int k){
        ne[k] = ne[ne[k]];
    }
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int m = scan.nextInt();

        init();
        while(m -- > 0){
            //因为java中没有输入一个字符，所以用字符串转字符
            String s = scan.next();
            char op = s.charAt(0);

            if(op == 'H'){
                int x = scan.nextInt();
                add_head(x);
            }else if(op == 'D'){
                int k = scan.nextInt();
                if(k == 0) head = ne[head];
                else remove(k-1);
            }else {
                int k = scan.nextInt();
                int x = scan.nextInt();
                add(k-1,x);
            }
        }
        for(int i = head;i != -1;i = ne[i] ){
            System.out.print(e[i] +  " ");
        }

    }

}

