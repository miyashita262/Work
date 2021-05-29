#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct queue {

  Item *arr;  // キューに使っている配列の先頭のアドレス
  unsigned int max_num;  // キューに使う配列の大きさ(格納可能なデータの数)
  unsigned int front;  // キューの先頭の位置(arrからの相対位置==arr[]の添字)
  unsigned int num;  // 格納されているデータの数

} Queue;

Queue init(unsigned int size) {  // キューの初期化を行う
    Queue q;
    q.max_num=size;
    q.front=0;
    q.num=0;
    q.arr=(int*)malloc(sizeof(int)*size);
    return q;
}

void fin(Queue *q) {    // キューの破棄
    free(q->arr);
    q->arr = NULL;
    q->max_num = 0;
    q->front = 0;
    q->num = 0;
}

void printItem(Item item) { //データの一つを表示
    printf("%d ",item);
}

void print(Queue *q) {  // キューの状態を表示する
    printf("[");
    for(int i=0;i<(q->num);i++){
        printItem(q->arr[(q->front + i) % q->max_num]);
    }
    printf("]\n");

    printArr(q);
}

void enq(Queue *q, Item data) { // キューに Item を enqueue
    if (q->num >= q->max_num){
        return;
    }
    q->arr[(q->front+q->num) % q->max_num] = data;
    q->num++;
}

Item deq(Queue *q) {    // キューから Item を dequeue
    Item item;
    if (q->num <= 0){
        return -1;
    }
    if(q->num >0){
        item = q->arr[q->front % q->max_num];
        q->front = q->front  + 1;
        q->num--;
    }
    return(item);
}

void printArr(Queue *q) { // キューに使用している配列内を全て表示
    int rear = (q->front + q->num) % q->max_num;
    printf("{");
    for (int i=0; i < q->max_num; i++) {

        if ( ( q->front < rear && ( i < q->front || i >= rear)) // Case:A
        || ( q->front >= rear && i >= rear && i < q->front)     // Case:B
        || q->num == 0)                                         // Case:C
            printf("* ");
        else
            printItem(q->arr[i]);
    }
    printf("}\n");
}

int main(void) {
  Queue q = init(4);

    print(&q);
    enq(&q, 100);
    print(&q);
    enq(&q, 200);
    print(&q);
    enq(&q, 300);
    print(&q);
    enq(&q, 400);
    print(&q);
    printItem(deq(&q));
    print(&q);
    printItem(deq(&q));
    print(&q);
    enq(&q, 500);
    print(&q);
    printItem(deq(&q));
    print(&q);
    printItem(deq(&q));
    print(&q);
    printItem(deq(&q));
    print(&q);
  return 0;

}

