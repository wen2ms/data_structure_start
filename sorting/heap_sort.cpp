#include <iostream>
#include <vector>

// Best: O(nlog(n))
// Worst: O(nlog(n))
// Average: O(nlog(n))
// Stable: false [[3, 2, 3, 1]

void heapify(int index, int nums_count, std::vector<int>& nums) {
    int max_pos = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < nums_count && nums[left] > nums[max_pos]) {
        max_pos = left;
    }
    if (right < nums_count && nums[right] > nums[max_pos]) {
        max_pos = right;
    }
    if (max_pos != index) {
        std::swap(nums[index], nums[max_pos]);
        heapify(max_pos, nums_count, nums);
    }
}

void heap_sort(std::vector<int>& nums) {
    int nums_count = nums.size();
    for (int i = nums_count / 2 - 1; i >= 0; --i) {
        heapify(i, nums_count, nums);
    }
    for (int i = nums_count - 1; i >= 1; --i) {
        std::swap(nums[0], nums[i]);
        heapify(0, i, nums);
    }
}

void print(const std::vector<int>& vec) {
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> case_1{7, 6, 5, 4, 3, 2};
    std::vector<int> case_2{8, 2, 1, 3, 4};
    std::vector<int> case_3{1, 2, 3};

    heap_sort(case_1);
    heap_sort(case_2);
    heap_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}