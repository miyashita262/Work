#include <stdio.h>

 

int main(void){

              FILE *fp;

              char buf[256];

 

              if ((fp = fopen("Test01.txt", "r"))==NULL)

                            return -1;

 

              while(fgets(buf, 256, fp) != NULL) {

                            printf("%s", buf);

              }

              fclose(fp);

              return 0;

}