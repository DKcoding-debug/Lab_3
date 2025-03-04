/*
	Delvis Kouete
	Data Structure Spring 2025
	Due: Mar. 4, 2025
	Lab Name: Stack
	A stack is an abstract data type in which elements are added and removed
	from only one end; a “last in, first out” structure. This stack must be implemented as a
	linked structure
	*/

#include <iostream>
using namespace std;

// Node class to represent each element of the stack
class Node
{
public:
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr){}
};

// Stack class to represent the stack
class Stack
{
private:
	Node* top;

public:
	Stack() : top(nullptr) {}

	bool IsEmpty()
	{
		return top == nullptr;
	}
	// Method to check if the stack is full
	// In a linked-list implementation, the stack is never "full" unless system memory is exhausted.
	bool IsFull()
	{
		return false;
	}

	void Push(int value)
	{
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
	}

	// Method to remove the top item from the stack (Pop)
	void Pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is empty, cannot pop!" << endl;
			return;
		}
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	// Method to get the top item from the stack without removing it (Top)
	int Top()
	{
		if (IsEmpty())
		{
			cout << "Stack is empty!" << endl;
			return -1;
		}
		return top->data;
	}

	// Destructor to free any allocated memory when the stack goes out of scope
	~Stack()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}
};

// Main function to test the stack implementation
int main()
{
	Stack s;

	// Test stack operations
	s.Push(10);
	s.Push(20);
	s.Push(30);

	cout << "Top of stack: " << s.Top() << endl;

	s.Pop();
	cout << "Top of stack after pop: " << s.Top() << endl;

	s.Pop();
	s.Pop();
	cout << "Is stack empty? " << (s.IsEmpty() ? "Yes" : "No") << endl;

	return 0;
}