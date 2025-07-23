#include <iostream>
#include <vector>

// Best: O(nlog(n))
// Worst: O(nlog(n))
// Average: O(nlog(n))
// Stable: false [[3, 2, 3, 1]

void heapify(std::vector<int>& vec, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[left] > vec[largest]) {
        largest = left;
    }

    if (right < n && vec[right] > vec[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(vec[i], vec[largest]);

        heapify(vec, n, largest);
    }
}

void heap_sort(std::vector<int>& vec) {
    int n = vec.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(vec, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]);

        heapify(vec, i, 0);
    }
}

void print_vec(const std::vector<int>& vec) {
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> case_1 = {7, 6, 5, 4, 3, 2};
    std::vector<int> case_2 = {8, 2, 1, 3, 4};
    std::vector<int> case_3 = {1, 2, 3};

    heap_sort(case_1);
    heap_sort(case_2);
    heap_sort(case_3);

    print_vec(case_1);
    print_vec(case_2);
    print_vec(case_3);

    return 0;
}