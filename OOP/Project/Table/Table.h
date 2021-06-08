#pragma once
#include "../Cell/Cell.h"

class Table{
private:
  static Table* instance;  /**< instance of the table, implementing singleton
                              * @see  Table* getInstance() */
  std::vector<Cell> table; /**< vector of type Cell (the table itself), holds all Cells with their ID and Value */
  Table(){} /**< Default constructor of Table, has to be initialised here to maintain the singleton template */
public:
  /**
   * @brief gets the instance of the Table or creates new if there isn't one
   * @returns the instance of the Table
   */
  static Table* getInstance(){
    if(!instance){
      instance = new Table;
    }
    return instance;
  }

  /**
   * @brief prints the table on the console
   */
  void printTable();

  /**
   * @brief edits the Cell with ID *where* in the table with the value *value*
   * @param where -> Cell ID
   * @param value -> Cell value (number, string or operation)
   */
  void editMember(const char* where, const char* value);

  /**
   * @brief gets the Cell at position *where* from the table
   * @param where -> Cell ID
   * @returns Cell at ID *where* from the table vector
   */
  Cell* getCell(const char* where);

  /**
   * @brief pushes the Cell *cell* at the back of the table vector
   * @param cell -> Cell to be added to the Table.
   */
  void addCell(Cell& cell);

  /**
   * @brief public function to get the table vector, if needed.
   * @return the vector with cells from Table
   */
  std::vector<Cell>& getTable();

  /**
   * Gets the maximum space taken from a value in the given column (*a*)
   * @param a -> char representing the column
   * @returns the maximum space that a value of a Cell in the table takes in the given column.
   */
  int getMaxWhitespace(char a);
};