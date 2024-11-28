#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

int maxPackedSets(std::vector<int>& items, const std::vector<std::set<int>>& sets) {
    int maxSets = 0; // Maximum number of sets packed

    for (const auto& set : sets) {
        bool canPack = true;

        // Check if all items in the current set exist in the items list
        for (int item : set) {
            if (std::find(items.begin(), items.end(), item) == items.end()) {
                canPack = false;
                break;
            }
        }

        if (canPack) {
            // If we can pack the set, remove its items from the available items
            for (int item : set) {
                items.erase(std::remove(items.begin(), items.end(), item), items.end());
            }
            maxSets++;
        }
    }
    return maxSets;
}

int main() {
    // Set of items
    std::vector<int> items = { 1, 2, 3, 4, 5, 6 };

    // List of sets
    std::vector<std::set<int>> sets = { {1, 2, 3}, {4, 5}, {5, 6}, {1, 4} };

    // Find the maximum number of sets that can be packed into the given set of items
    int maxSets = maxPackedSets(items, sets);

    // Print the result
    std::cout << "Maximum number of sets that can be packed: " << maxSets << std::endl;

    return 0;
}
