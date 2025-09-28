#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Initialize an empty vector, used for storing the indices.
        vector<int> indices;
        // Outer loop: Loop through each element only once.
        for (int i = 0; i < int(nums.size()-1); i++) {
            // With each iteration of the outer loop, the inner loop will start from the next element.
            // Inner loop: loop through and compare the elements to the right of the outer loop's current element.
            for (int j = i+1; j < int(nums.size()); j++){
                // Conditional statement to check if the sum of the two elements is equal to the target.
                if ((nums[i] + nums[j]) == target) {
                // If the above statement is true...
                // Store the indices in the vector.
                indices.push_back(i);
                indices.push_back(j);
                // Return the vector.
                return indices;
                }
            }
        }
        // Return an empty vector, in case no solution is found.(Following the function's signature).
        return indices;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2,11,7,15,7};

    vector<int> indices = solution.twoSum(nums,9);
    for(int num : indices) {
        cout << num << " ";
    }
    cout << ("Solution") << endl;
    return 0;
}   

