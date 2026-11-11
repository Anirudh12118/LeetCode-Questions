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
    void traverse(ListNode*temp,stack<int>&st){
        //Base Case
        if(temp==nullptr){
            return;
        }
        st.push(temp->val);
        traverse(temp->next,st);
    }

    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //checking for odd Node
        if(fast!=nullptr){
            slow=slow->next;
        }
        //Passing 1st node of 2nd half.
        traverse(slow,st);
        ListNode*temp=head;
        while(!st.empty() && temp!=nullptr){
            if(st.top()!=temp->val){
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};