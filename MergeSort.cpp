#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T>& v, int l, int r, int mid, std::vector<T>& aux) {
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (v[i] <= v[j]) {  aux[k++] = v[i++];  }
		else 			  {  aux[k++] = v[j++];  }
	}

	while (i <= mid) {  aux[k++] = v[i++];  }
	while (j <= r)   {  aux[k++] = v[j++];  }
	for(int ldx = l; ldx <= r; ldx++) {
		v[ldx] = aux[ldx];
	}
}

template <typename T>
void mergeSortRecursive(std::vector<T>& v, int l, int r, std::vector<T>& aux) {
	if (l >= r) return;
	int mid = l + (r - l) / 2;
	mergeSortRecursive(v, l, mid, aux);
	mergeSortRecursive(v, mid + 1, r, aux);
	merge(v, l, r, mid, aux);
}

template <typename T>
void sort(std::vector<T>& v) {
	if (v.empty())	return;
	int l = 0, h = (int) v.size() - 1;
	std::vector<T> aux(v.size());
	mergeSortRecursive(v, l, h, aux);
}

int main() {
	
}