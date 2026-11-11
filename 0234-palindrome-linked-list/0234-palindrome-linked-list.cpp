/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    stack<int>st;
    void traverse(ListNode*temp){
        //Base Case
        if(temp==nullptr){
            return;
        }
        st.push(temp->val);
        traverse(temp->next);
    }

    bool isPalindrome(ListNode* head) {
        traverse(head);
        ListNode*temp=head;
        while(!st.empty() || temp!=nullptr){
            if(st.top()!=temp->val){
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};