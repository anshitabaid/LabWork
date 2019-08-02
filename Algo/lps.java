import java.util.*;
class lps
{

	static int findlps (String s, int m[][], int a, int b)
	{
		if (a<=0 || b<=0)
			return 0;
		if (a==b)
			return 1;
		if (s.charAt (a-1)==s.charAt(b-1))
		{
			m[a][b]=2+findlps (s, m, a+1, b-1);
		}
		else
		{
			m[a][b]=Math.max (findlps(s, m, a+1, b), findlps (s, m, a, b-1));

		}

		return m[a][b];
	}

	public static void main (String args [])
	{
		Scanner sc = new Scanner (System.in);
		String s = "bbabcbcab";
		int l = s.length();
		int i, j;
		int m[][]=new int[l+1][l+1];
		for (i=1; i<=l; i++)
			m[i][i]=1;
		int res = findlps (s, m, 1,l);
		System.out.println (res);

	}
}