#include<stdio.h>

int main(void){
    int i;

    int n[] ={1980,1990,2000,2010,2015,2020,2300};
    
    for(i=0; i <= 6 ; i++){
        if(n[i] % 100 != 0 && n[i] % 4 ==0){
            printf("%d : Leap-year\n",n[i]);
        }
        else if(n[i] % 400 == 0){
            printf("%d : Leap-year\n",n[i]);
        }
        else{
           printf("%d :\n",n[i]);
        }
    }
    return 0;
}