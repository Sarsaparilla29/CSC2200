
#include "ListLinked.h"

// ListNode member functions
// default constructor
template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
	:dataItem(nodeData),
	 next(nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
	//this->head = new ListNode<DataType>(nodeData, 0);
}

// List member functions
template <typename DataType>
List<DataType>::List(int ignored)
	: head(nullptr),
	  cursor(0)
{
	//head = new ListNode(newDataItem, 0);
}

template <typename DataType>
List<DataType>::List(const List& other)
{
	operator=(other);
}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
	// self assignment check
	if (this != &other) {
		clear();
		ListNode* otherPtr = other.head;
		// record the position fo cursor in other list
		ListNode* cursorHolder = 0;
		while (otherPtr != 0) {
			// iteration for copying every ListNode in the other list
			insert(otherPtr->dataItem);
			if (otherPtr == other.cursor) {
				cursorHolder = otherPtr;
			}
			// move the other ptr to the next list node
			otherPtr = otherPtr->next;
		}
		cursor = cursorHolder;
	}
	return *this;
}

template <typename DataType>
List<DataType>::~List()
{
	cout << "destructor called" << endl;
	clear();
}

// insert
template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
	// check whether list is empty or not
	if (isEmpty()) {
		// initialization of cursor head
		new ListNode(newDataItem, 0); // or 0
	}
	else {
		// it is not empty
		cursor->next = new ListNode(newDataItem, cursor->next);
	}
}

// take home
template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
}

template <typename DataType>
void List<DataType>::clear()
{
	// delete keyword to delete each list node
	// head pointer
	// cursor pointer
	cursor = head;
	while (cursor != 0) {
		// iterately delete each ListNode in the current list object
		head = head->next;
		delete cursor;
		cursor = head; // last case head and cursor have value nullptr
	}
}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	return (head == 0);
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	// always return false since there is no maxSize
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	return false;
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	return false;
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
	DataType t = NULL;
	return t;
}

template <typename DataType>
void List<DataType>::moveToBeginning() throw (logic_error)
{
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
}

#include "show5.cpp" // this line was originally at bottom of this file


