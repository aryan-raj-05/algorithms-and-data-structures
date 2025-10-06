#include <algorithm>
#include <vector>
using namespace std;

// Time Complexity: O(n + c)
// Space Complexity: O(c), where c is max element in nums
// Limitations of the implementation below:
//    1. not stable
//    2. does not handle negative numbers
void counting_sort(vector<int>& nums) {
    // 1. find the largest number in nums
    int maxItem = *max_element(nums.begin(), nums.end());

    // 2. create bookkeeping array
    vector<int> bookkeeper(maxItem + 1, 0);
    for (int num : nums) {
        bookkeeper[num]++;
    }

    // 3. constructing the sorted array
    int numIter = 0;
    for (int i = 0; i < bookkeeper.size(); i++) {
        while (bookkeeper[i] > 0) {
            nums[numIter++] = i;
            bookkeeper[i]--;
        }
    }
}

// prefix sum counting sort
// same time and space complexity
// but stability of array is maintained,
// it still does not work if array has negative numbers
vector<int> prefix_sum_counting_sort(vector<int>& nums) {
    int maxVal = *max_element(nums.begin(), nums.end());

    vector<int> bookkeeper(maxVal + 1, 0);
    for (int num : nums) {
        bookkeeper[num]++;
    }

    // calculate prefix sum
    for (int i = 1; i <= maxVal; i++) {
        bookkeeper[i] += bookkeeper[i - 1];
    }

    // build output array
    // from the back of nums, find the appropriate position
    // and place it to the output array
    vector<int> output(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
        output[bookkeeper[nums[i]] - 1] = nums[i];
        bookkeeper[nums[i]]--;
    }

    return output;
}