/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;


class Main
{
	public static void main (String[] args) 
	{
		Scanner cin = new Scanner (System.in);
		BigInteger dp[] = new BigInteger[1003];
		
		dp[0] = BigInteger.ONE;
		dp[1] = BigInteger.valueOf(2);
		dp[2] = BigInteger.valueOf(5);
		dp[3] = BigInteger.valueOf(13);
			
			for(int i=4; i<1002; i++)
			{
				dp[i] = BigInteger.valueOf(2).multiply(dp[i-1]).add(dp[i-2]).add(dp[i-3]);
			}
			
			int n;
			
			while(cin.hasNext())
			{
				
				n = cin.nextInt();
				System.out.println(dp[n]);
			}
	}
	
		
}