#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = createNode(0);
    ListNode* temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = 0;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;

        temp->next = createNode(sum % 10);
        temp = temp->next;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {

    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3); 

    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4); 
    printf("L1: ");
    printList(l1);
    printf("L2: ");
    printList(l2);

    ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    free(l1->next->next);
    free(l1->next);
    free(l1);
    free(l2->next->next);
    free(l2->next);
    free(l2);
    while (result != NULL) {
        ListNode* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
