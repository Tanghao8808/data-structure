#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<stdbool.h>

typedef int SDataType;
typedef struct SeqList
{
	SDataType* array_;
	int size_;
	int capacity_;
}SeqList;

void SeqListInit(SeqList* seqlist, int capacity);
void SeqListDestroy(SeqList* seqlist);

void SeqListPushBack(SeqList* seqlist, SDataType value);
void SeqListPopBack(SeqList* seqlist);

void SeqListPushFront(SeqList* seqlist, SDataType value);
void SeqListPopFront(SeqList* seqlist);

void SeqListInsert(SeqList* seqlist, int pos, SDataType value);
void SeqListErase(SeqList* seqlist, int pos);



void SeqListPrint(const SeqList* seqlist);
void SeqListModify(SeqList* seqlist, int pos, SDataType value);
//�ҵ�һ��Ԫ��
int SeqListFind(const SeqList* seqlist, SDataType value);

//ɾ����һ��ֵΪvalue��Ԫ��
void SeqListRemove(SeqList* seqlist, SDataType value);

bool SeqListIsEmpty(SeqList* seqlist);
int SeqListSize(SeqList* seqlist);

void SeqListBubbleSort(SeqList* seqlist);
int SeqListBinarySearch(SeqList* seqlist, SDataType value);

//ɾ������ֵΪvalued ��Ԫ��
void SeqListRemoveAll(SeqList* seqlist, SDataType value);