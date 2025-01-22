Node* reverseList(Node* head) {
    Node* next = NULL, prev = NULL, curr = head;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;

}
