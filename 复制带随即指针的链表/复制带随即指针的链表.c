#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* random;
}Node;

Node* BuyNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->random = NULL;
	node->next = NULL;
	return node;
}

Node* NodeInit(Node* head) {
	head = NULL;
	return head;
}

Node* CopyNode(Node*head) {
	//先复制链表的结点并插入到原节点的后面
	Node* cur = head;//用来遍历旧链表的结点
	while (cur != NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = cur->data;
		node->random = NULL;

		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	//再根据原节点的random对先结点的random进行修改
	cur = head;
	while (cur != NULL) {
		
		if (cur->random != NULL) {
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	//最后将链表拆分成旧链表和新链表，再将新链表的头节点返回即可
	//：需要做的就是修改旧链表结点的next和新链表节点的next
	//因为最后要返回的是新链表的头节点，所以先将它记录下来
	cur = head;
	Node* newhead = head->next;
	while (cur!=NULL) {
		Node* node = cur->next;//用来遍历新链表结点
		cur->next = node->next;
		if (node->next != NULL) {
			node->next = cur->next->next;
		}
		cur = cur->next;
	}
	return newhead;
}

void NodePrint(Node* head) {
	Node* cur = head;
	if (cur == NULL) {
		printf("链表为空！！！\n");
	}
	else {
		while (cur != NULL) {
			printf("%p : %d (%p)--->  ", cur, cur->data, cur->random);
			cur = cur->next;
		}
	}
	return;
}



int main() {
	Node* n1 = BuyNode(10);
	Node* n2 = BuyNode(20);
	Node* n3 = BuyNode(30);
	Node* n4 = BuyNode(40);
	//连接链表
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	//n4->next = NULL;
	//random指针的指向
	n1->random = n3;
	n2->random = n1;
	n3->random = n3;
	n4->random = NULL;
	NodePrint(n1);
	printf("\n\n复制后的新链表：\n\n\n");
	Node* newnode = CopyNode(n1);
	NodePrint(newnode);
	system("pause");
	return 0;
}