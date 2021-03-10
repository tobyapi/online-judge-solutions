import java.lang.*;
import java.util.*;

class Now {
	private static Now singleton = null;
	private static int id;
	private static String exp;

	private Now() {
		id = 0;
	}

	private Now(String exp) {
		this.exp = exp;
		id = 0;
	}

	public static synchronized void initialize(String exp) {
		singleton = new Now(exp);
	}

	public static synchronized Now getInstance() {
		if(singleton == null){
			singleton = new Now();
		}
		return singleton;
	}

	public static int getId() {
		return id;
	}

	public static String getExp() {
		return exp;
	}

	public static int plusId() {
		id++;
		return id;
	}
}


interface Parser {
	public int parse();
}

class Expression implements Parser{

	public int parse(){
		int res = new Term().parse();

		while(true){
			char now = Now.getExp().charAt(Now.getId());
			
			if(now == '+') {
				Now.plusId();
				res += new Term().parse();
			}
			else if(now == '-') {
				Now.plusId();
				res -= new Term().parse();
			}
			else {
				break;
			}
		}

		return res;
	}
}

class Term implements Parser {

	public int parse(){
		int res = new Factor().parse();
		while(true) {
			char now = Now.getExp().charAt(Now.getId());

			if(now == '*') {
				Now.plusId();
				res *= new Factor().parse();
			}
			else if(now == '/') {
				Now.plusId();
				res /= new Factor().parse();
			}
			else {
				break;
			}
		}

		return res;
	}
}

class Factor implements Parser {

	public int parse() {
		int res=0;
		char now = Now.getExp().charAt(Now.getId());

		if(now == '(') {
			Now.plusId();
			res = new Expression().parse();
			Now.plusId();
		}
		else {
			return new Number().parse();
		}

		return res;
	}
}

class Number implements Parser {

	public int parse() {
		int res = 0;
		String exp = Now.getExp();

		while(true) {
			char now = exp.charAt(Now.getId());
			if(!Character.isDigit(now))break;

			res *= 10;
			res += Character.digit(now,10);
			
			Now.plusId();
		}

		return res;
	}
}

public class Main {

	public void solve() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String exp;
		exp = sc.nextLine();

		for(int i=0;i<n;i++) {
			exp = sc.nextLine();
			Now.initialize(exp);
			System.out.println(new Expression().parse());	
		}
	}

	public static void main(String[] args) {
		Main problem_0109 = new Main();
		problem_0109.solve();
	}
}
