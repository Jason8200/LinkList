#include <stdio.h>
#include <stdlib.h>

typedef struct myLinkList_t
{
	int val;
	struct myLinkList_t *next;
}myLinkList;

myLinkList *CreateLinkList(int val)
{
	myLinkList *p = (myLinkList *)malloc(sizeof(myLinkList));
	
	p->val = val;
	p->next = NULL;
	return p;
}

int myLinkedListGet(myLinkList* obj, int index) 
{
	myLinkList *p;
	int i=1;
	if(index<0)
	{
		return -1;
	}
	p=obj->next;
	while((p!=NULL)&&(index>i))
	{
		p=p->next;
		++i;
	}
	if(p==NULL)
		return -1;
	return (p->val);
}

void myLinkedListAddAtIndex(myLinkList* obj, int index, int val)
{
	myLinkList *L = (myLinkList*)malloc(sizeof(myLinkList));
	myLinkList *p = obj;
	int cent=0;
	L->val = val;
	
	if(index<=0)
	{
		L->next = obj->next;
		obj->next = L;
	}
	
	while((p)&&((index-1)>cent))
	{
		p=p->next;
		cent++;
	}
	
	if((p==NULL)||(cent>index))
	{
		return;
	}
	
	L->next = p->next;
	p->next = L;
}

int main()
{
	myLinkList *s1 = CreateLinkList(1);
	myLinkList *s2 = CreateLinkList(2);
	myLinkList *s3 = CreateLinkList(3);
	myLinkList *s4 = CreateLinkList(4);
	myLinkList *s5 = CreateLinkList(5);
    	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	
	myLinkList *TestList;
	int res = myLinkedListGet(s1,1);
	printf("s3->val = %d\n",s1->next->next->val);
	printf("res = %d\n",res);
	
	myLinkedListAddAtIndex(s1,1,8);
	res = myLinkedListGet(s1,1);
	printf("res = %d\n",res);
	return 0;
}
