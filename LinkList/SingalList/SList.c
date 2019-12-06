#define  _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
#include<windows.h>

void SListInit(SList* slist)
{
	assert(slist != NULL);
	slist->first_ = NULL;
}
void SListDestroy(SList* slist)
{
	assert(slist != NULL);
	if (slist->first_ == NULL)
		return;
	if (slist->first_->next_ == NULL)
	{
		free(slist->first_);
		slist->first_ = NULL;
		return;
	}
	SLNode* del = slist->first_;
	SLNode* next = del->next_;
	while (del != NULL)
	{
		free(del);
		del = next;
		if(next != NULL)
			next = next->next_;
	}
	slist->first_ = NULL;
}

static SLNode* NewNode(SLDataType value)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->value_ = value;
	newnode->next_ = NULL;
	return newnode;
}
void SListPushFront(SList* slist, SLDataType value)
{
	assert(slist != NULL);

	SLNode* newnode = NewNode(value);
	assert(newnode != NULL);

	newnode->next_ = slist->first_;
	slist->first_ = newnode;
}

void SListPopFront(SList* slist)
{
	assert(slist != NULL);
	assert(slist->first_ != NULL);
	SLNode* del_node = slist->first_;
	slist->first_ = slist->first_->next_;
	free(del_node);
	del_node = NULL;
}

void SListPushBack(SList* slist, SLDataType value)
{
	assert(slist != NULL);
	if (slist->first_ == NULL)
	{
		SLNode* newnode = NewNode(value);
		assert(newnode);
		slist->first_ = newnode;
		return;
	}
	SLNode* cur = slist->first_;
	while (cur->next_ != NULL)
	{
		cur = cur->next_;
	}
	SLNode* newnode = NewNode(value);
	assert(newnode);
	cur->next_ = newnode;

}
void SListPopBack(SList* slist)
{
	assert(slist);
	assert(slist->first_);
	if (slist->first_->next_ == NULL)
	{
		free(slist->first_);
		slist->first_ = NULL;
	}
	SLNode* cur = slist->first_;
	while (cur->next_->next_ != NULL)
	{
		cur = cur->next_;
	}
	free(cur->next_);
	cur->next_ = NULL;
}

void PrintValue(const SList* slist)
{
	assert(slist);
	if (slist->first_ == NULL)
		return;
	SLNode* cur = slist->first_;
	while (cur != NULL)
	{
		printf("%d-->", cur->value_);
		cur = cur->next_;
	}
	printf("NULL\n");
}


SLNode* SListFind(const SList* slist,SLDataType value)
{
	assert(slist);
	if (slist->first_ == NULL)
		return NULL;
	SLNode* cur = slist->first_;
	while (cur != NULL)
	{
		if (cur->value_ == value)
			return cur;
		cur = cur->next_;
	}
	return NULL;
}
void SListUpdate(SLNode* node, SLDataType value)
{
	assert(node);
	node->value_ = value;
}

void SListInsert(SLNode* pos, SLDataType value)
{
	assert(pos);
	SLNode* newnode = NewNode(value);
	newnode->next_ = pos->next_;
	pos->next_ = newnode;
}
void SListErase(SLNode* pos)
{
	assert(pos);
	SLNode* del_node = pos->next_;
	pos->next_ = del_node->next_;
	free(del_node);
	del_node = NULL;
}