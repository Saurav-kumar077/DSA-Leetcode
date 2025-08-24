class Solution {
public:
    /**
     * @brief Finds all elements that appear more than ⌊ n/3 ⌋ times.
     * * This solution uses the Boyer-Moore Voting Algorithm, extended to find two candidates.
     * The core idea is that if we are looking for elements that appear more than n/k times,
     * there can be at most k-1 such elements. For this problem, k=3, so there can be at
     * most two majority elements.
     * * The algorithm consists of two passes:
     * 1.  First Pass: Iterate through the array to find two potential candidates. We maintain
     * two candidates and their counts. When we see a number that is not one of our
     * candidates and both counts are non-zero, we decrement both counts. This effectively
     * "cancels out" a group of three distinct numbers. The elements that survive this
     * process are our candidates.
     * 2.  Second Pass: The first pass only gives us candidates; it doesn't guarantee they
     * are majority elements. We must iterate through the array again to get the true
     * counts of our candidates.
     * 3.  Final Check: We check if the counts of the candidates are greater than n/3 and
     * add them to the result list.
     * * @param nums The input vector of integers.
     * @return A vector containing all majority elements.
     */
    std::vector<int> majorityElement(std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        // 1. Find up to two candidates
        int candidate1 = 0, candidate2 = 1; // Initialize with distinct arbitrary values
        int count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // 2. Verify the candidates
        std::vector<int> result;
        count1 = 0;
        count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        // 3. Check if their counts are greater than n/3
        int n = nums.size();
        if (count1 > n / 3) {
            result.push_back(candidate1);
        }
        if (count2 > n / 3) {
            result.push_back(candidate2);
        }

        return result;
    }
};