
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *curr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            ListNode *newNode = new ListNode();
            if (head == nullptr)
            {
                head = newNode;
                curr = head;
            }
            else
            {
                if(l1!=nullptr&&l2!=nullptr)
                {
                    int sum = carry+l1->val+l2->val;
                    if(sum>10)
                    {
                        carry=sum/10;
                        sum%=10;
                    }
                    else
                    {
                        carry=0;
                    }

                    newNode->val=sum;
                    curr->next=newNode;
                    curr=curr->next;
        
                }
                else if(l1!=nullptr)
                {
                    int sum = carry+l1->val;
                    if (sum > 10)
                    {
                        carry = sum / 10;
                        sum %= 10;
                    }
                    else
                    {
                        carry = 0;
                    }
                    newNode->val = sum;
                    curr->next = newNode;
                    curr = curr->next;
                }
                else if (l2 != nullptr)
                {
                    int sum = carry + l2->val;
                    if (sum > 10)
                    {
                        carry = sum / 10;
                        sum %= 10;
                    }
                    else
                    {
                        carry = 0;
                    }
                    newNode->val = sum;
                    curr->next = newNode;
                    curr = curr->next;
                }
            }
        }
        return head;
    }
};
