#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int fp = open ("file.txt", O_RDWR);
    char buf [256];
    int s = read (fp, buf, sizeof (buf));
    int charc, wordc, linec;
    charc=wordc=linec=0;
    int i;
    for (i=0; i<s; i++)
    {
        if (buf[i]==' ')
            wordc++;
        else if (buf [i]=='\n')
        {
            wordc++;
            linec++;
        }
        else
            charc++;
    }
    printf ("%d\t%d\t%d\n", charc, wordc, linec);
}