#include <iostream>
#include <random>
#include <utility>
#include <vector>

// Best: O(n + k) 【0.12, 0.24, 0.37, 0.51, 0.63, 0.88]
// Worst: O(n + k) [0.91, 0.92, 0.93, 0.94, 0.95]
// Average: O(n + k)
// Stable: false

std::random_device random_device;
std::mt19937 generator(random_device());

void quick_sort(int left, int right, std::vector<double>& nums) {
    if (left < right) {
        int low = left;
        int mid = left;
        int high = right;
        std::uniform_int_distribution<> distribution(left, right);
        int pivot_index = distribution(generator);
        double pivot = nums[pivot_index];
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

void quick_sort(std::vector<double>& nums) {
    int nums_count = nums.size();
    quick_sort(0, nums_count - 1, nums);
}

void bucket_sort(std::vector<double>& nums) {
    int nums_count = nums.size();
    std::vector<std::vector<double>> buckets(nums_count);
    for (double num : nums) {
        int index = num * nums_count;
        if (index == nums_count) {
            index = nums_count - 1;
        }
        buckets[index].push_back(num);
    }
    for (std::vector<double>& bucket : buckets) {
        quick_sort(bucket);
    }
    int index = 0;
    for (const std::vector<double>& bucket : buckets) {
        for (double num : bucket) {
            nums[index] = num;
            ++index;
        }
    }
}

void print(const std::vector<double>& nums) {
    for (double num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<double> nums{0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucket_sort(nums);
    print(nums);

    return 0;
}