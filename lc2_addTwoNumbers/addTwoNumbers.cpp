/*******************************************************************
Copyright (c) 2020 Hacky DH

This file is distributed under MIT License.
See the LICENSE file for details.
*******************************************************************/

/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes
contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero,
except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return true;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p=l1, *q=l2;
        int c=0, sum;
        while(p!=nullptr && q!=nullptr) {
            if(p!=q) {
                sum = p->val + q->val + c;
                p->val = q->val = sum%10;
            } else {
                sum = p->val + c;
                p->val = sum%10;
            }
            c = sum/10;
            if(p->next==nullptr && q->next==nullptr && c!=0) {
                p->next = new ListNode(c);
                return l1;
            }
            if(p->next==nullptr && q->next!=nullptr) {
                p->next = q->next;
            } else if(p->next!=nullptr && q->next==nullptr) {
                q->next = p->next;
            }
            p=p->next;
            q=q->next;
        }
        return l1;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}
