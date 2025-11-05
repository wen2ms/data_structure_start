#include <iostream>
#include <vector>

// Best: O(n) [1, 2, 3, 4, 5]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(n^2)
// Stable: true [1, 2, 3, 2, 4]

void insertion_sort(std::vector<int>& nums) {
    int nums_count = nums.size();
    for (int i = 1; i < nums_count; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
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

    insertion_sort(case_1);
    insertion_sort(case_2);
    insertion_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}