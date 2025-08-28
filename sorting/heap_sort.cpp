#include <iostream>
#include <vector>

// Best: O(nlog(n))
// Worst: O(nlog(n))
// Average: O(nlog(n))
// Stable: false [[3, 2, 3, 1]

void heapify(std::vector<int>& vec, int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && vec[left] > vec[largest]) {
        largest = left;
    }

    if (right < size && vec[right] > vec[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(vec[index], vec[largest]);

        heapify(vec, size, largest);
    }
}

void heap_sort(std::vector<int>& vec) {
    int size = vec.size();

    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(vec, size, i);
    }

    for (int i = size - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]);

        heapify(vec, i, 0);
    }
}

void print(const std::vector<int>& vec) {
    for (const auto& item : vec) {
        std::cout << item << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> case_1 = {7, 6, 5, 4, 3, 2};
    std::vector<int> case_2 = {8, 2, 1, 3, 4};
    std::vector<int> case_3 = {1, 2, 3};

    heap_sort(case_1);
    heap_sort(case_2);
    heap_sort(case_3);

    print(case_1);
    print(case_2);
    print(case_3);

    return 0;
}