#define  _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SListTest1()
{
	SList slist;
	SListInit(&slist);
	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	//1-->2-->3
	SListPushFront(&slist, 13);
	SListPushFront(&slist, 12);
	SListPushFront(&slist, 11);
	PrintValue(&slist);
	//11-->12-->13-->1-->2-->3
	SLNode* node = SListFind(&slist, 13);
	SListUpdate(node, 15);
	PrintValue(&slist);
	SListInsert(node, 18);
	PrintValue(&slist);
	SListErase(node);
	PrintValue(&slist);
	SListPopBack(&slist);
	SListPopBack(&slist);
	SListPopBack(&slist);
	//11-->12-->13
	SListPopFront(&slist);
	SListPopFront(&slist);
	//13
	SListDestroy(&slist);
}
#if 0
int main()
{
	SListTest1();
	system("pause");
	return 0;
}
#endif