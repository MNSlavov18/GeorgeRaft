#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>


bool canTransport(const std::vector<int>& weights, int k, int capacity) {
    int trips = 0;
    int n = weights.size();

    std::vector<bool> used(n, false);

    for (int i = 0; i < n; i++)
    {
        if (used[i]) continue;
        int currentWeight = weights[i];
        used[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && currentWeight + weights[j] < capacity)
            {
                currentWeight += weights[j];
                used[j] = true;
            }
        }
        trips++;
        if (trips > k)
        {
            return false;
        }
    }

    return true;

}

int findMinCapacity(std::vector<int>& weights, int k) {
    std::sort(weights.rbegin(), weights.rend());
    int left = *std::max_element(weights.begin(), weights.end());
    int right = std::accumulate(weights.begin(), weights.end(), 0);

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        //TODO: FindIFCanTransport
        if (canTransport(weights, k, mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result -1 ;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    //TODO: FindMinCapacity
    std::cout << findMinCapacity(weights, k) << std::endl;
    return 0;
}

