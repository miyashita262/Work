#include<stdio.h>

int main(void){

    int i;  /* iの定義 */

    for (i = 1; i <= 12 ; i++){
        switch (i){
        case 1: printf("%2d :Jan.",i);
            break;
        case 2: printf("%2d :Feb.",i);
            break;
        case 3: printf("%2d :Mar.",i);
            break;
        case 4: printf("%2d :Apr.",i);
            break;
        case 5: printf("%2d :May",i);
            break;
        case 6: printf("%2d :June",i);
            break;
        case 7: printf("%2d :July",i);
            break;
        case 8: printf("%2d :Aug",i);
            break;
        case 9: printf("%2d :Sept.",i);
            break;
        case 10: printf("%d :Oct.",i);
            break;
        case 11: printf("%d :Nov.",i);
            break;
        case 12: printf("%d :Dec.",i);
            break;
        }       /*　switch文 */
    putchar('\n');  /* 毎回改行する*/
    }
    return 0;
}