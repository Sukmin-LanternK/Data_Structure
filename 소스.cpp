#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
	struct tagNode* NextNode;
}Node;

Node* SLL_CreatNode(ElementType NewData) {
	// 스택이 아닌 힙을 사용하므로, 힙에서 어디를 가리키는지를 이용하여 Node 조회 
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	return NewNode;
}

void SLL_DestroyNode(Node* Node) {
	free(Node);
}

void SLL_AppendNode(Node** Head,Node* NewNode) {
	if (*Head == NULL)*Head = NewNode;
	else {
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location) {

	Node* Current = Head;
	while(Current != NULL && --Location >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) *Head = Remove->NextNode;
	else {
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove) {
			Current = Current->NextNode;
		}
		if (Current != NULL) Current->NextNode = Remove->NextNode;
	}
	
	SLL_DestroyNode(Remove);
}

void SLL_InsertNode(Node* Current, Node* Insert) {
	Insert->NextNode = Current->NextNode;
	Current->NextNode = Insert;

}

int SLL_GetNodeCount(Node* Head) {
	int count=1;
	Node* Current = Head; 
	while (Current->NextNode != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count; 
}

int main() {
	Node* List = NULL;
	Node* NewNode =NULL;
	NewNode = SLL_CreatNode(13);
	SLL_AppendNode(&List, NewNode);
	NewNode = SLL_CreatNode(15);
	SLL_AppendNode(&List, NewNode);
	
	printf("%d",List->NextNode->Data);


	SLL_DestroyNode(NewNode);
	SLL_DestroyNode(List);

	return 0;
}