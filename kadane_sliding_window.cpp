#include <iostream>
#include <vector>
#include <climits>

int kadane_sliding_window(const std::vector<int> integers, int k) {
    int maximum = INT_MIN;
    int current_sum = 0;

    int left = 0;
    for (int right = 0; right < integers.size(); ++right) {
        current_sum += integers[right];
        if (right - left + 1 <= k) {
            if (current_sum <= 0) {
                left = right  + 1;
                current_sum = 0;
            }
        } else {
            current_sum -= integers[left];
            left++;

            while (integers[left] < 0) {
                current_sum -= integers[left];
                left++;
            }
        }

        std::cout << left << ' ' << right << std::endl; 

        maximum = std::max(current_sum, maximum);
    }
    return maximum;
}

int main() {
    int n, k;

    std::cin >> n >> k;

    std::vector<int> input_integers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> input_integers[i];
    }

    std::cout << kadane_sliding_window(input_integers, k) << std::endl;

    return 0;
}