#include<stdio.h>

int main(void){
    int i;
    int w;
    int s;
    int j;
    int k;
    int g;

    char str[] ="abcDEFghi";

    
    for(i = 0; i <=8 ; i++){
        if(str[i] >= 97 && str[i] <= 122){
        s= str[i] - 32;
        printf("%c",s);
        }
        else if(str[i] >=65 && str[i] <=90) {
        printf("%c",str[i]);
        }      
    }
    printf("\n");
    for(i = 0; i <=8 ; i++){
        if(str[i] >= 65 && str[i] <= 90){
        k= str[i] + 32;
        printf("%c",k);
        }
        else if(str[i] >=97 && str[i] <=122) {
        printf("%c",str[i]);
        }
    }
    printf("\n");
    for(i = 0; i <=8 ; i++){
        if(str[i] >= 97 && str[i] <= 122){
        w = str[i] - 32;
        printf("%c",w);
        }
        else if (str[i] >=65 && str[i] <=90){
        s= str[i] + 32;
        printf("%c", s);
        }
    }
    
    return 0;
}
