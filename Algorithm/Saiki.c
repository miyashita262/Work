#include <stdio.h>

long long int N;
void func(long long int cur, int use, long long int counter)
{

    if (cur > N)
        return; // ベースケース
    if (use == 0b111)
        ++counter; // 答えを増やす

    // 7 を付け加える
    func(cur * 10 + 7, use | 0b001, counter);

    // 5 を付け加える
    func(cur * 10 + 5, use | 0b010, counter);

    // 3 を付け加える
    func(cur * 10 + 3, use | 0b100, counter);
}

int main()
{
    scanf("%d", &N);
    long long int res = 0;
    func(0, 0, res);
    printf("%d", res);
}