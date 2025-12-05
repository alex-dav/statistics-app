#include "statistics-app/statistics-lib.hpp"

double calculateAvg(const std::vector<double>& nums) {
    double sum{ 0.0 };
    for (double num : nums) {
        sum += num;
    }
    return sum / nums.size();
}
