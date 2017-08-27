#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    if (l1->val == 0 && l1->next == NULL)
    {
        return l2;
    }
    else if (l2->val == 0 && l2->next == NULL)
    {
        return l1;
    }

    struct ListNode *sum = malloc(sizeof(struct ListNode));
    struct ListNode *walker = sum;
    int carry = 0, v1, v2 vSum;
    while (1)
    {
        v1 = (l1 == NULL) ? 0 : l1->val;
        v2 = (l2 == NULL) ? 0 : l2->val;
        vSum = v1 + v2 + carry;
        carry = vSum / 10;
        walker->val = (vSum - (10 * carry));
        // check if we've hit the end of l1 and l2
        if ((l1 == NULL || l1->next == NULL) && (l2 == NULL || l2->next == NULL))
        {
            if (carry)
            {
                walker->next = malloc(sizeof(struct ListNode));
                walker->next->val = 1;
                walker->next->next = NULL;
            }
            else
            {
                walker->next = NULL;
            }
            break;
        }
        walker->next = malloc(sizeof(struct ListNode));
        walker = walker->next;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    return sum;
}