#pragma once




/**
 * Class that represents a Cell in a table.
 * The Cell has ID (ex: A1/B14/C24/Z2000)
 * and a value (int/ double/ string/ operation)
 */
class Cell{
private:
  const char* name;  /**< ID of the Cell*/

public:
  /**
   * Constructor, creates Cell with *ID* and *Value*
   * @param ID -> ID of the Cell that has to be created
   */
  explicit Cell(const char* ID);
  /**
   * @brief destructor, made virtual, because the class is abstract
   */
  virtual ~Cell();
  /**
   * @brief deleted copyconstructor to not cause errors
   */
  Cell(const Cell&) = delete;
  /**
   * @brief deleted operator= to not cause errors
   */
  Cell &operator= (const Cell&) = delete;
  /**
   * @brief redefined operator<< to print out cell information
   * @param out -> stream
   * @param cell -> pointer to cell that has to be printed
   * @returns the stream that has the value of the cell
   */
  friend std::ostream& operator<<(std::ostream& out, const Cell* cell);

  /**
   * @brief virtual setter of the value so all celltypes can get their value set
   * @param value -> string that represents the value that has to be set
   */
  virtual void setValue(const char* value) = 0;
  /**
   * @brief virtual getter of value
   * @returns string that has the value of the celltype
   */
  virtual const char* getValue() const = 0;
  /**
   * @brief virtual copy function to create new Cells
   * @returns a pointer to a Celltype
   */
  virtual Cell* copy()=0;
  /**
   * @brief getter of Cell ID
   * @returns the ID of the cell
   */
  const char* getName() const;
  /**
   * Virtual function that gets the Cell type.
   * @returns a string that represents the cell type("int"/"double"/"string"/"formula")
   */
  virtual const char* getCellType() = 0;
};








