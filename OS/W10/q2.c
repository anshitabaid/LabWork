#include <stdio.h>
#include <math.h>

int main ()
{

	int pagesize=32;
	int pageno=8;
	int pno, poff, frame, physaddr, i, framesize;
	int nbyte=(int)log2f(pagesize*pageno);
	printf ("No of bytes needed for logical address%d\n", nbyte);
	printf ("Enter frame size\t");
	scanf ("%d", &framesize);
	int addr;
	int table[pageno][2];
	printf ("Enter page no and frame no\n");
	for(i=0; i<pageno; i++)
		scanf ("%d %d", &table[i][0], &table[i][1]);
	while (1)
	{
		printf ("\nEnter logical address ");
		scanf ("%d", &addr);
		if (addr==-1)
			break;
		pno=addr/pagesize;
		poff=addr%pagesize;
		printf ("Page no:\t%d\n", pno);
		printf ("Offset:\t\t%d\n", poff);
		//search page table
		frame=-1;
		for (i=0; i<pageno; i++)
		{
			if (table[i][0]==pno)
			{
				frame=table[i][1];
				break;
			}
		}
		physaddr=frame*framesize + poff;
		printf ("Frame number:\t\t%d\n", frame);
		printf("Physical address:\t\t%d\n", physaddr);
	}
}

/*
64
0 3 1 4 2 0 3 1 4 8 5 10 6 2 7 6
*/