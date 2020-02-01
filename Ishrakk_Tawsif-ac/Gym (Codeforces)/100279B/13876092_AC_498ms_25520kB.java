import java.util.Scanner;
import java.math.BigInteger;
public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger n=in.nextBigInteger();
        BigInteger a=new BigInteger("1");
        long ans=0;
        while(a.compareTo(n)<=0){
            a=a.multiply(new BigInteger("2"));
            ans++;
        }
        System.out.println(ans);
    }
    
}