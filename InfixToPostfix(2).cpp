#include<iostream>
#include<string.h>
using namespace std;
int top=-1;
#define n 100
void Push(char a[],char data)
{
		top=top+1;
		a[top]=data;
}
void Pop(char a[],char *infix)
{
		int temp[2];
		temp[0]=a[top];
		*infix=temp[0];
		top=top-1;
}
bool isop(char infix)
{
	if(infix=='+'||infix=='-'||infix=='*'||infix=='/')
	return true;
	return false;
}
int main()
{
	char postfix[100]={0},temp[2],tokenout='\0',infix,toptoken;
	char stack[n];
	cout<<"\nEnter a valid Infix expression:";
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
