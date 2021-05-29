#include <stdio.h>
#define N 100

typedef struct
{
    int id;
    char name[20];
    int kokugo, sansu, rika;
}SEISEKI;

int main(void)
{
    SEISEKI seiseki[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &seiseki[i].id);
        if (seiseki[i].id < 0)
        {
            break;
        }
        scanf("%s", seiseki[i].name);
        scanf("%d", &seiseki[i].kokugo);
        scanf("%d", &seiseki[i].sansu);
        scanf("%d", &seiseki[i].rika);
    }

    int n = 0;
    int kokugo = 0;
    int sansu = 0;
    int rika = 0;
    for (int i = 0; seiseki[i].id >= 0 && i<100; i++)
    {
        printf("%d: %s %d\n", seiseki[i].id, seiseki[i].name, (seiseki[i].kokugo + seiseki[i].sansu + seiseki[i].rika) / 3);
        n++;
        kokugo += seiseki[i].kokugo;
        sansu += seiseki[i].sansu;
        rika += seiseki[i].rika;
    }
    printf("kokugo = %d\n", kokugo / n);
    printf("sansu = %d\n", sansu / n);
    printf("rika = %d\n", rika / n);

    return 0;
}