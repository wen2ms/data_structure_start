#include <iostream>
#include <vector>

// Best: O(n + k) [1, 2, 3, 4, 5]
// Worst: O(n + k) [5, 4, 3, 2, 1]
// Average: O(n + k)
// Stable: false [1, 2, 3, 2, 4]

void counting_sort(std::vector<int>& nums) {
    int maximum = *std::max_element(nums.begin(), nums.end());
    std::vector<int> counts(maximum + 1);
    for (int num : nums) {
        ++counts[num];
    }
    int index = 0;
    for (int i = 0; i <= maximum; ++i) {
        while (counts[i] > 0) {
            nums[index] = i;
            ++index;
            --counts[i];
        }
    }
}

void print(const std::vector<int>& nums) {
    for (int item : nums) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> case_1{7, 6, 5, 4, 3, 2};
    std::vector<int> case_2{8, 2, 1, 3, 4};
    std::vector<int> case_3{1, 2, 3};

    counting_sort(case_1);
    counting_sort(case_2);
    counting_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}