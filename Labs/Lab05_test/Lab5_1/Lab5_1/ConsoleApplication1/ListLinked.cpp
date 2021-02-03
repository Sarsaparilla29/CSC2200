
#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
	:dataItem(nodeData),
	 next(nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template <typename DataType>
List<DataType>::List(int ignored)
	: head(nullptr),
	  cursor(0)
{
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
	if (this != 0) {
		clear();
		ListNode* otherPtr = other.head;
		// record the position of cursor in other list
		ListNode* cursorHolder = 0;
		while (otherPtr != 0) {
			// iteration for copying every ListNode in the other list
			insert(otherPtr->dataItem);
			if (otherPtr == other.cursor) {
				cursorHolder = otherPtr;
			}
			otherPtr = otherPtr->next;
		}
		cursor = cursorHolder;
	}
	return *this;
}

template <typename DataType>
List<DataType>::~List()
{
	clear();
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
	// check whether list is empty or not

	if (isEmpty()) {
		// initialization of cursor and head

		head = new ListNode(newDataItem, 0);  // these two functions will show insert
		cursor = new ListNode(newDataItem, 0);
		//cursor->next = new ListNode(newDataItem, cursor->next);
	}
	else {
		// it is not empty
		cursor->next = new ListNode(newDataItem, cursor->next);
	}
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
	//List* tempNode = cursor->next;

	//List* next = currentNode;
	//while (currentNode != NULL) {
		//if (currentNode->dataItem == )
	//}
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
}

template <typename DataType>
void List<DataType>::clear()
{
	// delete key word
	// head pointer
	// cursor pointer
	cursor = head;
	while (cursor != 0) {
		// iterately delete each ListNode in the current list object
		head = head->next;
		delete cursor;
		cursor = head; // last case head and cursor have nullptr
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
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	if (isEmpty()) {
		throw logic_error("List is empty.");
	}
	else {
		//cursor->head;
	}
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	else if (cursor == NULL) {
		cout << "at the end." << endl;
	}
	else {
		for (ListNode* temp = head; temp != 0; temp = temp->next) {
			if (cursor == NULL) {
				break;
			}
		}
		cout << cursor->dataItem;
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (isEmpty()) {
		throw logic_error("List is empty.");
		return false;
	}
	else {
		cursor->next;
	}
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	if (isEmpty()) {
		throw logic_error("List is empty.");
	}
	else {
		for (ListNode* temp = head; temp != cursor; temp = temp->next) {
			if (temp == cursor) {
				cout << "[";
			}

			// Assumes that dataItem can be printed via << because
			// is is either primitive or operator<< is overloaded.
			cout << temp->dataItem;

			if (temp == cursor) {
				cout << "]";
			}
			cout << " ";
		}
		cout << endl;
	}
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
	if (isEmpty()) {
		throw logic_error("List is empty.");
	}
	else {
		List* temp_node;
		List* next_node = NULL;
		
		next_node->head;
		temp_node = next_node;
		
		//head->temp_node;
		//temp->head;

		//cursor->next_node;
	}
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
	// check whether list is empty or not

	if (isEmpty()) {
		throw logic_error("List is empty.");
		// initialization of cursor and head
		/*head = new ListNode(newDataItem, 0);  // these two functions will show insert
		cursor = new ListNode(newDataItem, 0);*/
		//cursor->next = new ListNode(newDataItem, cursor->next);
	}
	else {
		ListNode* tempNode = cursor;
		cursor->next = new ListNode(newDataItem, cursor->next);
		tempNode = new ListNode(newDataItem, tempNode);
		// it is not empty
		//cursor->next = new ListNode(newDataItem, cursor->next);
	}
}

#include "show5.cpp"

