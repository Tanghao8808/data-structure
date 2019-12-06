#define  _CRT_SECURE_NO_WARNINGS 1

#include"OJ.h"
#include"SList.h"
#include<stdio.h>
#include<assert.h>

SLNode* ReverseList(SList* slist)
{
	assert(slist);
	if (slist->first_ == NULL || slist->first_->next_ == NULL)
		return slist->first_;
	SLNode* first = slist->first_;
	SLNode* next = first->next_;
	SLNode* newlist = NULL;
	while (first != NULL)
	{
		first->next_ = newlist;
		newlist = first;

		first = next;
		if (next != NULL)
			next = next->next_;
	}
	slist->first_ = NULL;
	slist = NULL;
	return newlist;

}