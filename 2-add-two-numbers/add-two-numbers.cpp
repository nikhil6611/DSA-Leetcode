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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* temp3;
        ListNode* firstNode = new ListNode((carry+l1->val+l2->val)%10);
        carry = (l1->val+l2->val+carry)/10;
       temp3 = firstNode;
        ListNode* temp1 = l1->next;
        ListNode* temp2 = l2->next;
        while(temp1!=NULL && temp2!=NULL){
            int data = temp1->val + temp2->val+carry;
            ListNode* newnode = new ListNode(data%10);
            carry = data/10;
            temp3->next = newnode;
            temp3=temp3->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int data = temp1->val + carry;
            ListNode* newnode = new ListNode(data%10);
            carry = data/10;
            temp3->next = newnode;
            temp3=temp3->next;
            temp1=temp1->next;
        }
         while(temp2!=NULL){
            int data = temp2->val + carry;
            ListNode* newnode = new ListNode(data%10);
            carry = data/10;
            temp3->next = newnode;
            temp3=temp3->next;
            temp2=temp2->next;
        }
        while(carry){
            ListNode* newnode= new ListNode(carry%10);
            carry=carry/10;
            temp3->next = newnode;
            temp3=temp3->next;
        }
        return firstNode;
    }
};