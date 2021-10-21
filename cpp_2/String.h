#pragma once

/* Assignment: 1
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherrer, ID: 315932608
*/

class String
{
private:
	char charArray[10];

public:
	String();
	String(char* string);
	~String() {};
	void updateValue(char string[]);
	bool setCharsByUser();

	bool setCharAt(char ch, int index);
	char getCharAt(int index);

	void printValue();
	void printValue(bool upperCaseFlag);
};

