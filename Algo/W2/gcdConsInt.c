#include <stdio.h>

int main ()
{
	int m, n, t;
	scanf ("%d", &m);
	scanf ("%d", &n);
	if (m<n)
	{
		t=m; m=n; n=t;
	}
	t = n;
	int opcount=0;
	while (t>0)
	{
		opcount++;
		if (m%t==0)
			if (n%t==0)
				break;
		t--;
	}
	if (t==0)	t=m;
	printf ("GCD: %d\nOpcount: %d\n", t, opcount);
}