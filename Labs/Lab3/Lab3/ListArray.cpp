
#include "ListArray.h"

template < typename DataType >
List<DataType>::List ( int maxNumber )
{
}

template < typename DataType >
List<DataType>::List ( const List& source )
{
}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source )
{
	return *this;
}

template < typename DataType >
List<DataType>::~List ()
{
}

template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem )
	throw ( logic_error )
{
}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error )
{
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
{
}

template < typename DataType >
void List<DataType>::clear ()
{
}

template < typename DataType >
bool List<DataType>::isEmpty () const
{
	return false;
}

template < typename DataType >
bool List<DataType>::isFull () const
{
	return false;
}

template < typename DataType >
void List<DataType>::gotoBeginning ()
        throw ( logic_error )
{
}

template < typename DataType >
void List<DataType>::gotoEnd ()
        throw ( logic_error )
{
}

template < typename DataType >
bool List<DataType>::gotoNext ()
        throw ( logic_error )
{
	return false;
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