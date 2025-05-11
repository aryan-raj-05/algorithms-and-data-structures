#include <iostream>
#include <random>
#include <vector>

using std::vector;
using std::swap;

template <typename T>
int splitArray(vector<T>& A, int lo, int hi) {
	// generate a random index
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(lo, hi);
	int idx = dist(gen);

	swap(A[lo], A[idx]);	// swap with lo

	// partition the array around the pivot
	int i = lo + 1;
	T pivot = A[lo];	// pivot is at index lo.
	for(int j = lo + 1; j <= hi; j++){
		if (A[j] < pivot){
			swap(A[j], A[i++]);
		}
	}
	swap(A[i - 1], A[lo]);
	
	return (i - 1);
}

template <typename T>
void QuickSort(vector<T>& A, int lo, int hi) {
	if (lo >= hi)	return;
	int idx = splitArray(A, lo, hi);
	QuickSort(A, lo, idx - 1);
	QuickSort(A, idx + 1, hi);
}

template <typename T>
void sort(vector<T>& A) {
	if (A.empty())	return;
	int lo = 0, hi = (int) A.size() - 1;
	QuickSort(A, lo, hi);
}

int main() {

}