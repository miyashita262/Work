#include <stdio.h>

 

int main(void){

              FILE *fp_r, *fp_w;

              char buf[256];

 

              if ((fp_r = fopen("Test01.txt", "r"))==NULL)

                            return -1;

              if ((fp_w = fopen("Test02.txt", "w"))==NULL)

                            return -1;

             

              while(fgets(buf, 256, fp_r) != NULL) {

                            fputs(buf, fp_w);

              }

 

              fclose(fp_w);

              fclose(fp_r);

              return 0;

}