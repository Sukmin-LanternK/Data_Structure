#include <stdlib.h>
#include <stdio.h>

#include "SLL.h"
#include "DLL.h"
#include "CDLL.h"
#include "STACK.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop(ArrayStack* Stack);
//--------------

int main() {
	ArrayStack* Stack = NULL;
	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 11);
	AS_Push(Stack, 13);
	AS_Push(Stack, 15);
	AS_Push(Stack, 17);
	printf("Capacity: %d, Size: %d, Top: %d",Stack->Capacity,AS_GetSize(Stack),Stack->Top);

	int size = AS_GetSize(Stack);
	for (int i = 0;i < size;i++) {
		printf("Popped: %d, Current Top: %d",AS_Pop(Stack),Stack->Top);
	}
	AS_DestroyStack(Stack);
	return 0;
}