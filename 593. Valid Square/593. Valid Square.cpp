/* James Bohn
 * 10/16/19
 * Time and space efficient solution for LeetCode problem 589. Valid Square
 * Implementation is done by making sure there are exactly 4 distances
 * that are a minimum value and exactly two distances that are a maximum value
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		if (isSame(p1, p2, p3, p4)) return false;

		vector<double> distances{ dist(p1,p2), dist(p1,p3) , dist(p1,p4) , dist(p2,p3) , dist(p2,p4) , dist(p3,p4) };
		double mini = distances[0], maxi = distances[0];
		for (int i = 1; i < distances.size(); ++i) {
			mini = min(mini, distances[i]);
			maxi = max(maxi, distances[i]);
		}
		int minCount = 0, maxCount = 0;
		for (int i = 0; i < distances.size(); ++i) {
			if (distances[i] == mini) ++minCount;
			if (distances[i] == maxi) ++maxCount;
		}
		return (minCount == 4 && maxCount == 2);
	}

	bool isSame(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		return (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4);
	}

	double dist(vector<int>& p1, vector<int>& p2) {
		return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
	}
};

int main()
{

}