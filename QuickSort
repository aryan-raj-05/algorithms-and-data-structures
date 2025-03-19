#include <iostream>
#include <random>
#include <vector>

template <typename T>
int splitArray(std::vector<T>& A, int lo, int hi) {
	// generate a random index
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(lo, hi);
	int idx = dist(gen);

	std::swap(A[lo], A[idx]);	// swap with lo

	// partition the array around the pivot
	int i = lo + 1;
	T pivot = A[lo];	// pivot is at index lo.
	for(int j = lo + 1; j <= hi; j++){
		if (A[j] < pivot){
			std::swap(A[j], A[i++]);
		}
	}
	std::swap(A[i - 1], A[lo]);
	
	return (i - 1);
}

template <typename T>
void QuickSort(std::vector<T>& A, int lo, int hi) {
	if (lo >= hi)	return;
	int idx = splitArray(A, lo, hi);
	QuickSort(A, lo, idx - 1);
	QuickSort(A, idx + 1, hi);
}

template <typename T>
void sort(std::vector<T>& A) {
	if (A.empty())	return;
	int lo = 0, hi = (int) A.size() - 1;
	QuickSort(A, lo, hi);
}

int main() {

	std::vector<int> v = {10,9,8,7,6,5,4,3,2,1,0};
	sort(v);

	for(auto x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}