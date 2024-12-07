#pragma once
typedef int ElementType;

//CDLL 노드 구조체 선언
typedef struct CDTagNode {
	ElementType Data;
	struct CDTagNode* PrevNode;
	struct CDTagNode* NextNode;
}CDNode;


//CDLL 전용 함수 선언 
CDNode* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(CDNode* CDNode);
void CDLL_AppendNode(CDNode** Head, CDNode* NewNode);
CDNode* CDLL_GetNodeAt(CDNode* Head, int location);
void CDLL_RemoveNode(CDNode** Head, CDNode* Remove);
void CDLL_InsertNode(CDNode* Current, CDNode* NewNode);
int CDLL_GetNodeCount(CDNode* Head);
//--------------------------------------------------

CDNode* CDLL_CreateNode(ElementType NewData) {
	CDNode* NewNode = (CDNode*)malloc(sizeof(CDNode));
	NewNode->Data = NewData;
	NewNode->PrevNode = NewNode;
	NewNode->NextNode= NewNode;

	return NewNode;
}

void CDLL_DestroyNode(CDNode* CDNode) {
	free(CDNode);
}

void CDLL_AppendNode(CDNode** Head, CDNode* NewNode) {
	if (*Head == NULL){
		*Head = NewNode;
		(*Head)->NextNode = NewNode;
		(*Head)->PrevNode = NewNode;
	}
	else {
		CDNode* Tail = (*Head)->PrevNode;

		NewNode->NextNode = *Head;
		NewNode->PrevNode = Tail;
		(*Head)->PrevNode = NewNode;
		Tail->NextNode = NewNode;
	}
}

CDNode* CDLL_GetNodeAt(CDNode* Head, int location) {
	CDNode* Current = Head; 
	while (--location != 0 && Current != NULL) {
		Current = Current->NextNode;
	}
	return Current;
}

void CDLL_RemoveNode(CDNode** Head, CDNode* Remove) {
	if (*Head == Remove) {
		//테일을 2번째에 연결
		//2번째를 헤드와 치환 
		//2번째를 테일에 연결
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		*Head = (*Head)->NextNode;
		(*Head)->PrevNode = Remove->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else {
		CDNode* Current = *Head;
		while (Current != NULL && Current != Remove) {
			Current = Current->NextNode;
		}
		Current->PrevNode->NextNode = Remove->NextNode;
		Current->NextNode->PrevNode = Remove->PrevNode;
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

void CDLL_InsertNode(CDNode* Current, CDNode* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode = NewNode;
	Current->NextNode->PrevNode = NewNode;
}

int CDLL_GetNodeCount(CDNode* Head) {
	int count = 1;
	CDNode* Current = Head; 
	while (Current != NULL && Current->NextNode != Head) {
		Current = Current->NextNode;
		count++;
	}
	return count;
}
