
#include "ListArray.h"

template < typename DataType >
List<DataType>::List(int maxNumber)
	: maxSize(maxNumber),
	  size(0),
	  cursor(-1)
{
	dataItems = new DataType[maxSize];
}

template < typename DataType >
List<DataType>::List ( const List& source )
{
	maxSize = source.maxSize;
	size = source.size;
	cursor = source.cursor;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < size; i++) {
		dataItems[i] = source.dataItems[i];
	}
}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source )
{
	if (this != &source) {
		if (source.maxSize > maxSize) {
			delete[] dataItems;
			maxSize = source.maxSize;
			dataItems = new DataType[maxSize];
		}
		size = source.size;
		cursor = source.cursor;
		for (int i = 0; i < size; i++) {
			dataItems[i] = source.dataItems[i];
		}
	}
	return *this;
}

template < typename DataType >
List<DataType>::~List ()
{
	delete[] dataItems;
}

template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem )
	throw ( logic_error )
{
	if (isFull())
		throw logic_error("List is full.");
	if (isEmpty())
		dataItems[0] = newDataItem;
	else {

		for (int j = size; j > cursor + 1; j--) {
			// last shifted element in the list dataItems[cursor+1] = dataItems[cursor+1]
			dataItems[j] = dataItems[j - 1];
			// 
		}
		// update the value of element at position cursor + 1
		dataItems[++cursor] = newDataItem;
	}
	// update size and cursor
	size++;
	cursor++;
}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error )
{
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	else {
		// for loop to shift remaining elements in opposite direction compare with
		for (int i = cursor; i < size - 1; i++) {
			// last shifted element dataItems[size - 2] = dataItems[size - 1];
			dataItems[i] = dataItems[i + 1];
		}
	}
	// update size
	size--;
	cursor--;
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
{
	if (isEmpty())
		throw logic_error("List is empty.");
	else {
		// update newDataItem at position pointed by cursor
		dataItems[cursor] = newDataItem;
	}
}

template < typename DataType >
void List<DataType>::clear ()
{
	cursor = -1;
	size = 0;
}

template < typename DataType >
bool List<DataType>::isEmpty () const
{
	// compare size with 0
	return (size == 0);
}

template < typename DataType >
bool List<DataType>::isFull () const
{
	// compare size with maxSize
	return (size == maxSize);
}

template < typename DataType >
void List<DataType>::gotoBeginning ()
        throw ( logic_error )
{
	cout << "gotoBeginning function" << endl;
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	else
		cursor--;
}

template < typename DataType >
void List<DataType>::gotoEnd ()
        throw ( logic_error )
{
	cout << "gotoEnd function" << endl;
	if (isEmpty()) {
		throw logic_error("List is empty");
	}
	else
		cursor = size;
}

template < typename DataType >
bool List<DataType>::gotoNext ()
        throw ( logic_error )
{
	if (isFull()) {
		throw logic_error("List is full");
	}
	else if (isEmpty())
		throw logic_error("List is empty");
	else
		cursor++;
}

template < typename DataType >
bool List<DataType>::gotoPrior ()
        throw ( logic_error )
{
	return false;
}

template < typename DataType >
DataType List<DataType>::getCursor () const
        throw ( logic_error )
{
	DataType t;
	return t;
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth ( int n )
        throw ( logic_error )
{
}

template < typename DataType >
bool List<DataType>::find ( const DataType& searchDataItem )
        throw ( logic_error )
{
	return false;
}