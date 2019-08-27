#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int fp1 = creat ("f2.txt", O_RDWR);
    int fp2 = open ("file.txt", O_RDWR);
    char buf1[256];
    int s = read (fp2, buf1, sizeof (buf1));
    if (s<0)
    {
        perror ("error");
        exit (1);
    }
    s = write (fp1, buf1, s);
    close (fp1);
    close (fp2);
}