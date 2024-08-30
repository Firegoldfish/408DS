#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node {
    int data;
    struct Node *link;
} Node;

// 将最小值节点移到链表前面
void moveMinToFront(Node *list) {
    if (list == NULL || list->link == NULL) {
        return; // 空链表或只有头结点，不需要操作
    }

    Node *minPrev = list;            // 指向最小节点的前驱节点
    Node *minNode = list->link;       // 指向最小节点
    Node *prev = list->link;          // 当前节点的前驱节点
    Node *current = list->link->link; // 当前节点

    // 遍历链表找到最小值节点及其前驱
    while (current != NULL) {
        if (current->data < minNode->data) {
            minPrev = prev;
            minNode = current;
        }
        prev = current;
        current = current->link;
    }

    // 如果最小值节点已经在表头，不需要移动
    if (minNode == list->link) {
        return;
    }

    // 将最小值节点从原位置移除
    minPrev->link = minNode->link;

    // 将最小值节点插入到头结点之后
    minNode->link = list->link;
    list->link = minNode;
}

// 辅助函数：创建新节点
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// 辅助函数：打印链表
void printList(Node *list) {
    Node *current = list->link;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

int main() {
    // 创建链表：头结点 -> 4 -> 2 -> 5 -> 1 -> 3 -> NULL
    Node *list = createNode(0); // 头结点
    list->link = createNode(4);
    list->link->link = createNode(2);
    list->link->link->link = createNode(5);
    list->link->link->link->link = createNode(1);
    list->link->link->link->link->link = createNode(3);

    printf("Original list:\n");
    printList(list);

    moveMinToFront(list);

    printf("List after moving min to front:\n");
    printList(list);

    return 0;
}
