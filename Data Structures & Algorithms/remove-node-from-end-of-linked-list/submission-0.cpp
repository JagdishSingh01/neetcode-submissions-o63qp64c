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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next ==NULL) return NULL;
        ListNode* curr= head;
        //Last node
        if(n==1){
            while(curr->next->next!=NULL){
                curr=curr->next;
            }
            curr->next=NULL;
            return head;
        }
        
        int len=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        int indx= len-n;

        //head node delete
        if(indx==0) return curr->next;

        //delete nth node other than last
        int cnt=0;
        while(curr && cnt<indx-1){
            curr= curr->next;
            cnt++;
        }
        curr->next = curr->next->next;

        return head;
    }
};
