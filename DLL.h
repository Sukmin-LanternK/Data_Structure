#pragma once
#include <corecrt_malloc.h>
typedef int ElementType;

//DLL 노드 구조체 선언
typedef struct DTagNode {
	ElementType Data;
	struct DTagNode* PrevNode;
	struct DTagNode* NextNode;
}DNode;

//DLL 전용 함수 선언 
DNode* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(DNode* DNode);
void DLL_AppendNode(DNode** Head, DNode* NewNode);
DNode* DLL_GetNodeAt(DNode* Head, int location);
void DLL_RemoveNode(DNode** Head, DNode* Remove);
void DLL_InsertNode(DNode* Current, DNode* NewNode);
int DLL_GetNodeCount(DNode* Head);
//--------------------------------------------------

DNode* DLL_CreateNode(ElementType NewData) {

	DNode* NewNode = (DNode*)malloc(sizeof(DNode));
	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;
	return NewNode;
}

void DLL_DestroyNode(DNode* DNode) {
	free(DNode);
}

void DLL_AppendNode(DNode** Head, DNode* NewNode) {
	if (*Head== NULL) *Head = NewNode;
	else {
		DNode* Current = *Head;
		while (Current->NextNode != NULL) {
			Current = Current->NextNode;
		}
		Current->NextNode = NewNode;
		NewNode->PrevNode = Current;
	}
}



DNode* DLL_GetNodeAt(DNode* Head, int location) {
	DNode* Current = Head;
	while (--location != 0 && Current != NULL){
		Current = Current->NextNode;
	}
	return Current;
}
void DLL_RemoveNode(DNode** Head, DNode* Remove) {
	if (*Head == Remove) {
		// Head 변경
		*Head = Remove->NextNode;
		// Remove 주소 변경 
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else {
		DNode* Current = *Head;
		while (Current->NextNode != Remove) {
			Current = Current->NextNode;
		}
		//Prev->Next
		Current->NextNode = Remove->NextNode; 
		Remove->PrevNode = NULL;
		//Next->Prev
		(Remove->NextNode)->PrevNode = Current;
		Remove->NextNode = NULL;
	}
}

void DLL_InsertNode(DNode* Current, DNode* NewNode) {
	
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;
	Current->NextNode = NewNode;
	if (Current->NextNode != NULL) Current->NextNode->PrevNode = NewNode;
}

int DLL_GetNodeCount(DNode* Head) {
	int count = 1;
	DNode* Current = Head;
	while (Current->NextNode != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count; 
}