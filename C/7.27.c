#include <stdio.h>
#include <stdlib.h>	// malloc(),free()のため
#include <string.h>	// strcpy()を使う場合

typedef struct {
	int 	id;
	char 	name[64];
	int 	kokugo;
	int	    sansu;
} ITEM;

typedef struct node_tag {
	ITEM	data;
	struct node_tag *next;  // ※ NODE はまだ使えない
} NODE;

typedef struct {
	NODE	*head;
	NODE	*tail;
} LIST;

LIST init(void) {   // リストの初期化
    LIST lst;
    lst.head = NULL;
    lst.tail = NULL;
    return lst;
}

// ノードの data を出力 
void printNode(NODE *node) {
    printf("id = %d", node->data.id);
    printf(", name = %s", node->data.name);
    printf(", kokugo = %d", node->data.kokugo);
    printf(", sansu = %d\n", node->data.sansu);
}

// 値を入れたITEMを作成 
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
    dst->id = src->id;
    strcpy(dst->name,src->name);
    dst->kokugo = src->kokugo;
    dst->sansu = src->sansu; 
}

// 先頭にノードを追加
void addHead(LIST *lst, ITEM item) {
    NODE *d =(int*)malloc(sizeof(NODE));
    copyItem(&d->data,&item);
    d->next = lst->head;

    lst->head = d;
    if(lst->tail == NULL){
        lst->tail = d;
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
    lst->head = n;
}

int getNum(LIST *lst) {	// ノードの数を得る
    NODE *p = lst->head;
    int count = 0;
    
    if (p == NULL){
        return count;
    }
    while (p != NULL){
        count ++;
        p = p->next;
    }
    return count;
}

void print(LIST *lst) {	// 先頭から順に全ノードを出力
    NODE *p = lst->head;

    // 先頭ノードと末尾ノードの id を出力
    if (lst->head == NULL)
        printf("Head = NULL, ");
    else
        printf("Head id = %d, ", lst->head->data.id);

    if (lst->tail == NULL)
        printf("Tail = NULL\n");
    else
        printf("Tail id = %d\n", lst->tail->data.id);
    
    if (p == NULL) {   // リストが空だった場合
        printf("<Empty>\n");
        return;
    }
    while (p != NULL){
        printNode(p);
        p = p->next;  
    }
    
}

int main(void){
    LIST lst = init();
    
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));
    
    
    addHead(&lst, newItem(110, "ABC", 80, 90));
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    addHead(&lst, newItem(120, "DEF", 85, 95));
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    addHead(&lst, newItem(130, "GHI", 38, 96));
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    delHead(&lst);
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    delHead(&lst);
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    addHead(&lst, newItem(140, "GHI", 55, 66));
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    delHead(&lst);
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    delHead(&lst);
    print(&lst);
    printf("==> Num = %d\n\n", getNum(&lst));

    return 0;
}



