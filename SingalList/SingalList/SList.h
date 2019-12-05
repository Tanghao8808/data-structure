#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once

typedef int SLDataType;

typedef struct SLNode
{
	SLDataType value_;
	struct SLNode* next_;
}SLNode;

typedef struct SList
{
	SLNode* first_;
}SList;

void SListInit(SList* slist);
void SListDestroy(SList* slist);


void SListPushFront(SList* slist, SLDataType value);
void SListPopFront(SList* slist);

void SListPushBack(SList* slist, SLDataType value);
void SListPopBack(SList* slist);

void PrintValue(const SList* slist);

SLNode* SListFind(const SList* slist,SLDataType value);
void SListUpdate(SLNode* node, SLDataType value);
void SListInsert(SLNode* pos, SLDataType value);
void SListErase(SLNode* pos);
