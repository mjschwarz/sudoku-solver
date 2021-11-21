#include "Grid.h"
#include <fstream>

Grid::Grid(const std::string &file) : grid(new uint32_t *[N]) {
    for (uint32_t i = 0; i < N; ++i)
        grid[i] = new uint32_t[N];

    std::ifstream infile;
    infile.open(file.c_str());
    std::string val;
    uint32_t row = 0;
    uint32_t col = 0;
    // read every non-whitespace value in the file
    while (infile >> val) {
        grid[row][col] = val[0] - 48;
        ++col;
        if (col % N == 0) {
            col = 0;
            ++row;
        }
    }
}

Grid::~Grid() {
    for (uint32_t i = 0; i < N; ++i)
        delete[] grid[i];
}

void Grid::printGrid() const noexcept {
    std::cout << "-------------------------" << std::endl;
    for (uint32_t row = 0; row < N; ++row) {
        if (row % 3 == 0 && row != 0) std::cout << std::endl;
        for (std::uint32_t col = 0; col < N; ++col) {
            if (col % 3 == 0 && col != 0) std::cout << "    ";
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
    std::cout << std::endl;
}

std::pair<uint32_t, uint32_t> *Grid::findEmpty() const noexcept {
    for (uint32_t row = 0; row < N; ++row) {
        for (uint32_t col = 0; col < N; ++col) {
            if (grid[row][col] == 0)
                return new std::pair<uint32_t, uint32_t>(row, col);
        }
    }
    return nullptr;
}

bool Grid::isValid(uint32_t row, uint32_t col, uint32_t val) const noexcept {
    // row
    for (uint32_t i = 0; i < N; ++i) {
        if (grid[row][i] == val && i != col) return false;
    }
    // col
    for (uint32_t j = 0; j < N; ++j) {
        if (grid[j][col] == val && j != row) return false;
    }
    // box
    uint32_t r = row - row % 3;
    uint32_t c = col - col % 3;

    for (uint32_t m = r; m < r + 3; ++m) {
        for (uint32_t n = c; n < c + 3; ++n) {
            if (grid[m][n] == val && m != row && n != col) return false;
        }
    }
    return true;
}

bool Grid::solve() noexcept {
    std::pair<uint32_t, uint32_t> *nextSquare = findEmpty();
    // check if all squares already solved
    if (nextSquare == nullptr) return true;

    uint32_t row = nextSquare->first;
    uint32_t col = nextSquare->second;

    for (uint32_t val = 1; val <= 9; ++val) {
        if (isValid(row, col, val)) {
            grid[row][col] = val;
            // backtracking
            if (solve()) return true;
            else grid[row][col] = 0;
        }
    }
    return false;
}

