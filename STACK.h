#pragma once

typedef int Elementype;

typedef struct ASNode{
	ElementType Data;
}ASNode;

typedef struct tagArrayStack {
	int Capacity;
	int Top;
	ASNode* Nodes;
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
int AS_GetSize(ArrayStack* Stack);
//--------------

void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	*Stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (ASNode*)malloc(sizeof(ASNode) * Capacity);
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push(ArrayStack* Stack, ElementType Data) {
	Stack->Top += 1;
	Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack* Stack) {
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack) {
	return (Stack->Top) + 1;
}