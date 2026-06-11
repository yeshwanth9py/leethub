// Last updated: 6/11/2026, 11:16:16 AM
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        int m = elements.size();
        vector<int> assigned(n, -1);

        // Store element indices in a map (element value -> smallest index)
        unordered_map<int, int> elementIndex;
        for (int j = 0; j < m; j++) {
            if (elementIndex.find(elements[j]) == elementIndex.end()) {
                elementIndex[elements[j]] =
                    j; // Store smallest index of each element
            }
        }

        // Process each group
        for (int i = 0; i < n; i++) {
            int minIndex = -1;

            // Find smallest divisor in our element set
            for (int d = 1; d * d <= groups[i]; d++) {
                if (groups[i] % d == 0) {
                    // Check both divisors (d and groups[i]/d)
                    if (elementIndex.count(d) &&
                        (minIndex == -1 || elementIndex[d] < minIndex)) {
                        minIndex = elementIndex[d];
                    }
                    if (elementIndex.count(groups[i] / d) &&
                        (minIndex == -1 ||
                         elementIndex[groups[i] / d] < minIndex)) {
                        minIndex = elementIndex[groups[i] / d];
                    }
                }
            }

            assigned[i] = minIndex;
        }

        return assigned;
    }
};