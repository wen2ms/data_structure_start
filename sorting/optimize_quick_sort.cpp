#include <iostream>
#include <random>
#include <utility>
#include <vector>

// Best: O(n) [2, 2, 2, 3]
// Worst: O(n^2) [5, 4, 3, 2, 1]
// Average: O(nlog(n))
// Stable: false [2, 2, 1]

std::random_device random_device;
std::mt19937 generator(random_device());

void quick_sort(int left, int right, std::vector<int>& nums) {
    if (left < right) {
        int low = left;
        int mid = left;
        int high = right;
        std::uniform_int_distribution<> distribution(left, right);
        int pivot_index = distribution(generator);
        int pivot = nums[pivot_index];
        while (mid <= high) {
            if (nums[mid] < pivot) {
                std::swap(nums[mid], nums[low]);
                ++mid;
                ++low;
            } else if (nums[mid] > pivot) {
                std::swap(nums[mid], nums[high]);
                --high;
            } else {
                ++mid;
            }
        }
        quick_sort(left, low - 1, nums);
        quick_sort(high + 1, right, nums);
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