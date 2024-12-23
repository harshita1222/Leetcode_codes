class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* mine = new ListNode(-1);
        ListNode* curr = mine;
        int carry = 0;

        while(l1 && l2){
            int sum = (l1->val + l2->val + carry);
            int data = sum % 10;
            carry = sum / 10;
            ListNode* temp = new ListNode(data);
            curr->next = temp;
            curr = temp;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = (l1->val + carry);
            int data = sum % 10;
            carry = sum / 10;
            ListNode* temp = new ListNode(data);
            curr->next = temp;
            curr = temp;
            l1 = l1->next;
        }

        while(l2){
            int sum = (l2->val + carry);
            int data = sum % 10;
            carry = sum / 10;
            ListNode* temp = new ListNode(data);
            curr->next = temp;
            curr = temp;
            l2 = l2->next;
        }

        if(carry){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }
        return mine->next;
    }
};
