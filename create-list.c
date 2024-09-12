/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL||head->next==NULL){return head;}
    int count = 0;
    struct ListNode * current = head, *last;
    while(true){
        count++;
        if(current->next==NULL){
            last=current;
            break;
        }
        current=current->next;
    }
    int slice = count-(k%count);
    current=head;
    for(int i=0; i<slice-1; i++){
        current=current->next;
    }
    last->next=head;
    head=current->next;
    current->next=NULL;
    return head;
}
