// Example 09-01

#include <stdio.h>
#define STACK_MAX 100

typedef int Item;

typedef struct stack {
   Item *bottom;
   unsigned int num;
} Stack;

Stack init(Item *arr);

void printItem(Item item);
void print(Stack *s);

void push(Stack *s, Item data);
Item pop(Stack *s);

int main(void) {
   Item stackArr[STACK_MAX];
   Stack stk = init(stackArr);
   
   print(&stk);
   push(&stk, 100);
   print(&stk);
   push(&stk, 200);
   print(&stk);
   push(&stk, 300);
   print(&stk);
   push(&stk, 400);
   print(&stk);
   printItem(pop(&stk));
   print(&stk);
   printItem(pop(&stk));
   print(&stk);
   push(&stk, 500);
   print(&stk);
   printItem(pop(&stk));
   print(&stk);
   printItem(pop(&stk));
   print(&stk);
   printItem(pop(&stk));
   print(&stk);
   
   return 0;
}

Stack init(Item *arr) {
   Stack stk;
   stk.bottom = arr;
   stk.num = 0;
   return stk;
}

void printItem(Item item) {
   printf("%d",(int)item);
}

void print(Stack *s) {
   printf("[");
for(int i=0;i<(s->num);i++){
    printItem(*(s->bottom + i));
}
   printf("\n");
}

void push(Stack *s, Item data) {
   Item* top = s->bottom + s->num;
   *top =data;
}

Item pop(Stack *s) {
   if (s->num > 0) {
      Item* top = s->bottom + s->num -1;
      s->num--;
      return *top;
   }
   return -1; // スタックが空の場合
}