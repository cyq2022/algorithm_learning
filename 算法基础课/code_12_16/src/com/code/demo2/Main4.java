package com.code.demo2;
import java.io.*;

class ReadAndWrite {
    // 读入对象
    // 快速读入对象
    StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    // 字符串快速读入对象
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // 快速输出对象
    PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    // 读入整数
    public int readInt() {
        try {
            st.nextToken();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return (int) st.nval;
    }

    // 读入长整型整数
    public long readLong() {
        try {
            st.nextToken();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return (long) st.nval;
    }

    // 读入浮点数
    public double readDouble() {
        try {
            st.nextToken();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return st.nval;
    }

    // 读入字符串
    public String readString1() {
        String s = null;
        try {
            s = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return s;
    }

    public String readString2() {
        try {
            st.nextToken();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return st.sval;
    }

    public static void main(String[] args) {



        ReadAndWrite readAndWrite = new ReadAndWrite();
        // 读入整数
        int i = readAndWrite.readInt();
        readAndWrite.out.println(i);
        // 将缓冲区的数据刷新
        // 只有将缓冲区的数据进行刷新，才会在控制台进行输出
        readAndWrite.out.flush(); // 一定要写否则数据不会真正输出
        // 读入长整数
        long l = readAndWrite.readLong();
        readAndWrite.out.println(l);
        // 读入浮点数
        double d = readAndWrite.readDouble();
        readAndWrite.out.println(d);
        // 读入字符串
        String s = readAndWrite.readString1();
        readAndWrite.out.println(s);
        s = readAndWrite.readString2();
        readAndWrite.out.println(s);
        readAndWrite.out.flush();
    }
}
