import java.util.*;

public class P1{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String str = in.nextLine();
		while (n-->0){
			str = in.nextLine();
			for (char i=0;i<str.length();++i){
				char c = str.charAt(i),d=c;
				if (c>='a' && c<='z'){
					d = (char)(((int)c-(int)'a' + 1)%26 + (int)'a');
				}else if (c>='A' && c<='Z'){
					d = (char)(((int)c-(int)'A'+1)%26 + (int)'A');
				}
				System.out.print(d);
			}
			System.out.println();
		}
		in.close();
	}
}