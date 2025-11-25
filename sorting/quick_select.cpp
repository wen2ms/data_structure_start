#include <iostream>
#include <utility>
#include <vector>

// Best: O(n) [3, 1, 4, 2, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(n)

int quick_select(std::vector<int>& nums, int left, int right, int nth) {
    if (left == right) {
        return nums[left];
    }
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; ++j) {
        if (nums[j] < pivot) {
            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
    std::swap(nums[i], nums[right]);
    if (i == nth) {
        return nums[i];
    }
    if (i > nth) {
        return quick_select(nums, left, i - 1, nth);
    }
    return quick_select(nums, i + 1, right, nth);
}

int main() {
    std::vector<int> nums{0, 2, 3, 5, 4};
    int nth_elemnt = quick_select(nums, 0, nums.size() - 1, 2);

    std::cout << nth_elemnt << '\n';

    return 0;
}