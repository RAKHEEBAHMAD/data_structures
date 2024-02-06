/* Fast and slow pointer approach*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the Nth node
        slow->next = slow->next->next;

        return dummy->next;
    }
};

/* My Approach */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        n=size-n+1;
        if(n==1)
        {
            head=head->next;
            return head;
        }
        if(n==size)
        {
            ListNode* temp=head;
            ListNode* prev=head;
            while(temp and temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
        }
        else{
            ListNode* temp=head;
            int x=1;
            while(x<n-1 and temp!=NULL)
            {
                x++;
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }

        
        return head;
    }
};