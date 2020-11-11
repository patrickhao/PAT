#include <cstdio>

struct node {
    int data;
    node* next;
};

node* create(int arr[]) {
    node *p, *pre, *head;
    head = new node;
    pre = head;
    for(int i = 0; i < 5; i++) {
        p = new node;
        p->data = arr[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int search(node* head, int target) {
    int count = 0;
    node* p = head->next;
    while(p != NULL) {
        if(p->data == target) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void insert(node* head, int pos, int elem) {
    node* p = head;
    for(int i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    node* q = new node;
    q->data = elem;
    q->next = p->next;
    p->next = q;
}

//删除以head为头结点的链表中所有数据域为target的结点，只删除出现的第一个元素加一个break即可
void del(node* head, int target) {
    node *pre, *p;
    pre = head;
    p = head->next;
    while(p != NULL) {
        if(p->data == target) {
            pre->next = p->next;
            delete(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void put(node*head) {
    node* p = head->next;
    while(p->next != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    node* l = create(arr);
    put(l);
    printf("%d\n", search(l, 5));
    insert(l, 3, 9);
    insert(l, 5, 9);
    put(l);
    del(l, 9);
    put(l);

    return 0;
}