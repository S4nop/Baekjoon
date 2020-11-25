package javatest;

import java.lang.System;
//import java.io.IOException;

public class Class2nd {
	public static void main(String[] args){
		System.out.print("Input demical number : ");
		try {
		int numsum = 0;
		int num = System.in.read();
		while(num != 10) {
		num -= 48;
		numsum *= 10;
		numsum += num;
		num = System.in.read();
		}
		System.out.println("Binary number : " + Integer.toBinaryString(numsum));
		System.out.println("Octal number : " + Integer.toOctalString(numsum));
		System.out.println("Hexademical number : " + Integer.toHexString(numsum));
		}catch (Exception e) {}
	}
}
