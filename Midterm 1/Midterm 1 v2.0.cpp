#include <iostream>
using namespace std;

// Declaring the Structure of Nodes for our Linked List.
struct node {
	int data;
	struct node* next;
};

// Declaring the Front and Rear of our List as NULLS to start.
struct node* front = NULL;
struct node* rear = NULL;

// Function to enqueue elements to our nodes.
void enqueue(int x)
{
	struct node* temp = new node();
	temp->data = x;
	temp->next = NULL;
	
	// Checking if our Queue is empty or contains nodes.
	// If so, then we are inserting into the first node.
	if(front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	
	rear->next = temp;
	rear = temp;
}

// Function to dequeue elements from our nodes.
void dequeue()
{
	struct node* temp = front;
	
	// Checking if our queue has elements or is empty.
	if(front == NULL)
	{
		cout << "Queue is Empty!" << endl;
		return;
	}
	
	// Checking if we only have 1 element in our queue.
	if(front == rear)
	{
		front = rear = NULL;
	}
	
	else
	{
		node *temp = front;
		front = front->next;
		free(temp);
	}
}

// Function to see the element at the FRONT of the Queue.
void displayfront()
{
	//Checking if the queue has elements or is empty.
	if(front == NULL && rear == NULL)
	{
		cout << "Nothing to Display. Your Queue is Empty!" << endl;
	}
	
	else
	{
		cout << "The element at the FRONT of the Queue is: " << front->data << endl;
	}
}

// Function to Display the entire Queue
void displayqueue()
{
	//Checking if the queue has elements or is empty.
	if(front == NULL && rear == NULL)
	{
		cout << "Nothing to Display. Your Queue is Empty!" << endl;
	}
	
	else
	{
		node* temp = front;
		while(temp != NULL)
		{
			cout << temp->data << "     ";
			temp = temp->next;
		}
	}
}


int main()
{
	int x;
	int switchcaseflag = 1;
	int opchoice;
	
	while(switchcaseflag == 1)
	{
		cout << "Please Enter the Appropriate Number to perform that function." << endl;
		cout << "-------------------------------------------------------------" << endl;
		
		cout << "Enter (1) to Enqueue." << endl;
		cout << "Enter (2) to Dequeue." << endl;
		cout << "Enter (3) to see the value at FRONT of Queue(if any)." << endl;
		cout << "Enter (4) to see the entire Queue." << endl;
		
		cout << endl;
		cout << "Input: ";
		cin >> opchoice;
		cout << endl;
		
		switch(opchoice)
		{
			case 1: cout << "Enter Value to Enqueue: ";
					cin >> x;
					enqueue(x);
					cout << "Enqueued!" << endl;
					cout << endl;
					cout << endl;
					break;
			
			case 2: cout << "Dequeueing..." << endl;
					dequeue();
					cout << endl;
					cout << endl;
					break;
			
			case 3: cout << "Showing the value of FRONT of Queue as requested..." <<endl;
					displayfront();
					cout << endl;
					cout << endl;
					break;
					
			case 4: cout << "Displaying the Entire Queue as requested..." << endl;
					displayqueue();
					cout << endl;
					cout << endl;
					break;
					
			default: cout << "Invalid Input. Ending Program..." << endl;
					 switchcaseflag = 0;
					 break;
		}
	}
	return 0;
}
