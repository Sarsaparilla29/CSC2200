
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES

Text::Text ( const char *charSeq )
{
	// constructor
	bufferSize = strlen(charSeq) + 1; // string get length
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq); // string copy
}

/*** copy constructor ***/
Text::Text ( const Text &other )
{
	bufferSize = other.bufferSize; 
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);
}

void Text::operator = ( const Text &other )
{
	if (other.bufferSize < bufferSize) {
		delete[] buffer;
		buffer = new char[bufferSize];
	}
	strcpy(buffer, other.buffer);
}

Text::~Text ()
{
	std::cout << "Destroying Text" << std::endl;
}

int Text::getLength () const
{
	return strlen(buffer); // excluding null character
}

char Text::operator [] ( int n ) const
{
	// "abcd" -> length without null character is 4 in this case
	// 0 1 2 3 4
	// a b c d '\0'
	// n >= 0 && n <= 4
	if (n >= 0 && n <= getLength()) {
		return buffer[n];
	}
	return '\0';
}

void Text::clear ()
{
	// set first character in array to null character
	buffer[0] = '\0';
}

void Text::showStructure() const

// Outputs the characters in a string. This operation is intended for
// testing/debugging purposes only.

{
	int j;   // Loop counter

	for (j = 0; j < bufferSize; j++)
		cout << j << "\t";
	cout << endl;
	for (j = 0; buffer[j] != '\0'; j++)
		cout << buffer[j] << "\t";
	cout << "\\0" << endl;
}

Text Text::toUpper( ) const
{
	Text temp;
	for (int i = 0; i < bufferSize; i++) {
		//temp.buffer[toupper(i)];
		temp.buffer[i] = temp.buffer[toupper(i)];
	}
	// for loop with index i to go through array elements in the array.
	// and call toUpper function to convert each temp.buffer[i];
	return temp;
}

Text Text::toLower( ) const
{
	Text temp;
	return temp;
}

bool Text::operator == ( const Text& other ) const
{
	return (strcmp(buffer, other.buffer) == 0);
}

bool Text::operator <  ( const Text& other ) const
{
	// whether result of comparison is less than 0
	if (strcmp(buffer, other.buffer) < 0)
		return true;
	else
		return false;
}

bool Text::operator >  ( const Text& other ) const
{
	// whether result of comparison is greater than 0
	if (strcmp(buffer, other.buffer) > 0)
		return true;
	else
		return false;
}
