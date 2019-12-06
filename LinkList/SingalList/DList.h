#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int DListDatatype;
typedef struct DListNode
{
	DListDatatype value_;
	struct DListNode* prev_;
	struct DListNode* next_;
}DListNode;

typedef struct DList 
{
	DListNode* head;
}DList;

static DListNode* NewNode(DListDatatype value)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	assert(newnode);
	newnode->value_ = value;
	newnode->prev_ = NULL;
	newnode->next_ = NULL;

	return newnode;
}
void DListInit(DList* DList)
{
	assert(DList);
	DList->head = NewNode(0);  //头节点的value没有意义
	DList->head->prev_ = DList->head;
	DList->head->next_ = DList->head;
}
void DListClear(DList* DList)
{
	assert(DList && DList->head);
	DListNode* cur = DList->head->next_;
	while (cur != DList->head)
	{
		DListNode* next = cur->next_;

		free(cur);

		cur = next;
	}
	DList->head->next_ = DList->head->prev_ = DList->head;
}
void DListDestroy(DList* DList)
{
	DListClear(DList);
	free(DList->head);
	DList->head = NULL;
}
void DListPushFront(DList* DList, DListDatatype value)
{
	assert(DList);
	DListNode* newnode = NewNode(value);

	newnode->next_ = DList->head->next_;
	newnode->prev_ = DList->head;
	DList->head->next_ = newnode;
	newnode->next_->prev_ = newnode;
}
void DListPushBack(DList* DList, DListDatatype value)
{
	assert(DList);
	DListNode* newnode = NewNode(value);

	newnode->next_ = DList->head;
	newnode->prev_ = DList->head->prev_;
	DList->head->prev_->next_ = newnode;
	DList->head->prev_ = newnode;
}

void DListPopFront(DList* DList)
{
	assert(DList && DList->head->next_ != DList->head);
	DListNode* del_node = DList->head->next_;
	DList->head->next_ = del_node->next_;
	del_node->next_->prev_ = DList->head;

	free(del_node);
	del_node = NULL;
}

void DListPopBack(DList* DList)
{
	assert(DList && DList->head->next_ != DList->head);
	DListNode* del_node = DList->head->prev_;
	del_node->prev_->next_ = DList->head;
	DList->head->prev_ = del_node->prev_;

	free(del_node);
	del_node = NULL;
}

DListNode* DListFind(const DList* DList, DListDatatype value)
{
	assert(DList && DList->head);
	DListNode* cur = DList->head->next_;
	while (cur != DList->head)
	{
		if (cur->value_ == value)
			return cur;
		cur = cur->next_;
	}
	return NULL;
}

//在pos节点前面插入value节点
void DListInsert(DListNode* pos, DListDatatype value)
{
	assert(pos);
	DListNode* newnode = NewNode(value);

	newnode->next_ = pos;
	newnode->prev_ = pos->prev_;
	pos->prev_->next_ = newnode;
	pos->prev_ = newnode;

}

//删除pos位置的节点
void DListErase(DListNode* pos)
{
	assert(pos);
	pos->prev_->next_ = pos->next_;
	pos->next_->prev_ = pos->prev_;
	free(pos);
	pos->next_ = NULL;
	pos->prev_ = NULL;
}

void DListRemove(DList* DList,DListDatatype value)
{
	assert(DList && DList->head);
	if (DList->head->next_ == DList->head)
		return;
	DListNode* cur = DList->head->next_;
	while (cur != DList->head)
	{
		if (cur->value_ == value)
		{
			DListNode* del_node = cur;
			cur = del_node->next_;

			del_node->prev_->next_ = del_node->next_;
			del_node->next_->prev_ = del_node->prev_;

			free(del_node);
		}
		else 
		{
			cur = cur->next_;
		}
	}
}

void DListPrint(DList* DList)
{
	assert(DList && DList->head);
	DListNode* cur = DList->head->next_;
	while (cur != DList->head)
	{
		printf("[%d]-->", cur->value_);
		cur = cur->next_;
	}
	printf("\n");

}
