#include <stdio.h>

 

int main(void){

              FILE *fp;

              if ((fp = fopen("Test01.txt", "w"))==NULL)

                            return -1;

              fputs("Ichinoseki KOSEN!!\n3J", fp);

              fclose(fp);

              return 0;

}