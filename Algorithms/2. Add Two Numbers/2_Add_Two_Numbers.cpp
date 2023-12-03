#include<iostream>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode* r = new ListNode();
        ListNode* r_ant = r;
        ListNode* ini = r;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
         
            int n1 = 0;
            int n2 = 0;
            if (l1 != NULL) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                n2 = l2->val;
                l2 = l2->next;
            }
            int sum = n1 + n2 + carry;

            if (sum >= 10) {
                r->val = sum % 10;
                carry = sum / 10;
            }
            else {
                r->val = sum;           
                carry = 0;
            }

            
            if (l1 != NULL || l2 != NULL) {
                r->next = new ListNode();
                r = r->next;
            }

        }
        if (carry > 0) {
            r->next = new ListNode(carry);
        }

        return ini;
    }
};
