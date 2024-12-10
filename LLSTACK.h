#pragma once

typedef int ElementType;

typedef struct LLStackTagNode {
	char* Data;
	struct LLStackTagNode* NextNode;
}LLSNode;

typedef struct tagLinkedListStack {
	LLSNode* List;
	LLSNode* Top;
}LinkedListStack;

LLSNode* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(LLSNode* Node);
void LLS_CreateStack(LinkedListStack** Stack);
bool LLS_isEmpty(LinkedListStack* Stack);
void LLS_DestroyStack(LinkedListStack* Stack);
LLSNode* LLS_Pop(LinkedListStack* Stack);
void LLS_Push(LinkedListStack* Stack, LLSNode* NewNode);
int LLS_GetSize(LinkedListStack* Stack);
//----------------------------------

LLSNode* LLS_CreateNode(char* NewData) {
	LLSNode* NewNode = (LLSNode*)malloc(sizeof(LLSNode));
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;
	return NewNode;
}

void LLS_DestroyNode(LLSNode* Node) {
	free(Node->Data);
	free(Node);
}

void LLS_CreateStack(LinkedListStack** Stack) {
	*Stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

bool LLS_isEmpty(LinkedListStack* Stack) {
	if (Stack->Top == NULL) return true;
	else return false;
}

void LLS_DestroyStack(LinkedListStack* Stack) {
	while (!LLS_isEmpty(Stack)) {
		LLSNode* Node = LLS_Pop(Stack);
		LLS_DestroyNode(Node);
	}
	free(Stack);
}

LLSNode* LLS_Pop(LinkedListStack* Stack) {
	LLSNode* TopNode = (Stack->Top);

	if (Stack->List == Stack->Top) {Stack->List = NULL; Stack->Top = NULL;}
	else{
		LLSNode* Current = Stack->List;
		while (Current != NULL && Current->NextNode != Stack->Top) {
			Current = Current->NextNode;
		}
		Current->NextNode = NULL;
	}
	return TopNode; 
}

void LLS_Push(LinkedListStack* Stack, LLSNode* NewNode) {
	if (Stack->Top == NULL) Stack->List = NewNode;
	else Stack->Top->NextNode = NewNode;
	Stack->Top = NewNode;
}

int LLS_GetSize(LinkedListStack* Stack) {
	int count = 0; 
	LLSNode* Current = Stack->List;
	while (Current != NULL) {
		Current = Current->NextNode;
		count++;
	}
	return count;
}
