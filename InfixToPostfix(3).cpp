#include<iostream>
#include<string.h>
using namespace std;
struct NODE
{
	char data;
	struct NODE* link;
};
struct HEAD
{
	int count;
	NODE* list;
};
bool Push(HEAD* head,char val)
{
	NODE* newnode=new NODE;
	newnode->data=val;
	newnode->link=NULL;
	newnode->link=head->list;
	head->list=newnode;
	head->count++;
	if(newnode)
	return true;
	else 
	return false;
}
void Pop(HEAD* head,char* infix)
{
	NODE* temp=head->list;
	head->list=temp->link;
	*infix=temp->data;
	delete(temp);
}
HEAD* CreateStack()
{
	HEAD* newhead=new HEAD;
	newhead->list=NULL;
	newhead->count=0;
	return newhead;
}
bool isop(char infix)
{
	if(infix=='+'||infix=='-'||infix=='*'||infix=='/')
	return true;
	return false;
}int main()
{
	HEAD* stack=CreateStack();
	char infix,temp[2],toptoken='\0',tokenout='\0';
	char postfix[100]={0};
	cout<<"\nEnter a valid Infix Expression:";
	while((infix=getchar())!='\n')
	{
		if(infix=='(')
		continue;
		else if(infix==')')
		{
		Pop(stack,&tokenout);
		temp[0]=tokenout;
		strcat(postfix,temp);
		}
		else if(isop(infix))
		{
			Push(stack,infix);
		}
		else
		{
			temp[0]=infix;
			strcat(postfix,temp);
		}
	}
	cout<<"\nThe Equivalent Postfix Expression :"<<postfix;
}
