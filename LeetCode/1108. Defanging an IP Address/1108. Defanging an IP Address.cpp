/* James Bohn
 * 10/16/19
 * good not great time and space solution for LeetCode problem 1108. Defanging an IP Address
 */


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string ans;
		for (int i = 0; i < address.size(); ++i) {
			if (address[i] == '.') {
				ans += "[.]";
			}
			else {
				ans += address[i];
			}
		}
		return ans;
	}
};

int main()
{

}
