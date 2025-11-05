#include <iostream>
#include <vector>

// Best: O(nlog(n)) [1, 2, 3, 4, 5]
// Worst: O(nlog(n)) [5, 4, 3, 2, 1]
// Average: O(nlog(n))
// Stable: true [1, 2, 3, 2, 4]

void merge(int low, int mid, int high, std::vector<int>& nums) {
    int left_count = mid - low + 1;
    int right_count = high - mid;
    std::vector<int> left(left_count);
    std::vector<int> right(right_count);
    for (int i = 0; i < left_count; ++i) {
        left[i] = nums[low + i];
    }
    for (int i = 0; i < right_count; ++i) {
        right[i] = nums[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < left_count && j < right_count) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            ++i;
        } else {
            nums[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left_count) {
        nums[k] = left[i];
        ++i;
        ++k;
    }
    while (j < right_count) {
        nums[k] = right[j];
        ++j;
        ++k;
    }
}

void merge_sort(int low, int high, std::vector<int>& nums) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(low, mid, nums);
    merge_sort(mid + 1, high, nums);
    merge(low, mid, high, nums);
}

void merge_sort(std::vector<int>& nums) {
    merge_sort(0, nums.size() - 1, nums);
}

void print(const std::vector<int>& nums) {
    for (const int num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> case_1{7, 6, 5, 4, 3, 2};
    std::vector<int> case_2{8, 2, 1, 3, 4};
    std::vector<int> case_3{1, 2, 3};

    merge_sort(case_1);
    merge_sort(case_2);
    merge_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}