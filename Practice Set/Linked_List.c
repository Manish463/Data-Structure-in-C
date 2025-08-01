#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int val) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

struct Node *insert(struct Node *head, int val) {
    struct Node *ptr = createNode(val);
    struct Node *p = head;

    if(!p) return ptr;

    while(p->next != NULL) {
        p=p->next;
    }
    p->next = ptr;

    return head;
}

struct Node *delete(struct Node *head) {
    if(!head) return NULL;
    if(!head->next) {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

int search(struct Node *head, int num) {
    struct Node *ptr = head;
    int idx = 0, flag = 0;

    while(ptr != NULL) {
        if(ptr->data == num) {
            return idx;
        }

        ptr = ptr->next;
        idx++;
    }

    return -1;
}

struct Node *reverse(struct Node *head) {
    if (!head || !head->next) return head;

    struct Node *p = head;
    struct Node *q = p->next;
    struct Node *r = q->next;

    p->next = NULL;
    while(r != NULL) {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;

    return q;
}

struct Node *concate(struct Node *head, struct Node *head2) {
    struct Node *q = head;

    if(!head) return head2;

    while(q->next != NULL) {
        q = q->next;
    }
    q->next = head2;

    return head;
}

void traversal(struct Node *ptr) {
    printf("The elements are: ");

    while(ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node *head;
    struct Node *head2;
    int val, num;
    
    printf("enter: ");
    scanf("%d", &val);
    head=createNode(val);
    
    for (int i = 0; i < 5-1; i++) {
        printf("enter: ");
        scanf("%d", &val);
        insert(head, val);
    }
    traversal(head);

    printf("enter: ");
    scanf("%d", &val);
    head2=createNode(val);

    for (int i = 0; i < 5-1; i++) {
        printf("enter: ");
        scanf("%d", &val);
        insert(head2, val);
    }
    traversal(head2);

    head = concate(head, head2);
    traversal(head);
    // printf("Enter the num to search: ");
    // scanf("%d", &num);
    // printf("The num is found at %d", search(head, num));

    // delete(head);
    // traversal(head);

    // head = reverse(head);
    // traversal(head);

    free(head);
    return 0;
}