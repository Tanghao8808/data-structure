#define  _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"
#include<windows.h>

void TestDList()
{
	DList DList;
	DListInit(&DList);
	DListPushFront(&DList, 3);
	DListPushFront(&DList, 2);
	DListPushFront(&DList, 1);

	DListPushBack(&DList, 11);
	DListPushBack(&DList, 12);
	DListPushBack(&DList, 13);

	DListPrint(&DList);  //1,2,3,11,12,13

	DListPopBack(&DList);//1,2,3,11,12
	DListPrint(&DList);

	DListPopFront(&DList);//2,3,11,12
	DListPrint(&DList);

	DListNode* pos = DListFind(&DList, 11);
	DListInsert(pos, 13);
	DListPrint(&DList); //2,3,13,11,12

	pos = DListFind(&DList, 12);
	DListErase(pos);
	DListPrint(&DList); //2,3,13,11

	pos = DListFind(&DList, 13);
	DListInsert(pos, 15);
	DListInsert(pos, 16);
	DListInsert(pos, 15);
	DListInsert(pos, 15);
	DListInsert(pos, 17);
	DListPrint(&DList); //2,3,15,16,15,15,17,13,11

	DListRemove(&DList, 15);
	DListPrint(&DList); //2,3,16,17,13,11

	DListDestroy(&DList);
}
int main()
{
	TestDList();
	system("pause");
	return 0;
}