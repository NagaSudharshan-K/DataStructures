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
void StackTop(HEAD* head,char *toptoken)
{
		*toptoken=head->list->data;
}
bool EmptyStack(HEAD* head)
{
	if(head->list==NULL)
	return true;
	else
	return false;
}
HEAD* CreateStack()
{
	HEAD* newhead=new HEAD;
	newhead->list=NULL;
	newhead->count=0;
	return newhead;
}
void show(HEAD* head)
{
	NODE* temp=head->list;
	cout<<"\nELEMENTS IN THE STACK:\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<'\n';
}
bool isop(char infix)
{
	if(infix=='+'||infix=='-'||infix=='*'||infix=='/')
	return true;
	return false;
}
int priority(char token)
{
	if(token=='*' || token=='/')
	return 2;
	if(token=='+' || token=='-')
	return 1;
	return 0;
}
int main()
{
	HEAD* stack=CreateStack();
	char infix,temp[2],toptoken='\0',tokenout='\0';
	char postfix[100]={0};
	cout<<"\nEnter a valid Infix Expression:";
	while((infix=getchar())!='\n')
	{
		if(infix=='(')
		Push(stack,infix);//show(stack);
		else if(infix==')')
		{
		Pop(stack,&infix);
		while(infix!='(')
		{
			temp[0]=infix;
			strcat(postfix,temp);
			Pop(stack,&infix);
		}
		}
		else if(isop(infix))
		{
			StackTop(stack,&toptoken);
			while(!EmptyStack(stack) && priority(infix)<=priority(toptoken))
			{
				Pop(stack,&tokenout);
				temp[0]=toptoken;
				strcat(postfix,temp);
				StackTop(stack,&toptoken);
			}
			Push(stack,infix);
		}
		else
		{
			temp[0]=infix;
			strcat(postfix,temp);
		}
		}
		while(!EmptyStack(stack))
		{
		Pop(stack,&tokenout);
		temp[0]=tokenout;
		strcat(postfix,temp);
		}
		cout<<"\nThe Equivalent Postfix Expression : "<<postfix;
}
