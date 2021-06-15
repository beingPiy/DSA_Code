node* mergeSort(node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //rec case
    node* mid = mid_point(node* head) ;
    node*a = head ;
    node*b = mid->next ;
    mid->next = NULL ;

    a = mergeSort(a) ;
    b = mergeSort(b) ;

    c = merge(a , b) ;
    
    return c ;
}