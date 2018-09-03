// LinkedList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
struct node {
	int value;
	struct node *next;
};
	struct node *top= NULL;
 void push(int x) {
	if (top == NULL)
	{
		top= new node;
		top->value = x;
	}
	else {
		struct node*a;
		a = new node;
		a->value = x;
		a->next = top;
		top = a;
	}
}
 int pop() {
	 if (top == NULL) { cout << "Empty"; }
	 else { struct node*a = end;
	 end = end->next;
	 delete(a);
	 }
	 return next;
 }

int main()
{
	
	/*int a = 2017;
	cout << &a << endl;
	int *b = &a;
	cout << b<<endl;
	cout << *b<<endl;*/

	struct node *a;
	a = new node;
	a->value = 12;
	struct node *b;
	b = new node;
	b->value = 13;
	a->next = b;
 cout<<	a->next->value<<endl;
 push(1);
 push(10);
 
   delete(b);

   
	   
   
	
	system("pause");
    return 0;
}

