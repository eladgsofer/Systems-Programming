#include "String.h"
#include <iostream>

/* Assignment: 1
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherrer, ID: 315932608
*/

using namespace std;
/**
 * @brief Construct a new String:: String object
 * 
 */
String::String()
{
	this->charArray[0] = '\0';
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param string input
 */
String::String(char* string)
{
	int len = strlen(string), charsToBeCopied = 9;

	if (len < 9)
		charsToBeCopied = len;

	for (int i = 0; i < charsToBeCopied; i++)
	{
		this->charArray[i] = string[i];
	}
	this->charArray[charsToBeCopied] = '\0';
}

/**
 * @brief enter characters to edit the string. 
 * 		  Once 9 characters were received: all changes will be made if possible,
 *  	  otherwise none will be made.
 * 
 * @return true - if all given changes were successful.
 * @return false - otherwise. also doesn't change anything.
 */
bool String::setCharsByUser()
{	
	char charValue[2] = { 0 };
	bool validInput = true;
	int replacementNum, charIndex;
	char originalString[10] = { 0 };
	
	// init the temporary string with the charArray value
	strcpy(originalString, this->charArray);

	cout << "Enter how many chars you want to replace\n";
	cin >> replacementNum;

	for (int i = 0;i < replacementNum;i++)
	{
		cout << "Replacement " << i + 1 << " out of " << replacementNum << "\n" << endl;

		cout << "Enter the index you want to replace: (on 0 base)\n" << endl;
		cin >> charIndex;

		cin.ignore(INT64_MAX, '\n');
		cout << "Enter precisely one char (following chars will be ignored)\n" << endl;

		cin.get(charValue, 2);
		cin.ignore(INT64_MAX, '\n');

		if (!(this->setCharAt(charValue[0], charIndex)))
		{
			validInput = false;
			break;
		}
	}

	if (!validInput)
		strcpy(this->charArray, originalString);

	return validInput;
}

/**
 * @brief type a string of up to 9 characters and then press enter
 *  	  to change the current string into the new input one.
 * 
 * @param string 
 */
void String::updateValue(char string[])
{
	if (strlen(string) > 9)
		cerr << "Update failed - string is too long!\n";

	strcpy(this->charArray, string);
}

/**
 * @brief Changes a specific character to a new given value in a given index.
 * 
 * @param ch new character.
 * @param index index of replacement.
 * @return true - if replacement was successful.
 * @return false - otherwise.
 */
bool String::setCharAt(char ch, int index)
{
	int nullIndex = strlen(this->charArray);

	if (index > nullIndex)
		return false;

	// nullIndex maximum is 9, length limit is 9 chars.
	if (index == nullIndex && nullIndex <= 8)
	{
		this->charArray[index] = ch;
		this->charArray[index + 1] = '\0';
		return true;
	}

	this->charArray[index] = ch;
	return true;

}

/**
 * @brief check what character is at the given index in the object's string.
 * 
 * @param index (input)- the given index.
 * @return char - the character in the index.
 */
char String::getCharAt(int index)
{
	int strLength = strlen(this->charArray);
	if (index>=0 && index <= strLength-1)
		return this->charArray[index];

	cerr << "getCharAt failed - char index doesn't exist!";
	return '-';
}

/**
 * @brief prints all 10 characters in the char array and then goes one line downward.
 * 
 */
void String::printValue()
{
	cout << this->charArray << "\n";
}

/**
 * @brief A function which prints the String value.
 * 		  The format can be in Uppercase or lowercase by
 *  	  settings the upperCaseFlag to true/false.
 * 
 * @param upperCaseFlag (input) - 1 = uppercase, 0 = lowercase.
 */
void String::printValue(bool upperCaseFlag)
{

	for (int i = 0;i < strlen(this->charArray); i++)
	{
		if (this->charArray[i] >= 'A' && this->charArray[i] <= 'Z' && !upperCaseFlag)
		{
			cout << (char)(this->charArray[i] + ('a' - 'A'));
			continue;
		}
		if (this->charArray[i] >= 'a' && this->charArray[i] <= 'z' && upperCaseFlag)
		{
			cout << (char)(this->charArray[i] - ('a' - 'A'));
			continue;
		}
		cout << this->charArray[i];
	}
}

