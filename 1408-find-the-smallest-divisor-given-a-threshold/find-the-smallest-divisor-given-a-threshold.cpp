
class Solution {
public:
    long long calculateSum(const std::vector<int>& nums, int divisor) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += (num + divisor - 1) / divisor;
        }
        return totalSum;
    }
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        // The smallest possible divisor is 1.
        int low = 1;
        
        // The largest necessary divisor is the maximum element in the array.
        int high = *std::max_element(nums.begin(), nums.end());
        
        // This will store the smallest valid divisor found so far.
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Calculate the sum for the current mid-point divisor.
            long long currentSum = calculateSum(nums, mid);

            if (currentSum <= threshold) {
                // This divisor works. It's a potential answer.
                // Let's try to find an even smaller one.
                result = mid;
                high = mid - 1;
            } else {
                // This divisor is too small, making the sum too large.
                // We need to look for a larger divisor.
                low = mid + 1;
            }
        }
        
        return result;
    }
};