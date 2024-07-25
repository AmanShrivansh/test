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
      ListNode* th=NULL, *tt=NULL;
    
    void addLast(ListNode* node){
        if(tt==NULL){
            tt=node;
            th=node;
        }else{
            tt->next=node;
            tt=node;
        }
    }
    
    
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        
        ListNode* curr=head;
        while(curr){
            ListNode* fwd = curr->next;
            curr->next=NULL;
            if(tt==NULL || tt->val!=curr->val)addLast(curr);
            curr=fwd;
        }
        return th;
    }
};