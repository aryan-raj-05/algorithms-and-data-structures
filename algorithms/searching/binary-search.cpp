#include <stdexcept>
#include <vector>

template <typename T>
bool isSorted(const std::vector<T>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums.at(i) > nums.at(i + 1)) return false;
    }
    return true;
}

template <typename T>
int bin_search(const std::vector<T>& nums, const T val) {
    if (!isSorted(nums)) {
        throw std::runtime_error("Given array not sorted");
    }

    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums.at(mid) == val) return mid;
        else if (nums.at(mid) > val) hi = mid - 1;
        else lo = mid + 1;
    }

    return -1;
}