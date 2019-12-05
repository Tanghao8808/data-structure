#define  _CRT_SECURE_NO_WARNINGS 1

#include"OJ.h"
#include"SList.h"
#include<windows.h>
void TestReverseList()
{
	SList slist;
	SListInit(&slist);

	SListPushBack(&slist, 1);
	SListPushBack(&slist, 2);
	SListPushBack(&slist, 3);
	SListPushBack(&slist, 4);
	SListPushBack(&slist, 5);
	PrintValue(&slist);

	SLNode* reverse_first = ReverseList(&slist);

	SList newlist;
	newlist.first_ = reverse_first;
	PrintValue(&newlist);
	

	SListDestroy(&slist);
}

#if 0
int main()
{
	TestReverseList();
	system("pause");
	return 0;
}
#endif