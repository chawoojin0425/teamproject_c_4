#include <stdio.h>
#include <stdlib.h>
// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// 새 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// 리스트의 끝에 노드 추가 함수
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// 리스트 출력 함수
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// 메모리 해제 함수
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;  // 리스트의 시작 노드
    // 노드 추가
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    // 리스트 출력
    printf("Linked List: ");
    printList(head);
    // 메모리 해제
    freeList(head);

    return 0;
}
