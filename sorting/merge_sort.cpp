#include <iostream>
#include <vector>

// Best: O(nlog(n)) [1, 2, 3, 4, 5]
// Worst: O(nlog(n)) [5, 4, 3, 2, 1]
// Average: O(nlog(n))
// Stable: true [1, 2, 3, 2, 4]

void merge(std::vector<int>& nums, int low, int mid, int high) {
    int size_left = mid - low + 1;
    int size_right = high - mid;
    std::vector<int> left(size_left);
    std::vector<int> right(size_right);

    for (int i = 0; i < size_left; ++i) {
        left[i] = nums[low + i];
    }
    for (int i = 0; i < size_right; ++i) {
        right[i] = nums[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = low;
    while (i < size_left && j < size_right) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            ++i;
        } else {
            nums[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < size_left) {
        nums[k] = left[i];
        ++i;
        ++k;
    }

    while (j < size_right) {
        nums[k] = right[j];
        ++j;
        ++k;
    }
}

void merge_sort(std::vector<int>& nums, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    merge_sort(nums, low, mid);
    merge_sort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

void merge_sort(std::vector<int>& nums) {
    merge_sort(nums, 0, nums.size() - 1);
}

void print(const std::vector<int>& vec) {
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> case_1 = {7, 6, 5, 4, 3, 2};
    std::vector<int> case_2 = {8, 2, 1, 3, 4};
    std::vector<int> case_3 = {1, 2, 3};

    merge_sort(case_1);
    merge_sort(case_2);
    merge_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}