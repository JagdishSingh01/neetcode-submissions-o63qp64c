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
    ListNode* middle(ListNode* head){
        ListNode* mid= head;
        ListNode* end = head;
        while(end && end->next){
            mid = mid->next;
            end = end->next->next;
        }
        return mid;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr= front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* mid = middle(head);
        ListNode* second = reverse(mid);
        ListNode* first = head;
        while(second){
            if(second->val!=first->val) return false;
            second = second->next;
            first  = first->next;
        }
        return true;
    }
};