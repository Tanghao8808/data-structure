#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include"SeqList.h"

#include<assert.h>
#include<malloc.h>

static CheckCapacity(SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	assert(seqlist->size_ <= seqlist->capacity_);
	if (seqlist->size_ == seqlist->capacity_)
	{
		int capacity = seqlist->capacity_ * 2;
		SDataType* array = (SDataType*)malloc(sizeof(SDataType)*capacity);
		for (int i = 0; i < seqlist->size_; i++)
		{
			array[i] = seqlist->array_[i];
		}
		free(seqlist->array_);
		seqlist->array_ = array;
		seqlist->capacity_ = capacity;
	}
}
void SeqListInit(SeqList* seqlist, int capacity)
{
	assert(seqlist != NULL);
	seqlist->array_= (SDataType*)malloc(sizeof(SDataType)*capacity);

	assert(seqlist->array_ != NULL);
	seqlist->capacity_ = capacity;
	seqlist->size_ = 0;
}
void SeqListDestroy(SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);

	free(seqlist->array_);

	seqlist->array_ = NULL;
	seqlist->capacity_ = 0;
	seqlist->size_ = 0;
}


void SeqListPushBack(SeqList* seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);

	//需要检查是否要增容
	CheckCapacity(seqlist);
	seqlist->array_[seqlist->size_] = value;
	seqlist->size_++;
}
void SeqListPopBack(SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	assert(seqlist->size_ != 0);

	seqlist->size_--; 
}

void SeqListPushFront(SeqList* seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);

	CheckCapacity(seqlist);

	for (int i = seqlist->size_ - 1; i >= 0; i--)
	{
		seqlist->array_[i + 1] = seqlist->array_[i];
	}
	seqlist->array_[0] = value;
	seqlist->size_++;
}
void SeqListPopFront(SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	assert(seqlist->size_ != 0);

	for (int i = 1; i < seqlist->size_; i++)
	{
		seqlist->array_[i - 1] = seqlist->array_[i];
	}
	seqlist->size_--;

}

void SeqListInsert(SeqList* seqlist, int pos, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	assert(pos >= 0 && pos <= seqlist->size_);

	CheckCapacity(seqlist);

	for (int i = seqlist->size_ - 1; i >= pos; i--)
	{
		seqlist->array_[i + 1] = seqlist->array_[i];
	}
	seqlist->array_[pos] = value;
	seqlist->size_++;
}
void SeqListErase(SeqList* seqlist, int pos)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	assert(seqlist->size_ > 0);
	assert(pos >= 0 && pos < seqlist->size_);
	for (int i = pos+1; i < seqlist->size_; i++)
	{
		seqlist->array_[i - 1] = seqlist->array_[i];
	}
	seqlist->size_--;
}


void SeqListPrint(const SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	for (int i = 0; i < seqlist->size_; i++)
	{
		printf("[%d] ", seqlist->array_[i]);
	}
	printf("\n");
}
void SeqListModify(SeqList* seqlist, int pos, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	assert(pos >= 0 && pos < seqlist->size_);
	seqlist->array_[pos] = value;
}
int SeqListFind(const SeqList* seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	for (int i = 0; i < seqlist->size_; i++)
	{
		if (seqlist->array_[i] == value)
			return i;
	}
	return -1;
}
void SeqListRemove(SeqList* seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	for (int i = 0; i < seqlist->size_; i++)
	{
		if (seqlist->array_[i] == value)
		{
			for (int j = i + 1; j < seqlist->size_; j++)
			{
				seqlist->array_[j - 1] = seqlist->array_[j];
			}
			return;
		}
	}
	
}

bool SeqListIsEmpty(SeqList* seqlist)
{
	assert(seqlist != NULL);
	return seqlist->size_ == 0;
}
int SeqListSize(SeqList* seqlist)
{
	assert(seqlist != NULL);
	return seqlist->size_;
}

static swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SeqListBubbleSort(SeqList* seqlist)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	for (int i = 0; i < seqlist->size_-1; i++)
	{
		int IsSort = 1;
		for (int j = 0; j < seqlist->size_ - 1 - i; j++) 
		{
			if (seqlist->array_[j] > seqlist->array_[j+1])
			{
				swap(&seqlist->array_[j], &seqlist->array_[j+1]);
				IsSort = 0;
			}
		}
		if (IsSort == 1)
			return;
	}
}
int SeqListBinarySearch(SeqList* seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	int left = 0;
	int right = seqlist->size_ - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (seqlist->array_[mid] == value)
			return mid;
		else if (seqlist->array_[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
void SeqListRemoveAll(SeqList* seqlist, SDataType value)
{
	assert(seqlist != NULL);
	assert(seqlist->array_ != NULL);
	int index = 0;
	for (int i = 0; i < seqlist->size_; i++)
	{
		if (seqlist->array_[i] != value)
		{
			seqlist->array_[index] = seqlist->array_[i];
			index++;
		}
		
	}
	seqlist->size_ = index;
}