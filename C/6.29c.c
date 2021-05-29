#include <stdio.h>

 

int main(void){

              FILE *fp;

              if ((fp = fopen("Test01.txt", "a"))==NULL)

                            return -1;

              fputs("\nNational Institute of Technology", fp);

              fclose(fp);

              return 0;

}