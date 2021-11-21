#ifndef SUDOKUSOLVER_GRID_H
#define SUDOKUSOLVER_GRID_H


/**
 * Size of the sudoku grid (9x9).
 */
const uint32_t N = 9;

/**
 * Represents a 9x9 sudoku grid to be solved.
 */
class Grid {
public:
    /**
     * Initializes a sudoku grid using a user-inputted .txt file
     * containing grid values.
     * @param file - file path of the .txt file
     */
    explicit Grid(const std::string &file);

    ~Grid();

    /**
     * Prints a formatted sudoku grid to the console.
     */
    void printGrid() const noexcept;

    /**
     * Finds the next empty square in the grid.
     * @return a ptr to a pair representing the (row, col) of the empty
     *          square if one exists, else nullptr
     */
    [[nodiscard]] std::pair<uint32_t, uint32_t> *findEmpty() const noexcept;

    /**
     * Checks whether the chosen value for a square is valid within the
     * sudoku ruleset. (Value cannot be repeated within the same row, col, or box).
     * @param row - row of the current square
     * @param col - column of the current square
     * @param val - value currently being tried
     * @return true if the value choice is valid, false otherwise
     */
    [[nodiscard]] bool isValid(uint32_t row, uint32_t col, uint32_t val) const noexcept;

    /**
     * Solves a sudoku grid using recursive backtracking.
     * @return true if a solution is found, false otherwise
     */
    bool solve() noexcept;


private:
    /**
     * Sudoku grid to be solved.
     */
    uint32_t **grid;
};

#endif //SUDOKUSOLVER_GRID_H
