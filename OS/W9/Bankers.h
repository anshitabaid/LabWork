#include <stdlib.h>
typedef struct bankersds
{
	int * available;
	int ** max;
	int ** allocation;
	int ** need;	
}*  BankersDs;

BankersDs init (int n, int m)
{
	BankersDs ds = (BankersDs)malloc(sizeof (struct bankersds));
	ds->available = (int *)calloc (m, sizeof (int));
	(ds->max) = (int **)calloc (n, sizeof (int));
	(ds->allocation) = (int **)calloc (n, sizeof (int));
	(ds->need) = (int **)calloc (n, sizeof (int));
	for (int i = 0; i<m; i++)
	{
		ds->max[i]=(int *)calloc (m, sizeof (int));
		ds->allocation[i]=(int *)calloc (m, sizeof (int));
		ds->need[i]=(int *)calloc (m, sizeof (int));
	}
	return ds;

}