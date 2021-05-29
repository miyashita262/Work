#include<stdio.h>
#include<math.h>
#define PI 3.14159265389793

double deg2rad(double deg){
    double s = 0;
    s = deg *(PI/180);
    return s;
}
double deg_sin(double deg){
    double d = 0;
    d= sin(deg*PI/180);
    return d;
}
double deg_cos(double deg){
    double z = 0;
    z= cos(deg*PI/180);
    return z;
}

int main(void){
    double deg[]={0,45,90,120,180,-90,-120};
    int n = sizeof(deg)/sizeof(deg[0]);

    for(int i=0; i<n; i++){
        printf("%.1f[deg] = %f[rad]\n",deg[i],deg2rad(deg[i]));
        printf("sin(%.1f[deg])=%f,cos(%.1f[deg])=%f\n\n",deg[i]
        ,deg_sin(deg[i]),deg[i],deg_cos(deg[i]));
    }
    return 0;
}




    
        



