#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} Node;

int main(void) {
	Node *head = NULL;
	Node *tail = NULL;
	Node *cur = NULL;

	Node *newNode = NULL;
	int readData;

	while (1) {
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	puts("");

	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL)
		printf("저장된 자연수가 존재하지 않습니다. \n");
	else {
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL)
		return 0;
	else {
		Node *delNode = head;
		Node *delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode); // 맨 처음 head에 있는 메모리 해제

		while (delNextNode != NULL) {
			delNode = delNextNode; // delNode에 다음 노드인 delNextNode 값을 넣고
			delNextNode = delNextNode->next; // delNextNode에 그 다음 노드의 값을 넣는다.

			printf("%d을(를) 삭제합니다. \n", delNode->data); // 이 전과 달리 head값은 사라졌기 때문에 delNode로 다시 한번 선언
			free(delNode);
		}
	}
	return 0;
}