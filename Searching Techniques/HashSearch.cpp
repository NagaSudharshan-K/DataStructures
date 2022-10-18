//Hash Search
#include<iostream>
using namespace std;
#define MAX_SIZE 5
int choicef()
{
	int ch;
	cout<<"\n(0)Exit\n(1)Insert to Hashtable\n(2)Delete from Hashtable\n(3)Search from Hashtable\n(4)Display HashTable\nEnter your choice:";
	cin>>ch;
	return ch;
}
struct datanode
{
	int data;
	datanode* link;
};
struct headnode
{
	int count;
	datanode* first;
};
//headnode* hashtable[MAX_SIZE];
headnode* CreateHashTable()
{
	headnode* hashtable= new headnode[MAX_SIZE];
	int i=0;
	while(i<MAX_SIZE)
	{
		hashtable[i].count=0;
		hashtable[i].first=NULL;
		i++;
	}
	return hashtable;
}
bool InsertKey(headnode* table,int key)
{
	int index= key % MAX_SIZE;
	if(index<MAX_SIZE)
	{
	datanode* t= new datanode;
	t->data=key;
	t->link=table[index].first;
	table[index].first=t;
	table[index].count++;
	return true;
	}
	else
	return false;
}
bool SearchKey(headnode* table,int x)
{
	int index=x % MAX_SIZE;
	if(table[index].first==NULL)
	return false;
	datanode* t=table[index].first;
	while(t!=NULL && t->data!=x)
	{
		t=t->link;
	}
	if(t==NULL) return false;
	else return true;
}

bool DeleteKey(headnode* table,int x)
{
	int index=x % MAX_SIZE;
	datanode* delnode=table[index].first;
	datanode* t=NULL;
	if(delnode==NULL) return false;
	else if(delnode->data==x)
			{
			table[index].first=delnode->link;
			delete(delnode);
			return true;
			}
	else
	{
	while(delnode!=NULL && delnode->data!=x)
	{
		t=delnode;
		delnode=delnode->link;
	}
	if(delnode==NULL)
	{
		cout<<"\nDATA NOT FOUND\n";
		return false;
	}
	t->link=t->link->link;
	delete(delnode);
	return true;
}}
void show(headnode* table)
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		cout<<"\nAT INDEX "<<i+1<<":";
		datanode* temp=table[i].first;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->link;
		}
		cout<<"\n";
	}
}
int main()
{
	headnode* table=CreateHashTable();
	int val=5,choice;bool check;
	choice=choicef();
	do
	{
		switch(choice)
		{
			case 1:
				cout<<"\nEnter key to be inserted:";
				cin>>val;
				check=InsertKey(table,val);
				if(check) cout<<"\nKey is inserted into table\n";
				else cout<<"\nIndex out of bound\n";
				choice=choicef();
				break;
			case 2:
				cout<<"\nEnter the data to be deleted:";
				cin>>val;
				check=DeleteKey(table,val);
				if(check) cout<<"\nData is deleted\n";
				else cout<<"\nData not found\n";
				choice=choicef();
				break;
			case 3:
				cout<<"\nEnter the data to be searched:";
				cin>>val;
				check=SearchKey(table,val);
				if(check) cout<<"\nData Found\n";
				else cout<<"\nData not Found\n";
				choice=choicef();
				break;
			case 4:
				show(table);
				choice=choicef();
				break;
		}
	}while(choice);
}
//hello

