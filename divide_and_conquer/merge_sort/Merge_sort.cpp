#include <iostream>
#include <vector>

void mergeSort(std::vector<int>& input, int i, int j) {
    if (i == j) return;
    int mid = ((1LL)*i+j)/2;
    mergeSort(input, i, mid);
    mergeSort(input, mid+1, j);
    std::vector<int> merge;
    int idx1 = i, idx2 = mid+1;
    while (idx1 <= mid && idx2 <= j) {
        if (input[idx1] > input[idx2]) {
            merge.push_back(input[idx1++]);
        } else {
            merge.push_back(input[idx2++]);   
        }
    }

    while (idx1 <= mid) {
        merge.push_back(input[idx1++]);
    }
    while (idx2 <= j) {
        merge.push_back(input[idx2++]);
    }

    for (int k = 0; k < merge.size(); k++) {
        input[i+k] = merge[k];
    }
}

int main() {
    std::ios::sync_with_stdio (0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }
    mergeSort(input, 0, n-1);
    for (int i = 0; i < n; i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}