#include "statistics-app/statistics-lib.hpp"

double calculateAvg(const std::vector<double>& numsForAvg) {
    double sum{ 0.0 };
    for (const double numForAvg : numsForAvg) {
        sum += numForAvg;
    }
    return sum / numsForAvg.size();
}

void changeByPct(std::vector<double>& numsForPct, const double pct) {
    for (double& numForPct : numsForPct) {
        numForPct += numForPct * pct / 100.0;
    }
}
