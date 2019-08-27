#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int fp;
    fp = creat("file.txt",O_RDWR);
    if (fp<0)
    {
        perror ("Error");
        exit (1);
    }
    char buff[50];
    printf("enter text:\n");
    gets(buff);
    write(fp,buff,strlen(buff));
    close(fp);
}