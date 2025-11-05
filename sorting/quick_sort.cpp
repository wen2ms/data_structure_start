#include <iostream>
#include <vector>

// Best: O(nlog(n)) [3, 1, 4, 2, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(nlog(n))
// Stable: false [2, 2, 1]

void quick_sort(int left, int right, std::vector<int>& nums) {
    if (left < right) {
        int i = left;
        int j = right;
        int pivot = nums[left];
        while (i < j) {
            while (i < j && nums[j] >= pivot) {
                --j;
            }
            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[left]);
        quick_sort(left, i - 1, nums);
        quick_sort(i + 1, right, nums);
    }
}

void quick_sort(std::vector<int>& nums) {
    quick_sort(0, nums.size() - 1, nums);
}

void print(const std::vector<int>& vec) {
    for (const int num : vec) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> case_1{7, 6, 5, 4, 3, 2};
    std::vector<int> case_2{8, 2, 1, 3, 4};
    std::vector<int> case_3{1, 2, 3};

    quick_sort(case_1);
    quick_sort(case_2);
    quick_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}