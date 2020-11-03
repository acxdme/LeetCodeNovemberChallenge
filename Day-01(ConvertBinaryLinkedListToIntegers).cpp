/*
Time complexity : O(N)
Space complexity : O(1)
My approch : traverse list 2 times once to get the size and second to convert binary data to decimal number.
*/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int count = -1;
        while(temp != NULL)
        {
            temp=temp->next;
             count++;
        }
     
        temp =head;
        int value = 0;
        while(temp != NULL)
        {
            value += temp->val*pow(2,count);
            count--;
            temp= temp->next;    
        }
        return value;   
    }
};
