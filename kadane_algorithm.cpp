#include <iostream>
#include <vector>

int kadane(const std::vector<int>& nums) {
    int maximum = nums[0];
    int curr_sum = nums[0];
    int nums_count = nums.size();
    for (int i = 1; i < nums_count; ++i) {
        curr_sum = (curr_sum < 0 ? nums[i] : curr_sum + nums[i]);
        maximum = std::max(curr_sum, maximum);
    }
    return maximum;
}

int main() {
    int count;

    std::cin >> count;

    std::vector<int> input_integers(count);
    for (int i = 0; i < count; ++i) {
        std::cin >> input_integers[i];
    }

    std::cout << kadane(input_integers) << '\n';

    return 0;
}