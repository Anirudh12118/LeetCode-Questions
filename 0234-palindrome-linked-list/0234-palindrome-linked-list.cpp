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
    ListNode* Reverse(ListNode*temphead){
        ListNode*prev=nullptr;
        ListNode*curr=temphead;
        ListNode*nxt;
        while(curr!=nullptr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        bool result=true;
        if(head==nullptr || head->next==nullptr){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*connector;
        //Cheching for Odd node
        if(fast!=nullptr){
            connector=slow;
            slow=slow->next;
        }
        else{
            connector=prev;
        }
        connector->next=nullptr;
        //starting reverse
        ListNode*secondhalf=Reverse(slow);
        ///Checking
        ListNode*firsthalf=head;
        ListNode*temp=secondhalf;
        while(temp!=nullptr){
            if((temp->val)!=(firsthalf->val)){
                result=false;
                break;
            }
            temp=temp->next;
            firsthalf=firsthalf->next;
        }

        //Restore Original Linked list
        connector->next=Reverse(secondhalf);
        return result;
    }
};