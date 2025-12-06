#include "statistics-app/statistics-lib.hpp"
#include <cassert>
#include <cmath>

static constexpr bool equalWithTolerance(const std::vector<double>& a, const std::vector<double>& b);

int main() {
    std::vector<double> testNums1{
        2.0, 3.0, 4.0, 5.0, 6.0
    };
    std::vector<double> testNums2{
        -5.0, 10.0, 2.0, -6.0, 8.0
    };
    std::vector<double> testNums3{
        -0.2, 0.5, 2.0, 7.0, 1.4
    };
    assert(calculateAvg(testNums1) == 4.0);
    assert(calculateAvg(testNums2) == 1.8);
    assert(calculateAvg(testNums3) == 2.14);

    changeByPct(testNums1, 20);
    std::vector<double> testNums1Expected{
        2.4, 3.6, 4.8, 6.0, 7.2
    };
    changeByPct(testNums2, -80);
    
    std::vector<double> testNums2Expected{
        -1.0, 2.0, 0.4, -1.2, 1.6
    };
    changeByPct(testNums3, -15.6);
    std::vector<double> testNums3Expected{
        -0.1688, 0.422, 1.688, 5.908, 1.1816
    };
    assert(equalWithTolerance(testNums1, testNums1Expected));
    assert(equalWithTolerance(testNums2, testNums2Expected));
    assert(equalWithTolerance(testNums3, testNums3Expected));
}

static constexpr bool equalWithTolerance(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) {
        return false;
    }

    const double epsilon = 0.0001;
    for (std::size_t i{ 0 }; i < a.size(); i++) {
        if (std::fabs(a.at(i) - b.at(i)) > epsilon) {
            return false;
        }
    }
    return true;
}
