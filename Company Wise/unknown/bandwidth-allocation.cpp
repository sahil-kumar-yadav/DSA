#include <iostream>
#include <vector>

using namespace std;

vector<int> findMaximumBandwidth(int n, int k, int m) {
    vector<int> bandwidth(n, m / n);
    int surplus = m % n;

    int left = k - 1, right = k + 1;
    while (surplus > 0) {
        if (left >= 0 && bandwidth[left] < bandwidth[left + 1] + 1) {
            bandwidth[left]++;
            surplus--;
        } else if (right < n && bandwidth[right] < bandwidth[right - 1] + 1) {
            bandwidth[right]++;
            surplus--;
        } else {
            break;
        }
    }

    return bandwidth;
}

int main() {
    int n = 4, k = 3, m = 17;
    vector<int> bandwidth = findMaximumBandwidth(n, k, m);

    cout << "Bandwidth allocation for all endpoints:\n";
    for (int i = 0; i < n; i++) {
        cout << "Endpoint " << i + 1 << ": " << bandwidth[i] << endl;
    }

    return 0;
}