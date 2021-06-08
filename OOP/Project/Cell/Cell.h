#pragma once

/**
 * Class that represents a Cell in a table.
 * The Cell has ID (ex: A1/B14/C24/Z2000)
 * and a value (number/ string/ operation)
 */
class Cell{
private:
  const char* name;  /**< ID of the Cell*/
  const char* value; /**< value of the Cell*/

public:
  /**
   * Constructor, creates Cell with *ID* and *Value*
   * @param ID -> ID of the Cell that has to be created
   * @param Value -> Value of the Cell that has to be created
   */
  Cell(const char* ID, const char* Value);

  /**
   * @brief replaces the Value of the Cell with the given parameter
   * @param newValue -> Value to be placed as new Value of the Cell
   */
  void changeValue(const char* newValue);

  /**
   * @brief getter of Value
   * @returns the Value of the Cell
   */
  const char* getValue() const;

  /**
   * @brief getter of ID
   * @returns the ID of the Cell
   */
  const char* getName() const;
};










