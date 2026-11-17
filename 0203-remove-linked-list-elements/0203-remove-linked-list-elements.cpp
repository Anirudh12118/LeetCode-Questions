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

    void Delete(ListNode* &head,ListNode*idx){
        //Checking if the node is head or Not ??
        if(head==idx){
            head=head->next;
        }
        else{
            struct ListNode*temp=head;
            while(temp && temp->next!=idx){
                temp=temp->next;
            }
            if(temp && temp->next==idx){
                temp->next=idx->next;
            }
        }
        delete(idx);
    }

    ListNode* removeElements(ListNode* head, int val) {
        struct ListNode*temp=head;
        struct ListNode*curr;
        while(temp!=nullptr){
            if(temp->val==val){
                curr=temp;
                temp=temp->next;
                Delete(head,curr);
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};