#pragma once

#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename T>
struct Node
{
	T info;
	Node <T>* link;//often called “next” for singly-linked list
};

template <typename T>
class LinkedList
{
private:
	int nodeCount; //not mandatory, but convenient 
	Node<T>* first;
	Node<T>* last;

public:
	/// <summary>
/// initializes empty list
/// first = null, last = null, count = 0
/// </summary>
	LinkedList()
	{
		nodeCount = 0;
		first = NULL; //or nullptr keyword, or 0
		last = NULL;
	}

	void print() {
		Node<T>* current;
		current = first;

		while (current != NULL) {
			cout << current->info << endl;
			current = current->link;
		}
	}//end print() function 

	int length() { return nodeCount; }

	/// <summary>
/// Insert at “beginning”
/// </summary>

	void insertFirst(const T& newInfo)
		//pass info by constant reference
		//alternative approach: create a Node object and pass it in
	{
		// def continues next slides


		Node<T>* newNode = new Node<T>;

		newNode->info = newInfo;
		newNode->link = first; //puts newNode before first

		first = newNode;


		if (last == NULL)
		{
			last = newNode;
			//if newNode is the only node, 
			//it is both first and last 
		}
		nodeCount++;
	} //end insertFirst()


	void insertAfter(Node<T>* previous, T insertedValue)
	{
		Node<T>* newNode = new Node<T>;
		newNode->info = insertedValue;

		//Diagram on next slides walks through two lines below:
		newNode->link = previous->link;

		previous->link = newNode;
	}

	Node<T>* getNode(int nodePosition)
	{
		Node<T>* current = new Node<T>;
		current = first;

		int i = 0;
		while (i < nodePosition)
		{
			current = current->link;
			i++;
		}

		return current;
	}


	bool search(const T& valueToFind)
	{
		bool found = false; 
		Node<T>* current = first;

		while (current != nullptr and !found)
		{
			if (current->info == valueToFind) 
			{
				found = true;
			}
			else
			{
				current = current->link;
			}
		}
		return found;
	}

	void deleteNodeWithInfo(const T& infoToDelete) {

		Node<T>* current; 
		Node<T>* temp; 
		bool found;

		if (first->info == infoToDelete)
		{
			found = true;
			current = first;
			first = first->link;
			delete current;
			nodeCount--;
		} //end if found in FIRST node

		else // the info is NOT in the first NODE - OR it's not present
		{
			found = false; 
			temp = first; 

			current = first->link;

			while (!found and current != nullptr)
			{
				if (current->info != infoToDelete)
				{
					temp = current;
					current = current->link;
				}

				else
				{
					found = true;

				}
			}//end while 

			if (found)
			{
				temp -> link = current->link;

				if (current == last)
				{
					last = temp; 
				}

				delete current; 
				nodeCount--;
			} //end if found

			else //DIDN'T find it!
			{
				cout << "The value " << infoToDelete << " was not found!" << endl;
			}

		} //end else 
	} //end deleteNode 



};