#include <iostream>
#include <vector>
#include <random>

using std::vector;

/*
    Inversion: For a given input of array A, let i, j be two numbers 
    such that i < j, then an inversion is when A[i] > A[j]

    In a sorted array the number of inversions in 0, the minimum number
    of inversions.

    And the maximum number of inversions an array of length n can have
    is nC2 = n(n-1)/2. Which will happen when the array is in descending 
    order
*/

int countInversionBruteForce(vector<int> &A) {
    int count = 0;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            if (A[i] > A[j]) {  count++;  }
        }
    }
    return count;
}

int countSplitInv(vector<int>& A, vector<int>& aux, int lo, int hi, int mid) {
    int count = 0;
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi) {
        if (A[i] > A[j]) {
            aux[k++] = A[j++];
            count += (mid - i + 1);
        } else {  
            aux[k++] = A[i++];
        }
    }

    while (i <= mid) {  aux[k++] = A[i++];  }
    while (j <= hi)  {  aux[k++] = A[j++];  }

    for(int idx = lo; idx <= hi; idx++) {  A[idx] = aux[idx];  }

    return count;
}

int helperCountInv(vector<int>& A, vector<int>& aux, int lo, int hi) {
    if (lo >= hi)   return 0;
    int mid = lo + (hi - lo) / 2;
    int leftInv = helperCountInv(A, aux, lo, mid);
    int rightInv = helperCountInv(A, aux, mid + 1, hi);
    int splitInv = countSplitInv(A, aux, lo, hi, mid);
    return (leftInv + rightInv + splitInv);
}

int countInversionDnC(vector<int>& A) {
    vector<int> aux(A.size());
    return helperCountInv(A, aux, 0, A.size() - 1);
}

int main() {

}