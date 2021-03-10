import java.util.*;
import java.math.*;
import java.lang.*;
 
class Main{

	static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
    	int n=sc.nextInt();
    	int m=sc.nextInt();
    	int r=sc.nextInt();
    	r-=n*m;
    	if(r<0)System.out.println(0);
    	else {
    		BigInteger ans = new BigInteger("1");
    		 for(int i=0;i<n-1;i++) {
    			ans=ans.multiply(BigInteger.valueOf(r+n-i-1))
    				.divide(BigInteger.valueOf(i+1));
    		}
    		System.out.println(ans);
    	}
	}
}
