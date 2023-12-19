package com.code.demo2;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main1 {

    private static final int N = 100010;
    private static int e[] = new int[N];
    private static int l[] = new int[N];
    private static int r[] = new int[N];
    private static int idx;


    private static void init() {
        r[0] = 1;
        l[1] = 0;
        idx = 2;
    }

    private static void insertL(int x) {
        e[idx] = x;
        r[idx] = r[0];
        l[idx] = 0;
        l[r[0]] = idx;
        r[0] = idx;
        idx++;
    }

    private static void insertR(int x) {
        e[idx]  = x;
        r[idx] = r[l[1]];
        l[idx] = l[1];
        r[l[1]] = idx;
        l[1] = idx;
        idx ++;
    }

    public static void delete(int k) {
        r[l[k]] = r[k];
        l[r[k]] = l[k];
    }

    public static void insertK(int k,int x) {
        e[idx] = x;
        l[idx] = k;
        r[idx] = r[k];
        l[r[k]] = idx;
        r[k] = idx;
        idx ++;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(reader.readLine());

        System.out.println(m);
        init();

        while(m-- > 0) {
            String str[] = reader.readLine().split(" ");
            String op = str[0];

            if("L".equals(op)) {
                int x = Integer.parseInt(str[1]);
                insertL(x);
            }

            if("R".equals(op)) {
                int x = Integer.parseInt(str[1]);
                insertR(x);
            }

            if("D".equals(op)) {
                int k = Integer.parseInt(str[1]);
                delete(k);
            }

            if("IL".equals(op)) {
                int k = Integer.parseInt(str[1]);
                int x = Integer.parseInt(str[2]);
                insertK(l[k + 1],x);
            }

            if("IR".equals(op)) {
                int k = Integer.parseInt(str[1]);
                int x = Integer.parseInt(str[2]);
                insertK(k + 1,x);
            }
        }

        for(int i = r[0]; i != 1; i = r[i])
            System.out.print(e[i] + " ");
    }
}

