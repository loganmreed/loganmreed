#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdint>  // For uint64_t
using namespace std;

// Fast xorshift32 PRNG (Inline)
inline uint32_t xorshift32(uint32_t* state) {
    *state ^= *state << 13;
    *state ^= *state >> 17;
    *state ^= *state << 5;
return *state;
}

int main() {
    uint32_t seed = 2463534242u;  // Initial PRNG seed
    uint64_t numberOfTosses;

    cout << "Enter how many times you want me to roll the die: ";
    cin >> numberOfTosses;

    uint64_t counts[6] = {0};  // Use uint64_t for large counts

    auto startRoll = chrono::high_resolution_clock::now();

    // Efficient Loop for Fast PRNG Rolling
    int i = 0, unrollLimit = numberOfTosses / 8 * 8;
    for (; i < unrollLimit; i += 8) {
        uint32_t roll1 = xorshift32(&seed) % 6;
        uint32_t roll2 = xorshift32(&seed) % 6;
        uint32_t roll3 = xorshift32(&seed) % 6;
        uint32_t roll4 = xorshift32(&seed) % 6;
        uint32_t roll5 = xorshift32(&seed) % 6;
        uint32_t roll6 = xorshift32(&seed) % 6;
        uint32_t roll7 = xorshift32(&seed) % 6;
        uint32_t roll8 = xorshift32(&seed) % 6;

        counts[roll1]++;
        counts[roll2]++;
        counts[roll3]++;
        counts[roll4]++;
        counts[roll5]++;
        counts[roll6]++;
        counts[roll7]++;
        counts[roll8]++;
    }

    // Handle remaining rolls
    for (; i < numberOfTosses; i++) {
        counts[xorshift32(&seed) % 6]++;
    }
    auto endRoll = chrono::high_resolution_clock::now();
    chrono::duration<double> rollTime = endRoll - startRoll;

    cout << "\nTotal Roll Time: " << rollTime.count() << " seconds\n\n";

    // Display counts and calculate total sum for statistics.
    uint64_t totalSum = 0, maxCount = 0, mode = 0;
    for (int j = 0; j < 6; j++) {
        cout << "Count for die value " << (j + 1) << ": " << counts[j] << endl;
        totalSum += counts[j] * (j + 1);
        if (counts[j] > maxCount) {
            maxCount = counts[j];
            mode = j;
        }
    }

    auto startStats = chrono::high_resolution_clock::now();

    // Calculate Mean.
    double mean = static_cast<double>(totalSum) / numberOfTosses;

    // Calculate Median.
    int cumulativeCount = 0, median = 0;
    for (int j = 0; j < 6; j++) {
        cumulativeCount += counts[j];
        if (cumulativeCount >= numberOfTosses / 2) {
            median = j + 1;
            break;
        }
    }

    // Calculate Range.
    uint64_t minCount = counts[0], maxRollCount = counts[0];
    for (int j = 1; j < 6; j++) {
        if (counts[j] < minCount) minCount = counts[j];
        if (counts[j] > maxRollCount) maxRollCount = counts[j];
    }
    int range = maxRollCount - minCount;

    // Calculate Variance and Standard Deviation.
    double variance = 0.0;
    for (int j = 0; j < 6; j++) {
        double diff = (j + 1) - mean;
        variance += counts[j] * diff * diff;
    }
    variance /= numberOfTosses;
    double stdDev = sqrt(variance);

    // Chi-Square Test for Fairness.
    double expected = numberOfTosses / 6.0;
    double chiSquare = 0.0;
    for (int j = 0; j < 6; j++) {
        double diff = counts[j] - expected;
        chiSquare += (diff * diff) / expected;
    }

    auto endStats = chrono::high_resolution_clock::now();
    chrono::duration<double> statsTime = endStats - startStats;

    // Output computed statistics.
    cout << "\nStatistics:\n";
    cout << "Mean (Average): " << mean << endl;
    cout << "Mode: " << (mode + 1) << " (appeared " << maxCount << " times)\n";
    cout << "Median: " << median << endl;
    cout << "Range (Max - Min Count): " << range << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard Deviation: " << stdDev << endl;
    cout << "Chi-Square Value: " << chiSquare << " (Lower is better for fairness)\n";
    cout << "Expected Probability: 16.67% for each number (1/6)\n";
    cout << "Statistics Calculation Time: " << statsTime.count() << " seconds\n";

    uint64_t totalCount = 0;
    for (int i = 0; i < 6; i++) {
        totalCount += counts[i];
    }
    cout << "Total Count of Rolls: " << totalCount << endl;
    cout << "Expected Rolls: " << numberOfTosses << endl;
    
    // RNG Info
    cout << "\nRandom Number Generator Info:\n";
    cout << "Uses an inline xorshift32 PRNG for fast, thread-local random generation.\n";
    cout << "Formula: xorshift32(&seed) % 6 (Generates values from 0 to 5)\n";
    cout << "Die values are adjusted by adding 1 (Final range: 1 to 6).\n";
    cin.ignore();
    cin.get();
    return 0;
}