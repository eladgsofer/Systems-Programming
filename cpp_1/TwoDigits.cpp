#include "TwoDigits.h"
#include <iostream>

/* Assignment: 1
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherrer, ID: 315932608
*/

/**
 * @brief Construct a new Two Digits:: Two Digits object
 * 
 * @param number (input) integer, uses only the tens and ones digits no matter how big.
 */
TwoDigits::TwoDigits(int number)
{
	this->onesDigit = (char)((number % 10) + '0');
	this->tensDigit = (char)(((number / 10) % 10) + '0');
}

/**
 * @brief Construct a new Two Digits:: Two Digits object
 * 
 * @param onesDigit (input)
 * @param tensDigit (input)
 */
TwoDigits::TwoDigits(char onesDigit, char tensDigit)
{
	this->onesDigit = onesDigit;
	this->tensDigit = tensDigit;
}

/**
 * @brief calculate and returns the object's number as an integer.
 * 
 * @return int (input)
 */
int TwoDigits::value()
{
	return (int)(this->onesDigit - '0') + ((int)(this->tensDigit - '0'))*10;
}

/**
 * @brief Updates value into a new one with an integer.
 * 
 * @param updatedNumber (input) - new object 2digits number.
 */
void TwoDigits::update(int updatedNumber)
{
	this->onesDigit = (char)((updatedNumber % 10) + '0');
	this->tensDigit = (char)(((updatedNumber / 10) % 10) + '0');
}

/**
 * @brief Updates value into a new one with 2 given chars.
 * 
 * @param onesDigit (input)
 * @param tensDigit (input)
 */
void TwoDigits::updateByChars(char onesDigit, char tensDigit)
{
	this->onesDigit = onesDigit;
	this->tensDigit = tensDigit;
}

/**
 * @brief Prints value with an option to print with the zero or without if the number is between 0 and 9.
 * 
 * @param withZeros (input), 1 = with zero, 0 = without.
 */
void TwoDigits::printValue(bool withZeros)
{
	if (!this->tensDigit || withZeros)
	{
		cout << this->tensDigit << this->onesDigit << "\n";
	}
	else
		cout << this->tensDigit << "\n";
		
}
