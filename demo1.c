/*这是一个链表测试实验*/
#include <stdio.h>
#include <stdlib.h>

typedef struct menu{
	unsigned char str[10];
	struct menu *next;
}NODE;

NODE *n_creat(NODE *head)
{
	head->next=NULL;
	return head;
}

NODE *n_find(NODE *head,int i)
{
	NODE *p;//当前第i个节点
	int j=0;
	p=head;
	while(j<i)
	{
		if(p->next!=NULL)
		{
			p=p->next;
			j++;
		}
		else
		{
			
			break;
		}
	}
	return p;
}

void n_insert(NODE *head,NODE *pnew,int i)
{
	NODE *p;
	if(i==0)
		return;
	p=n_find(head,i-1);	//查找i的前一个节点
	pnew->next=p->next;
	p->next=pnew;
}

void n_delete(NODE *head,int i)
{
	NODE *p;
	if(i==0)
		return;

	p=n_find(head,i-1);	//查找i前面的一个节点
	p->next=p->next->next;
}

void n_display(NODE *head)
{
	int i=0;
	NODE *p=head;
	while(p!=NULL)
	{
		printf("%d:%s\n",i,p->str);
		p=p->next;
		i++;
	}
}

int main()
{
	NODE *head;
	NODE main={
		"Main",
		0
	};
	NODE menu1={
		"menu1",
		0
	};
	NODE menu2={
		"menu2",
		0
	};
	NODE menu3={
		"menu3",
		0
	};

	head=n_creat(&main);
	n_insert(head,&menu1,1);
	n_insert(head,&menu2,2);
	n_insert(head,&menu3,3);

	n_display(head);
}
