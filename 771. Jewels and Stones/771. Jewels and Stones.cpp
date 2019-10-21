/* James Bohn
 * 10/17/19
 * Two solid solutions for LeetCode 771. Jewels and Stones.
 * One solution is more time efficient, the other is more space efficient.
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
	// O(J+S) time, O(J) space
	int numJewelsInStonesTime(string J, string S) {
		unordered_map<char, int> jewels;
		int count = 0;
		for (char c : J) {
			++(jewels[c]);
		}

		for (char c : S) {
			count += jewels[c];
		}
		return count;
	}

	// O(J*S) time, O(1) space
	int numJewelsInStonesSpace(string J, string S) {
		int count = 0;
		for (char c : S) {
			if (J.find(c) != string::npos) ++count;
		}
		return count;
	}
};

int main()
{

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
