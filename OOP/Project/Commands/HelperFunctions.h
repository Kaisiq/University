#pragma once

/**
 * @brief converts a string to low-cases only.
 * @param str-> gets converted to low-cases only.
 * @return char arr with only low-case chars.
 */
char* tolower(const char* str);

/**
 * @brief Validates a cell, by checking if it is correctly given.
 * @param cell -> gets validated
 * @returns true if the cell is valid.
 * @returns false if the cell isn't valid.
 */
bool isValidCell(const char* cell);



/**
 * @brief Validates if the given char* is a number (contains only numbers)
 * @param number -> char array representing the number that has to be validated.
 * @returns true if the number is valid
 * @returns false if the number is not valid
 */
bool isValidNumber(const char* number);

/**
 * @brief Validates if the given char* is a number of type double.
 * @param number -> char array representing the number that has to be validated.
 * @returns true if the number is a valid double.
 * @returns false if the number isn't a valid double.
 */
bool isValidDouble(const char* number);

/**
 * @brief Validates if the given char* is a string (example: "Hello world" <---- string)
 * @param str -> char array representing the string that has to be validated.
 * @returns true if the parameter is a valid string.
 * @returns false if the parameter isn't a valid string.
 */
bool isValidString(const char* str);

/**
 * @brief Counts how much operations of type  +,-,*,/ there are in the given char*
 * @param str -> char array that has operations of type +,-,*,/
 * @returns the count of the operations ('+', '-', '*', '/')
 */
int operationsCount(const char* str);

/**
 * @brief Counts how much operands the given char* has.
 * @param str -> char array that has operands
 * @returns the count of the operands.
 */
int operandsCount(const char* str);

/**
 * @brief Gets the operand on position n from the char arr str
 * @param n -> position of the operand you want.
 * @param str -> string with operands.
 * @returns the operand at position n from the char arr
 */
const char* getOperand(int n, const char* str);

/**
 * @brief Gets the operator on position n from the char arr str
 * @param n -> position of the operator you want.
 * @param str -> string with operators.
 * @returns the operator at position n from the char arr
 */
const char getOperator(int n, const char* str);

/**
 * @brief Validates if the given char arr is an operation (starts with =, has operations and operands in it)
 * @param str -> gets validated for an operation
 * @returns true if the parameter is a valid operation
 * @returns false if the parameter isn't a valid operation
 */
bool isValidOperation(const char* str);

/**
 * @brief Converts the given char arr to int
 * @param str -> gets converted to int
 * @returns the number from the string but with type int.
 */
int strToInt(const char* str);


/**
 * @brief removes the quotes from the given char arr, if it has those
 * @param value -> gets its quotes removed, if it has
 * @returns char arr without quotes
 */
const char* stringWithoutQuotes(const char* value);

/**
 * @brief template function that converts a given char arr to a number
 * @tparam T -> either double ot int, depending on the situation
 * @param str -> char arr to be converted
 * @returns a number of type T
 */
template <typename T>
T convertToNumber(const char* str);


/**
 * @brief checks if the given string has at least one number of type double and if it has a division as an operator
 * @param str -> gets checked for number and operator '/'
 * @returns true if the string has at least one double or has division in it
 * @returns false if it has none numbers of type double and no division in it
 */
bool hasAtleastOneDoubleOrHasDivision(const char* str);

/**
 * @brief calculates the operations in the given string
 * @tparam T -> either double or int, depends on the situation
 * @param str -> string to be calculated
 * @returns the result of the calculation in a string
 * @note ---- the template is used for the function "convertToNumber"
 * @see template <typename T> T convertToNumber(const char* str);
 */
template <typename T>
std::string calculateOperation(const char* str);

/**
 * @brief removes the whitespaces in a string
 * @param str -> gets its whitespaces removed
 * @returns a string without whitespaces
 */
const char* withoutSpaces(const char* str);


/**
 * @brief validates the input of the user
 * @param str -> gets validated (if it is a valid number/ valid string/ valid operation)
 * @returns true if the input is valid and can be used
 * @returns false if the input isn't valid and cannot be used
 * @see isValidString(const char* str)
 * @see isValidNumber(const char* number)
 * @see isValidDouble(const char* number)
 * @see isValidOperation(const char* str)
 */
bool isValidInput(const char* str);

/**
 * @brief returns the biggest character of a cell name in the table
 * @param vector -> Vector of type Cell (the table itself)
 * @returns the biggest column char (biggest character from the cell names)
 */
char getMaxChar(const std::vector<Cell*>& vector);

/**
 * @brief converts the width from int to char to be printed as a letter
 * @param width -> gets converted to char
 * @returns char that represents the column of the cell
 */
char widthToChar(int width);

/**
 * @brief gets the number part of the cell ID
 * @param name -> the cell ID
 * @returns number that represents the row of the cell
 */
char* getNumFromName(const char* name);


/**
 * @brief gets the biggest number from a cell ID in the table
 * @param vector -> vector of type Cell (the table itself)
 * @returns the biggest number from a cell ID in the table
 */
int getMaxNum(const std::vector<Cell*>& vector);

/**
 * @brief checks for infinite loop formulas
 * @param ID -> ID of Cell that has the formula
 * @param formula -> the formula of the cell
 * @returns true if there is a infinite loop
 * @returns false if there is no infinite loop
 */
bool checkForInfiniteLoopFormulas(Cell* cell, const char* formula);

/**
 * @brief checks if a FormulaCell with a Cell in its value has "#ERROR" in its operands
 * @param str -> gets their operands checked
 * @returns true if the operand char* is "#ERROR"
 * @returns false if the operand char* isn't "#ERROR"
 */
bool checkForError(const char* str);

/**
 * @brief checks if a char* representing a number is a valid int
 * @param number -> char* that gets checked
 * @returns true if the parameter is a valid int
 * @returns false if the parameter is not a valid int
 */
bool isValidInt(const char* number);

#include "../Table/Table.h"
#include "HelperFunctions.cpp"
