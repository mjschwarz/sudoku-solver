#include <iostream>
#include "Grid.cpp"


/**
 * Gets the user-inputted file path for the file
 * which contains the grid values.
 * @return file path as a string
 */
std::string getFileInput() noexcept {
    std::string file;
    std::cout << "Read the 'Functionality' section of README.md for required file format." << std::endl;
    std::cout << "Provide the relative path for the sudoku file: ";
    std::cin >> file;
    std::cout << std::endl;
    return file;
}

int main() {
    Grid grid = Grid(getFileInput());

    std::cout << "UNSOLVED Grid." << std::endl;
    grid.printGrid();

    if (grid.solve()) {
        std::cout << "SOLVED Grid." << std::endl;
        grid.printGrid();
    } else std::cout << "No Solution Found!" << std::endl;
}