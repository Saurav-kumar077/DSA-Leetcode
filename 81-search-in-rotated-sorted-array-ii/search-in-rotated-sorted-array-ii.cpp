class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // --- The Fix ---
            // Handle the ambiguous case where you can't tell which part is sorted.
            if (nums[st] == nums[mid]) {
                st++; // Shrink search space from the left
                continue; // Continue to the next iteration
            }

            // Now, one of the halves must be sorted.
            // Check if the left part is sorted
            if (nums[st] <= nums[mid]) {
                if (target >= nums[st] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            // Otherwise, the right part is sorted
            else {
                if (target > nums[mid] && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};