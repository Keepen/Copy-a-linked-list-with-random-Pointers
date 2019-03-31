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
	//�ȸ�������Ľ�㲢���뵽ԭ�ڵ�ĺ���
	Node* cur = head;//��������������Ľ��
	while (cur != NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = cur->data;
		node->random = NULL;

		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	//�ٸ���ԭ�ڵ��random���Ƚ���random�����޸�
	cur = head;
	while (cur != NULL) {
		
		if (cur->random != NULL) {
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	//��������ֳɾ�������������ٽ��������ͷ�ڵ㷵�ؼ���
	//����Ҫ���ľ����޸ľ��������next��������ڵ��next
	//��Ϊ���Ҫ���ص����������ͷ�ڵ㣬�����Ƚ�����¼����
	cur = head;
	Node* newhead = head->next;
	while (cur!=NULL) {
		Node* node = cur->next;//����������������
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
		printf("����Ϊ�գ�����\n");
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
	//��������
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	//n4->next = NULL;
	//randomָ���ָ��
	n1->random = n3;
	n2->random = n1;
	n3->random = n3;
	n4->random = NULL;
	NodePrint(n1);
	printf("\n\n���ƺ��������\n\n\n");
	Node* newnode = CopyNode(n1);
	NodePrint(newnode);
	system("pause");
	return 0;
}