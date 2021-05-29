#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

double randth(){
    double r = rand()/(double) RAND_MAX;

    return r;
}

int main(void){
    int n;
    scanf("%d",&n);
    printf("n=%d\n",n); //nの読み込み

    int count = 0;   //countの初期化

    double x ,y;
    srand((unsigned int)time(NULL));  //疑似乱数

    double pai;

    double f =4;

    for(int i=0; i<n; i++){
        x=randth();
        y=randth();
        x=pow(x,2);
        y=pow(y,2);
        if(sqrt(x+y)<=1){
            count++; //√x^2+y^2が１以上だったらカウントを+1
        }
   }
   pai = f*count/n;
    
    printf("PI=%f\n",pai);
    return 0;
}