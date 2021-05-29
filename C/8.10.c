#include <stdio.h>
#include <stdlib.h>           // malloc(),free()のため
#include <string.h>           // strcpy()を使う場合

typedef struct {
    int        id;
    char       name[64];
    int        kokugo;
    int        sansu;
} ITEM;

typedef struct node_tag {
    ITEM    data;
    struct node_tag *next;  // ※ NODE はまだ使えない
} NODE;

typedef struct {
    NODE   *head;
    NODE   *tail;
} LIST;

LIST init(void);                 // リストの初期化

void printNode(NODE *node);       // ノードの data を出力

ITEM newItem(int id, char *name, int kokugo, int sansu);    // 値を入れたITEMを作成

void copyItem(ITEM *dst, ITEM *src);         // Item構造体のコピー

void addHead(LIST *lst, ITEM item);           // 先頭にノードを追加

void delHead(LIST *lst);            // 先頭のノードを削除

int getNum(LIST *lst);      // ノードの数を得る

void print(LIST *lst);         // リストの先頭ノードと末尾ノードのidと、リストの先頭から順に全ノードの data を出力

void clear(LIST *lst);         // リストの全消去

void addTail(LIST *lst, ITEM item); // 末尾にノードを追加

void delTail(LIST *lst); // 末尾のノードを削除

NODE *search(LIST *lst, int id);
// id が一致するノードのポインタを返す。見つからなかった場合は NULL を返す。

int insert(LIST *lst, int id, ITEM item);
// id が一致するノードの後ろに、itemの値を持つ新しいノードを挿入する。
//idが一致するノードが見つからなかった場合は -1 を返す。見つかった場合は 0 を返す

int del(LIST *lst, int id); // id が一致するノードを削除する。 idが一致するノードが見つからなかった場合は -1 を返す。見つかった場合は 0 を返す

void push(LIST *lst, ITEM item); // リストの先頭に追加

ITEM pop(LIST *lst); // リストの先頭を取り出す

void printItem(ITEM data);

void enq(LIST *lst, ITEM item); // リストの末尾に追加

ITEM deq(LIST *lst); // リストの先頭を取り出す

void addSort(LIST *lst, ITEM item);// idが昇順になるように追加

int main(void){
    LIST lst = init();
    ITEM item;
    while(1) {
       scanf("%d", &item.id);
       if (item.id < 0)
          break;
       scanf("%s", item.name);
       scanf("%d", &item.kokugo);
       scanf("%d", &item.sansu);
       addSort(&lst, item);
    }
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));
    return 0;
}

LIST init(void) {   // リストの初期化

    LIST lst;

    lst.head=NULL;
    lst.tail=NULL;

    return lst;

}

void printNode(NODE *node) {
    if(node==NULL){
        printf("<NULL>\n");
        return ;
    }
    printf("id = %d", node->data.id);
    printf(", name = %s", node->data.name);
    printf(", kokugo = %d", node->data.kokugo);
    printf(", sansu = %d\n", node->data.sansu);
}

 

// 値を入れたITEMを作成 (実装済み)

ITEM newItem(int id, char *name, int kokugo, int sansu){

    ITEM item;

    item.id = id;

    strcpy(&item.name[0], name);

    item.kokugo = kokugo;

    item.sansu = sansu;

    return item;

}

 

// Item構造体のコピー

void copyItem(ITEM *dst, ITEM *src) {
    dst->id=src->id;
    strcpy(dst->name,src->name);
    dst->kokugo=src->kokugo;
    dst->sansu=src->sansu;
}

void addHead(LIST *lst, ITEM item) {
    NODE*D=(NODE*)malloc(sizeof(NODE));  //100いらない
    copyItem(&D->data,&item);
    D->next=lst->head;
    lst->head=D;
    if(lst->tail==NULL)
    {
        lst->tail=D;
    }
}

 

// 先頭のノードを削除

void delHead(LIST *lst) {

    NODE *p = lst->head;
    NODE *n = p->next;

    if (p == NULL){ // リストが空
        return;
    }
    if (p == lst->tail){ // 最後の1つ

        lst->tail = NULL;
    }

    free(lst->head);

    lst->head=n;
}

 

int getNum(LIST *lst) {     // ノードの数を得る

    NODE *p = lst->head;

    int count = 0;

   

    if (p == NULL){

        return count;
    }

    while(p!=NULL)
    {
        count++;
        p=p->next;
    }

    return count;

}

 

void print(LIST *lst) {       // 先頭から順に全ノードを出力

    NODE *p = lst->head;

    // 先頭ノードと末尾ノードの id を出力

    if (lst->head == NULL){ //p→lst.head

        printf("Head = NULL, ");
    }
    else{
        printf("Head id = %d, ", lst->head->data.id);

 
    }
    if (lst->tail == NULL){

        printf("Tail = NULL\n");
    }
    else{

        printf("Tail id = %d\n", lst->tail->data.id);

   
    }
    if (p == NULL) {   // リストが空だった場合

        printf("<Empty>\n");

        return;

    }

    while (p!=NULL)
    {
        printNode(p);
        p=p->next;
    }


}

void clear(LIST *lst) {

NODE *p = lst->head;
NODE *next = NULL;
    while(p!=NULL)
    {
        next=p->next;
        free(p);
        p=next;
    }
    lst->head = NULL;
    lst->tail = NULL;
}

void addTail(LIST *lst, ITEM item) 
{
    NODE *p=(NODE*)malloc(sizeof(NODE));
    copyItem(&p->data,&item);
    p -> next = NULL;
    if(lst->tail==NULL)
    {
        lst->head = p;
    }
    else
    {
        lst->tail->next = p;
    }
    lst->tail = p;

}

void delTail(LIST *lst) 
{ // 末尾のノードを削除 NODE *node = lst->head;

    NODE *p = lst->head;

    if (p == NULL){ 

        return;
    }
    if (p == lst->tail)
    { 
        free(p);
        lst->head=NULL;
        lst->tail=NULL;
    }
    else
    {
        while(p->next ==lst->tail)
        {
            p=p->next;
        }
    
        p->next=NULL;
        free(lst->tail);
        lst->tail=p;
    }


}
NODE *search(LIST *lst, int id)
{
    NODE *node=lst->head;
        while(node != NULL && node->data.id != id) {
        node = node->next;
    }
    return node;

}

int insert(LIST *lst, int id, ITEM item) {
     NODE *node = search(lst, id);
    if (node == NULL)   // idが見つからなかった場合
    {
        return -1;
    }
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    copyItem(&newNode->data, &item);
    newNode->next = node->next;
       // 新たに追加したノードの next の値を、idの一致するノードの next の値にセット
    node->next = newNode;
       // idの一致するノードの次のノードを、新たに追加したノードに変更
    if (node == lst->tail) // idの一致するノードが末尾ノードだった場合
    {   lst->tail = newNode;
    }
        return 0;

}
int del(LIST *lst, int id) {

    NODE *delNode = search(lst, id);
    if (delNode == NULL){   // idが見つからなかった場合
        return -1;
    }
    if (delNode == lst->head) { // リストの先頭だったら、delHead()に丸投げする
        delHead(lst);
        return 0;
    }
    if (delNode == lst->tail) { // リストの末尾だったら、delTail()に丸投げする
        delTail(lst);
        return 0;
    }
    NODE *node = lst->head;
    // もし lst->head == NULL であれば、search() 結果も
    // NULL (=このケースは上で既に処理済み)なので、ここでは考慮しなくて良い
    // また、p->next が NULL である可能性(リストの中身が1つだけ→該当ノードは必ず先頭ノード)も
    // 考慮する必要はない
    while(node->next->data.id != id) {
        node = node->next;
    }
    node->next = delNode->next;
    free(delNode);
    return 0;  

}

void push(LIST *lst, ITEM item)
{
    addHead(lst,item);
}

ITEM pop(LIST *lst)
{
    if(lst->head==NULL)
    {
        return newItem(-1,"",-1,-1);
    }
    ITEM item;
    copyItem(&item,&lst->head->data);
    delHead(lst);
    return item;

}

void printItem(ITEM data)
{

    printf("id = %d",data.id);

    printf(", name = %s",data.name);

    printf(", kokugo = %d",data.kokugo);

    printf(", sansu = %d\n",data.sansu);

}

void enq(LIST *lst, ITEM item)
{
    addTail(lst,item);
}

ITEM deq(LIST *lst)
{
    return pop(lst);
}

void addSort(LIST *lst, ITEM item)
{
    NODE *p=lst->head;
    NODE *prev=NULL;
    if(p==NULL||p->data.id>item.id)
    {
        addHead(lst,item);
        return;
    }
    while(p->data.id<item.id)
    {
        prev=p;
        p=p->next;
        if(p==NULL)
        {
            addTail(lst,item);
            return;
        }
    }
    insert(lst,prev->data.id,item);
}