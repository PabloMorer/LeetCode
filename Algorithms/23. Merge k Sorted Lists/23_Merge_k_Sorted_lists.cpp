#include<iostream>

#include<vector>
#include<map>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {

        std::map<int, int> order;

        //order listNodes 
        for (ListNode* l : lists) {
            joinMap(order, l);
        }
        std::map<int, int>::iterator it;
        ListNode* list = NULL;
        ListNode* init = NULL;
        ListNode* aux = NULL;
        it = order.begin();
        while (it != order.end()) {
            for (int i = 0; i < it->second; i++) {
                if (list == NULL) {
                    list = new ListNode(it->first);
                    init = list;
                }
                else {
                    aux = new ListNode(it->first);
                    list->next = aux;
                    list = aux;
                }
            }
            it++;
        }

        return init;
    }

    void joinMap(std::map<int, int>& order, ListNode* l) {

        std::map<int, int>::iterator it;

        while (l != NULL) {
            it = order.find(l->val);
            if (it != order.end()) {
                order[l->val]++;
            }
            else {
                order[l->val] = 1;
            }
            l = l->next;
        }
    }
};


