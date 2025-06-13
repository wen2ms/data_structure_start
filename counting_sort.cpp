#include <iostream>
#include <vector>

void counting_sort(std::vector<int>& nums) {
    int maximum = *std::max_element(nums.begin(), nums.end());

    std::vector<int> count(maximum + 1, 0);

    for (int num : nums) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= maximum; ++i) {
        while (count[i]-- > 0) {
            nums[index++] = i;
        }
    } 
}

void print_vec(const std::vector<int>& vec) {
    for (int item : vec) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> case_1 = {7, 6, 5, 4, 3, 2};
    std::vector<int> case_2 = {8, 2, 1, 3, 4};
    std::vector<int> case_3 = {1, 2, 3};

    counting_sort(case_1);
    counting_sort(case_2);
    counting_sort(case_3);

    print_vec(case_1);
    print_vec(case_2);
    print_vec(case_3);

    return 0;
}