
// Bubble sort, Gnome sort, Selection sort, Insertion sort, Shell sort, Quicksort, Merge sort, Radix sort

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <random>
#include <chrono>
#include <functional>
#include <string>
#include <iomanip>
#include <limits>


// Referenced from geeksfogeeks: https://www.geeksforgeeks.org/cpp/bubble-sort-in-cpp/
 void bubbleSort(std::vector<int>& v) {
int n = v.size();

    // Outer loop that corresponds to the number of
    // elements to be sorted
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already
        // in place
        for (int j = 0; j < n - i - 1; j++) {
          
          	// Comparing adjacent elements
            if (v[j] > v[j + 1])
              
              	// Swapping if in the wrong order
                std::swap(v[j], v[j + 1]);
        }
    }
}

// Referenced from: https://www.geeksforgeeks.org/dsa/gnome-sort-a-stupid-one/
void gnomeSort(int arr[], int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}
// Referenced from: https://learn.zybooks.com/zybook/SDSUCS210DabishFall2025/chapter/3/section/2
void SelectionSort(int* numbers, int numbersSize) {
   for (int i = 0; i < numbersSize - 1; i++) {
      // Find index of smallest remaining element
      int indexSmallest = i;
      for (int j = i + 1; j < numbersSize; j++) {
         if (numbers[j] < numbers[indexSmallest]) {
            indexSmallest = j;
         }
      }
     
      // Swap numbers[i] and numbers[indexSmallest]
      int temp = numbers[i];
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
   }
}

// Referenced from: http://learn.zybooks.com/zybook/SDSUCS210DabishFall2025/chapter/3/section/4
void InsertionSortInterleaved(int* numbers, int numbersSize, int startIndex, int gap) {
   for (int i = startIndex + gap; i < numbersSize; i += gap) {
      int j = i;
      while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
         int temp = numbers[j];
         numbers[j] = numbers[j - gap];
         numbers[j - gap] = temp;
         j -= gap;
      }
   }
}

// Referenced from: https://www.geeksforgeeks.org/dsa/shell-sort/
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

// Referenced from zybooks: https://learn.zybooks.com/zybook/SDSUCS210DabishFall2025/chapter/3/section/5
// the QuickSort function implementation

int Partition(int* numbers, int lowIndex, int highIndex) {
   // Pick middle element as the pivot
   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   int pivot = numbers[midpoint];
 
   bool done = false;
   while (!done) {
      while (numbers[lowIndex] < pivot) {
         lowIndex++;
      }
      while (pivot < numbers[highIndex]) {
         highIndex--;
      }
    
      // If lowIndex and highIndex have met or crossed each
      // other, then partitioning is done
      if (lowIndex >= highIndex) {
         done = true;
      }
      else {
         // Swap numbers[lowIndex] and numbers[highIndex]
         int temp = numbers[lowIndex];
         numbers[lowIndex] = numbers[highIndex];
         numbers[highIndex] = temp;

         // Update lowIndex and highIndex
         lowIndex++;
         highIndex--;
      }
   }
   return highIndex;
}

//Referenced from Zybooks: https://learn.zybooks.com/zybook/SDSUCS210DabishFall2025/chapter/3/section/6
void Merge(int* numbers, int leftFirst, int leftLast,
   int rightLast) {
   int mergedSize = rightLast - leftFirst + 1;
   int* mergedNumbers = new int[mergedSize];
   int mergePos = 0;
   int leftPos = leftFirst;
   int rightPos = leftLast + 1;
  
   while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
      }
      mergePos++;
   }
  
   while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
   }
   while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
   }
   for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
   }
   delete[] mergedNumbers;
}

// Referneced from Zybooks: https://learn.zybooks.com/zybook/SDSUCS210DabishFall2025/chapter/3/section/7
// Returns the length, in number of digits, of an integer value
int RadixGetLength(int value) {
   if (value == 0) {
      return 1;
   }
      
   int digits = 0;
   while (value != 0) {
      digits++;
      value /= 10;
   }
   return digits;
}

// Returns the maximum length, in number of digits, out of all array elements
int RadixGetMaxLength(const int* numbers, int numbersSize) {
   int maxDigits = 0;
   for (int i = 0; i < numbersSize; i++) {
      int digitCount = RadixGetLength(numbers[i]);
      if (digitCount > maxDigits) {
         maxDigits = digitCount;
      }
   }
   return maxDigits;
}
void RadixSort(int* array, int arraySize) {
   std::vector<std::vector<int>> buckets(10);

   int digitIndex;
   int maxDigits = RadixGetMaxLength(array, arraySize);
    
   // Start with the least significant digit
   int pow10 = 1;
   for (digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
      for (int i = 0; i < arraySize; i++) {
         int bucketIndex = abs(array[i] / pow10) % 10;
         buckets[bucketIndex].push_back(array[i]);
      }
      int copyBackIndex = 0;
      for (int i = 0; i < 10; i++) {
         for (int j = 0; j < buckets[i]->size(); j++) {
            array[copyBackIndex] = buckets[i].at(j);
            copyBackIndex++;
         }
         buckets[i].clear();
      }
      pow10 *= 10;
   }
}



// ---------- example comparator to demonstrate operator effects ----------
struct OddFirstAsc {
    bool operator()(int a, int b) const {
        const bool ao = a & 1, bo = b & 1;
        if (ao != bo) return ao > bo; // odds first
        return a < b;                 // within parity, ascending
    }
};

// ---------- if your algorithms accept (It, It, Compare), you're set ----------
// If some of your functions don't take a comparator, just ignore `comp` in the wrapper.

// Example: if you already defined gnome_sort(It, It, Compare) somewhere above, it will work.
// If you have other algorithms like insertion_sort, selection_sort, etc., register them below.

// ---------- data generation ----------
enum class InputKind { Random, Sorted, Reverse };

std::vector<int> make_data(size_t n, InputKind kind, uint64_t seed=42) {
    std::vector<int> v(n);
    if (kind == InputKind::Sorted) {
        iota(v.begin(), v.end(), 0);
    } else if (kind == InputKind::Reverse) {
        iota(v.begin(), v.end(), 0);
        reverse(v.begin(), v.end());
    } else {
        std::mt19937_64 rng(seed);
        std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
        for (auto& x : v) x = dist(rng);
    }
    return v;
}

// ---------- timing helper ----------
template<class F>
double time_ms(F&& f) {
    auto t0 = chrono::steady_clock::now();
    f();
    auto t1 = chrono::steady_clock::now();
    return chrono::duration<double, milli>(t1 - t0).count();
}

// ---------- register your algorithms here ----------
template <class It, class Comp>
using Algo = function<void(It, It, Comp)>;

struct AlgoEntry {
    std::string name;
    Algo<std::vector<int>::iterator, function<bool(const int&, const int&)>> run;
    bool is_n2 = false; // mark O(n^2) sorts to optionally skip for very large n
};

int main() {
    std::ios::sync_with_stdio(false);
    srcin.tie(nullptr);

    // Comparators to test
    vector<pair<string, function<bool(const int&, const int&)>>> comps = {
        {"std::less (asc)", less<>()},
        {"std::greater (desc)", greater<>()},
        {"OddFirstAsc", OddFirstAsc{}}
    };

    // ---- Add your algorithms here. Replace the lambdas with calls to YOUR functions. ----
    vector<AlgoEntry> algos;

    // Example wrappers:
    // If you have: void gnome_sort(It, It, Compare)
    // algos.push_back({"Gnome", [](auto f, auto l, auto comp){ gnome_sort(f, l, comp); }, true});

    // If you have: void insertion_sort(It, It)  (no comparator), you can ignore comp:
    // algos.push_back({"Insertion", [](auto f, auto l, auto /*comp*/){ insertion_sort(f, l); }, true});

    // Baseline with std::sort (allowed for comparison)
    algos.push_back({"std::sort", [](auto f, auto l, auto comp){ std::sort(f, l, comp); }, false});

    if (algos.empty()) {
        cerr << "Register at least one algorithm in `algos`.\n";
        return 1;
    }

    // Sizes (feel free to tweak)
    vector<size_t> sizes = {1'000, 10'000, 100'000};

    // For O(n^2) sorts, you may want to cap the largest size to avoid very long runs
    const size_t N2_CAP = 20'000; // change or set to big number to force run

    // Inputs to test
    vector<pair<string, InputKind>> inputs = {
        {"Random",  InputKind::Random},
        {"Sorted",  InputKind::Sorted},
        {"Reverse", InputKind::Reverse}
    };

    // Trials (random input): run multiple and report min/avg/max
    const int random_trials = 3;

    cout << fixed << setprecision(2);

    for (auto [cname, comp] : comps) {
        cout << "\n=== Comparator: " << cname << " ===\n";
        // header
        cout << left << setw(14) << "Algorithm"
             << setw(10) << "Size"
             << setw(10) << "Input"
             << right << setw(10) << "Best(ms)"
             << setw(10) << "Avg(ms)"
             << setw(10) << "Worst(ms)"
             << "\n";

        for (auto n : sizes) {
            for (auto [iname, ik] : inputs) {
                for (const auto& A : algos) {
                    if (A.is_n2 && n > N2_CAP) continue; // skip too-large runs for n^2 sorts

                    vector<double> times;
                    int trials = (ik == InputKind::Random ? random_trials : 1);

                    for (int t = 0; t < trials; ++t) {
                        // Fresh data each trial
                        auto data = make_data(n, ik, /*seed*/ 42 + t);
                        // Bind comparator (type-erased to function<> to satisfy AlgoEntry)
                        function<bool(const int&, const int&)> c = comp;

                        // Time it
                        double ms = time_ms([&]{
                            A.run(data.begin(), data.end(), c);
                        });

                        // Validate (ascending check for less<>; for others, you can relax or adapt)
                        // Simple correctness check: using the same comparator
                        if (!is_sorted(data.begin(), data.end(), c)) {
                            cerr << "Not sorted! Algo=" << A.name
                                 << " n=" << n << " input=" << iname
                                 << " comparator=" << cname << "\n";
                            return 2;
                        }

                        times.push_back(ms);
                    }

                    double best = *min_element(times.begin(), times.end());
                    double worst = *max_element(times.begin(), times.end());
                    double avg = accumulate(times.begin(), times.end(), 0.0) / times.size();

                    cout << left << setw(14) << A.name
                         << setw(10) << n
                         << setw(10) << iname
                         << right << setw(10) << best
                         << setw(10) << avg
                         << setw(10) << worst
                         << "\n";
                }
            }
        }
    }

    return 0;
}