#include <stdio.h>
#define STACK_MAX 100

typedef int Item; //いろんな関数の引数をItem型として扱うことができる

typedef struct stack { //構造体Stack型の定義(スタックの情報を保持)
   Item *bottom;   //スタックの底（配列の先頭）のアドレス
   unsigned int num; //符号なしのデータの数＝次の格納時に入る位置(bottom+num)
} Stack;

//データ数は0だということ、先頭の場所をreturnする関数
Stack init(Item *arr) { //スタックの初期化(*arrは配列の先頭のアドレスを渡す)、スタックの先頭を引数に
   Stack stk;
   stk.bottom = arr;  //Stackのbottomがスタックの先頭(arr)だよと教える
   stk.num = 0;  //Stuckのnum(データ数の初期数)は0だよ
   return stk;
}

void printItem(Item item) {
    printf("%d ",item);
}

//Stackで先頭のアドレスは？何個データを持ってるか？
void print(Stack *s) { //*sを渡すことでスタックの中のデータをずらずらと表示
   printf("[");
   for(int i=0; i<(s->num);i++){  //num回繰り返し
       printItem(*(s->bottom +i));  //printItemは前の関数
   }
   printf("\n");
}

void push(Stack *s, Item data) {
   Item *top = s->bottom + s->num;
   *top = data;
   s->num++;
}

Item pop(Stack *s) {
   if (s->num > 0) {
     Item *top = s->bottom + s->num -1;
     s->num--;
     return *top;
   }
   return -1; // スタックが空の場合
}



int main(void) {
   Item stackArr[STACK_MAX];
   Stack stk = init(stackArr);

   print(&stk);

   int i = 1;

   while (i != 0)
   {
      scanf("%d",&i);
      if(i>0){
         push(&stk,i);
      }
      if(i<0){
         printf("%d ",pop(&stk));
      }
      print(&stk);
   }

   return 0;
}

