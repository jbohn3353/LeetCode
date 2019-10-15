/* James Bohn
 * 10/14/19
 * Time and space efficient solution for LeetCode problem 2. Add Two Numbers
 */

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ret = new ListNode(0);
		ListNode* tempNode = ret;
		int carryover = 0;
		while (l1 != NULL || l2 != NULL) {
			int temp = 0;
			bool check = (l1 != NULL && l1->next != NULL) || (l2 != NULL && l2->next != NULL);
			if (l1 != NULL) {
				temp += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				temp += l2->val;
				l2 = l2->next;
			}
			
			tempNode->val = temp % 10 + carryover;
			carryover = floor(temp / 10);
			
			if (check) {
				tempNode->next = new ListNode(0);
				tempNode = tempNode->next;
			}
			else {
				if (carryover != 0) tempNode->next = new ListNode(1);
			}
		}
		return ret;
	}
};

int main()
{
	
}

