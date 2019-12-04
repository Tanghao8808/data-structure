#define  _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void TestSeqList1()
{
	SeqList seqlist;
	SeqListInit(&seqlist, 30);
	SeqListPushBack(&seqlist, 1);
	SeqListPushBack(&seqlist, 2);
	SeqListPushBack(&seqlist, 3);
	//1,2,3
	SeqListPushFront(&seqlist, 13);
	SeqListPushFront(&seqlist, 12);
	SeqListPushFront(&seqlist, 11);
	//11,12,13,1,2,3
	SeqListInsert(&seqlist, 4, 8);
	//11,12,13,1,8,2,3
	SeqListPopBack(&seqlist);
	//11,12,13,1,8,2
	SeqListPopFront(&seqlist);
	//12,13,1,8,2
	SeqListErase(&seqlist,2);
	//12,13,8,2
	SeqListInsert(&seqlist, 2, 12); // 12,13,12,8,2
	//SeqListPrint(&seqlist);
	SeqListRemoveAll(&seqlist, 12);
	SeqListPrint(&seqlist);// 13,8,2

	SeqListBubbleSort(&seqlist); //2,8,12,13
	SeqListPrint(&seqlist);

	int pos = SeqListBinarySearch(&seqlist, 13);
	printf("%d\n", pos);

	SeqListDestroy(&seqlist);
}

int main()
{
	TestSeqList1();
	system("pause");
	return 0;
}