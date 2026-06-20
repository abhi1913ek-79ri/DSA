#include <iostream>
#include <vector>
#include <ctime>     // For clock() and time()
#include <cstdlib>   // For rand() and srand()
#include <algorithm> // For std::swap
#include <fstream>   // For file output

using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        // Early exit if no swaps were made in this pass
        if (!swapped)
            break;
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Create and open the CSV file
    ofstream fout("bubble_sort_times.csv");
    if (!fout.is_open()) {
        cerr << "Error opening file for output!" << endl;
        return 1;
    }

    // Write the header row for the CSV file
    fout << "InputSize,TimeSeconds" << "\n";

    // Iterate over different input sizes
    for (int n = 100; n <= 5000; n += 100) {
        vector<int> arr(n);

        // Fill the array with random numbers in a chosen range (e.g., 0 to 9999)
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;
        }

        // Measure execution time of bubble_sort
        clock_t start = clock();
        bubble_sort(arr);
        clock_t end = clock();

        // Calculate time taken in seconds
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // Write the input size and execution time to the CSV file
        fout << n << "," << time_taken << "\n";

        // Also print to console for feedback
        cout << "Sorted array of size " << n << " in " << time_taken << " seconds." << endl;
    }

    fout.close();
    cout << "\nData saved in 'bubble_sort_times.csv'. Use a graphing tool to plot InputSize vs. TimeSeconds." << endl;
    return 0;
}
