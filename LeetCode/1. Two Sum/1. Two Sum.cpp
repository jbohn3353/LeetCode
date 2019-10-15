/* James Bohn
 * 10/14/19
 * Two solid solutions for LeetCode 1. Two Sum. One solution is time efficient,
 * the other is space efficient.
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//time efficient solution (one pass)
	vector<int> twoSumTime(vector<int>& nums, int target) {
		unordered_map<int, int> priorNumsMap;

		for (size_t i = 0; i < nums.size(); ++i) {
			auto possibleIndexOfPair = priorNumsMap.find(target - nums[i]);
			if (possibleIndexOfPair != priorNumsMap.end()) {
				return vector<int> { possibleIndexOfPair->second, int(i) };
			}
			priorNumsMap.insert({ nums[i], i });
		}

		return vector<int>();
	}

	//space efficient solution
	vector<int> twoSumSpace(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i+1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) return vector<int> {i, j};
			}
		}
		return vector<int>();
	}
};

int main() {

}