#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int>& pages, int n, int m, int mid) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; ++i) {
        if (pages[i] > mid) {
            return false;
        }

        if (currentPages + pages[i] > mid) {
            students++;
            currentPages = 0;
        }

        currentPages += pages[i];
    }

    return students <= m;
}

int findMinMaxPages(vector<int>& pages, int n, int m) {
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(pages, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int N = 4;
    vector<int> A = {12, 34, 67, 90};
    int M = 2;
    int output = findMinMaxPages(A, N, M);
    cout << output << endl;  // Output: 113

    return 0;
}
