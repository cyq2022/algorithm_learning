package com.code.demo1;

import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] q = new int[n];
        for(int i = 0; i < n; i++){
            q[i] = sc.nextInt();
        }

        quickSort(q,0,n-1);
        for(int i = 0; i < n; i++){
            System.out.print(q[i] + " ");
        }
    }

    public static void quickSort(int q[],int l,int r){
        if(l >= r)return;

        int x = q[l + r >> 1], i = l - 1, j = r +  1;

        while(i < j){
            while(q[++i] < x);
            while(q[--j] > x);
            if(i < j){
                int temp = q[j];
                q[j] = q[i];
                q[i] = temp;
            }
        }

        quickSort(q,l,j);
        quickSort(q,j + 1,r);
    }

}
