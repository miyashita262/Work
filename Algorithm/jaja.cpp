#include <iostream>
using namespace std;

// 入力
long long N;

// cur: 現在の値、use: 7, 5, 3 のうちどれを使ったか, counter: 答え
void func(long long cur, int use, long long &counter)
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
    cin >> N;
    long long res = 0;
    func(0, 0, res);
    cout << res << endl;
}