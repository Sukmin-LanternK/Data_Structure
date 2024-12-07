#include <stdlib.h>
#include <stdio.h>

#include "SLL.h"
#include "DLL.h"


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