/*
    Selection Problem : for an input of an array of n elements, find
                        the ith order statistic, that is ith smallest 
                        element in the array

    Two Ways of Solving the problem:
        1. Sort the Array and then return array[i]
        2. Similar to quicksort, by choosing a random pivot
           to partition the array and throw out the undesired half
*/

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using std::vector;

// ___First Method: Reduction to Sorting___
// Time Complexity: O(nlogn)
template <typename T>
T select(vector<T>& v, int ord) {   // reduction to sorting method
    // assuming that the order is given as 1-indexed
    std::sort(v.begin(), v.end());
    return v[ord - 1];
}

// ___________The Second Method: Randomized Selection___________
// Time Complexity: O(n)
// partitions the array around a random pivot and returns the index of that pivot
template <typename T> int partition(vector<T>& v, int lo, int hi, std::mt19937& gen) {
    // generate a random index
	std::uniform_int_distribution<int> dist(lo, hi);
	int idx = dist(gen);
	std::swap(v[lo], v[idx]);	// swap with lo

    T pivot = v[lo];
    int i = lo + 1;
    for(int j = lo + 1; j <= hi; j++) {
        if (v[j] < pivot) {
            std::swap(v[j], v[i++]);
        }
    }
    std::swap(v[i - 1], v[lo]);
    return (i - 1);
}

template <typename T>
T helperRselect(vector<T>& v, int ord, int lo, int hi, std::mt19937& gen) {
    if (lo == hi) return v[lo];

    int pivotidx = partition(v, lo, hi, gen);
    int rank = pivotidx - lo + 1;

    if (rank == ord) {
        return v[pivotidx];
    } else if (rank > ord) {
        return helperRselect(v, ord, lo, pivotidx - 1, gen);
    } else {
        return helperRselect(v, ord - rank, pivotidx + 1, hi, gen);
    }
}

template <typename T>
T Rselect(vector<T>& v, int ord) {
    std::random_device rd;
	std::mt19937 gen(rd());
    return helperRselect(v, ord, 0, v.size() - 1, gen);
}

int main() {
    
}
