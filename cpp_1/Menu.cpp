#include <iostream>

#include "Menu.h"
#include "String.h"
#include "Fraction.h"
#include "TwoDigits.h"

/* Assignment: 1
Author: Israel Israeli, ID: 01234567
Author: Canda Canadi, ID: 76543210
*/

using namespace std;

/**
 * @brief Construct a new Menu:: Menu object
 * 
 */
Menu::Menu() {}

/**
 * @brief main menu, see instructions on how to enter other menuscreens or exit.
 * 
 */
void Menu::mainMenu()
{
	int menuIndex=0;
	do
	{
		cout << "\nMAIN MENU:" << endl;
		cout << "Enter 1 for Two Digits Menu\nEnter 2 for Fraction Menu\nEnter 3 for String Menu\nEnter 4 for Quitting the program" << endl;
		cin >> menuIndex;
		cin.ignore(INT64_MAX, '\n');

		switch (menuIndex)
		{
		case 1: // twoDigitsMenu
			cout << "\nEntering TwoDigits Menu:" << endl;
			twoDigitsMenu();
			break;
		case 2: // fractionMenu
			cout << "\nEntering Fraction Menu:" << endl;
			fractionMenu();
			break;
		case 3: // stringMenu
			cout << "\nEntering String Menu:" << endl;
			stringMenu();
			break;
		case 4: // exit
			cout << "GoodBye" << endl;
		default:
			break;
		}

	} while (menuIndex != 4);
}

/**
 * @brief creates 2 of TwoDigits class objects with given inputs and manipulates them based on chosen option.
 * 
 */
void Menu::twoDigitsMenu() 
{
	TwoDigits twoDigitsByChars;
	TwoDigits twoDigitsByInt;

	while (!(recieveTwoDigitsByChars(twoDigitsByChars) && recieveTwoDigitsByInt(twoDigitsByInt))){
		cout << "Wrong input, try again with valid input" << endl;
	}

	int menuIndex = 0, value1, value2;
	do
	{
		cout << "\nEnter 1 for update a twoDigits Object by int\nEnter 2 Object summation\nEnter 3 Object printing\nEnter 4 for Quitting the menu" << endl;
		cin >> menuIndex;

		switch (menuIndex)
		{
		case 1:
			recieveTwoDigitsByInt(twoDigitsByChars);
			break;
		case 2:
			value1 = twoDigitsByInt.value(), value2 = twoDigitsByChars.value();
			cout << "The sum of " << value1 << "+" << value2 << " is: " << value1 + value2 << endl;

			break;
		case 3:
			cout << "First two digit number: ";
			twoDigitsByChars.printValue(true);

			cout << "Second two digit number: ";
			twoDigitsByInt.printValue(true);
			break;
		case 4:
			return;
		default:
			break;
		}

	} while (menuIndex != 4);
}

/**
 * @brief TwoDigits first object edit with given input before manipulation in the initialization of its menu.
 * 
 * @param twoDigitsByChars (output) - reference to first TwoDigits class object which is set with characters.
 * @return true - if input chars was successfuly received.
 * @return false - otherwise.
 */
bool Menu::recieveTwoDigitsByChars(TwoDigits& twoDigitsByChars)
{
	char tensDigit, onesDigit;
	cout << "Enter 2 Characters to construct the first number:" << endl;
	
	cout << "Enter the tens digit" << endl;
	cin >> tensDigit;

	cout << "Enter the ones digit" << endl;
	cin >> onesDigit;

	if (!(isdigit(tensDigit) && isdigit(onesDigit)))
	{
		cerr << "Only 2 digit numbers will be accepted." << endl;
		return false;
	}
	twoDigitsByChars.updateByChars(onesDigit, tensDigit);

	return true;
}

/**
 * @brief TwoDigits second object edit with given input before manipulation in the initialization of its menu.
 * 
 * @param twoDigitsByInt (output) - reference to second TwoDigits class object which is set with int.
 * @return true - if input chars was successfuly received.
 * @return false - otherwise.
 */
bool Menu::recieveTwoDigitsByInt(TwoDigits& twoDigitsByInt)
{
	int number;
	cout << "Enter a number (0-99)" << endl;
	cin >> number;
	if (!(number >= 0 && number <= 99))
	{
		return false;
	}
	twoDigitsByInt.update(number);
	return true;
}

/**
 * @brief creates a Fraction class onject with given inputs and manipulates it based on chosen option.
 * 
 */
void Menu::fractionMenu()
{
	int denominator, numerator;
	float value1, value2;

	cout << "Enter the numerator" << endl;
	cin >> numerator;

	cout << "Enter the denumerator" << endl;
	cin >> denominator;
	
	Fraction fraction(numerator, denominator);

	int menuIndex = 0;
	do
	{
		cout << "\nEnter 1 for update the numerator\nEnter 2 for update the denominator\nEnter 3 for Object printing\nEnter 4 for summation\nEnter 5 for qutting..." << endl;
		cin >> menuIndex;

		//recieve the enter
		cin.ignore(INT64_MAX, '\n');

		switch (menuIndex)
		{
		case 1:
			cout << "Enter the numerator" << endl;
			cin >> numerator;
			fraction.updateNumerator(numerator);
			break;
		case 2:
			cout << "Enter the denumerator" << endl;
			cin >> denominator;
			fraction.updateDenominator(denominator);
			break;
		case 3:
			fraction.printValue();
			break;
		case 4:

			cout << "Enter a fraction in a mantissa format, for example 3.1243" << endl;
			cin >> value1;
			value2 = (double)fraction.value();

			cout << "The sum of ";
			fraction.printValue(false);
			cout << " and " << value1 << " is: " << value1 + value2 << endl;

			break;
		case 5:
			return;
		default:
			break;
		}

	} while (menuIndex != 5);

}

/**
 * @brief creates a String class onject with given inputs and manipulates it based on chosen option.
 * 
 */
void Menu::stringMenu() 
{
	String stringObj;
	int menuIndex = 0, charIndex = 0;
	char userStringInput[10];
	char userInput[2] = { 0 };

	do
	{
		cout << "\nEnter 1 for update the string\nEnter 2 for updating the string values one by one\n"
			"Enter 3 for changing a character at a specific index\nEnter 4 for viewing a specific character at specific index\n"
			"Enter 5 for printing the string\nEnter 6 for printing the string at lowercase format\n"
			"Enter 7 for printing the string at uppercase format\nEnter 8 for qutting the menu...\n";
		cin >> menuIndex;

		// we receive a string afterwards therefore, we need to flush until enter;
		cin.ignore(INT64_MAX, '\n');


		switch (menuIndex)
		{
		case 1:
			cout << "Please enter new string\n" << endl;			
			cin.get(userStringInput, 10);
			cin.ignore(INT64_MAX, '\n');
			stringObj.updateValue(userStringInput);
			break;

		case 2:
			if (!stringObj.setCharsByUser())
			{
				cerr << "index specified is invalid! please try again";
			}
			break;
		case 3:
			cout << "Enter an index to replace a char at (on 0 base)" << endl;
			cin >> charIndex;
			cin.ignore(INT64_MAX, '\n');

			cout << "Enter the char value" << endl;

			// can recieve a space as well in that way.
			cin.get(userInput, 2);
			cin.ignore(INT64_MAX, '\n');
			

			if(!(stringObj.setCharAt(userInput[0], charIndex)))
				cerr << "Warning: index out of bounds! please try again" << endl;
			break;
		case 4:
			cout << "Enter an index (on 0 base)" << endl;
			cin >> charIndex;
			cout << stringObj.getCharAt(charIndex);
			break;
		case 5:
			stringObj.printValue();
			break;
		case 6:
			stringObj.printValue(false);
			break;
		case 7:
			stringObj.printValue(true);
			break;
		case 8:
			return;
		default:
			break;
		}

	} while (menuIndex != 8);
}

