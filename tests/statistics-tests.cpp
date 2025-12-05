#include "statistics-app/statistics-lib.hpp"
#include <cassert>

int main() {
    std::vector<double> testNums{
        2, 3, 4, 5, 6
    };
    assert(calculateAvg(testNums) == 4);
}
