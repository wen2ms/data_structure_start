#include <iostream>
#include <limits>
#include <vector>

int kadane(const std::vector<int>& nums) {
    int maximum = std::numeric_limits<int>::min();
    int current_sum = 0;

    for (int num : nums) {
        current_sum = std::max(num, current_sum + num);
        maximum = std::max(current_sum, maximum);
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