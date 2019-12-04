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
//找第一个元素
int SeqListFind(const SeqList* seqlist, SDataType value);

//删除第一个值为value的元素
void SeqListRemove(SeqList* seqlist, SDataType value);

bool SeqListIsEmpty(SeqList* seqlist);
int SeqListSize(SeqList* seqlist);

void SeqListBubbleSort(SeqList* seqlist);
int SeqListBinarySearch(SeqList* seqlist, SDataType value);

//删除所有值为valued 的元素
void SeqListRemoveAll(SeqList* seqlist, SDataType value);