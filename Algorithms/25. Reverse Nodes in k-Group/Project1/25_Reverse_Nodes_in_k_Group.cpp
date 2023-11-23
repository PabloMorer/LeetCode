#include<iostream>
#include<vector>

  //Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:



    

    std::pair<ListNode*, ListNode*> calculateGroup(ListNode* first, ListNode* last) {
        ListNode* newLast = first;
        ListNode* act = first->next;
        ListNode* ant = newLast;
        ListNode* act_aux;
        ListNode* ant_aux;
        while (act != last ) {
            act_aux = act->next;
            ant_aux = act;
            act->next = ant;
            act = act_aux;
            ant = ant_aux;
        }
        act->next = ant;
        newLast->next = NULL;
        std::pair<ListNode*, ListNode*> p;
        p.first = act;
        p.second = newLast;
        return p;
    }

    std::pair<int, int> prepareProblem(ListNode* head, int k) {
        ListNode* l = head;
        int cont = 1;
        while (l->next != NULL) {
            cont++;
            l = l->next;
        }
        int mod = cont % k;
        std::pair<int, int> p;
        p.first = cont;
        p.second = round(mod);
        return p;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        std::pair<int, int> p = prepareProblem(head, k);
        ListNode* ret = NULL;
        ListNode* first = head;
        ListNode* last_end = head;
        ListNode* last_gp_aux = head;
        int contAgr = 0;
        while (p.first - contAgr > p.second) {
            ListNode* first_gp = first;
            ListNode* last_gp = first;
            int c = 1;
            while (c < k) {
                last_gp = last_gp->next;
                c++;
            }
             last_gp_aux = last_gp->next;
            std::pair<ListNode*, ListNode*> group = calculateGroup(first_gp, last_gp);
            if (ret == NULL) {
                ret = group.first;
                last_end = group.second;
            }
            last_end->next = group.first;
            last_end = group.second;
            first = last_gp_aux;
            
            contAgr += k;
        }
        last_end->next = last_gp_aux;


        return ret;
    }
};
