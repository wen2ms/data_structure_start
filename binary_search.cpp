#include <iostream>
#include <vector>

int lower_bound(const std::vector<int>& nums, int target) {
    int nums_count = nums.size();
    int low = 0;
    int high = nums_count;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int upper_bound(const std::vector<int>& nums, int target) {
    int nums_count = nums.size();
    int low = 0;
    int high = nums_count;
    while (low < high) {
        int mid = (low + high) / 2;
        if (nums[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    std::vector<int> case_1{1, 2, 3, 4, 5};
    std::cout << lower_bound(case_1, 3) << ' ' << upper_bound(case_1, 3) << '\n';

    return 0;
}