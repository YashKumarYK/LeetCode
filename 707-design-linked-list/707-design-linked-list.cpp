class Node{
    public:
    int val;
    Node* next=NULL;
    
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int length;
    MyLinkedList() {
        head=NULL;
        tail= NULL;
        length=0;
    }
    int get(int index) {
        if (index>= length){
            return -1;
        }
        Node* temp = head;
        int i=0;
        while(i< index){
            temp= temp->next;
            i++;
        }
        return temp->val;
        
    }
    
    void addAtHead(int val) {
        Node* temp= new Node(val);
        if( !head  && !tail){
            head = temp;
            tail = temp;
        }
        else{
            temp->next= head;
            head = temp;
        }
        length++;
        
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(head==NULL && tail==NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next= temp;
            tail = temp;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        
        if(length<index ) return;
        
        if(index==0){
            addAtHead(val);
            return;
        }
        if( index==length){
            addAtTail(val);
            return;
        }
        
        Node* temp = head;
        for(int i=0; i<index-1; i++){
            temp= temp->next;
        }
        Node* nodeToInsert = new Node(val);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if( index >=length) return;
        if( index==0){
            Node* temp = head;
            head = head->next;
            temp->next= NULL;
            delete temp;
        }
        
        else if( index==length-1){
            Node* temp = head;
            while( temp->next !=tail){
                temp= temp->next;
            }
            delete tail;
            tail= temp;
        }
        else{
            Node* curr = head;
            Node* prev = NULL;
            int cnt =0;
            while( cnt< index){
                prev = curr;
                curr = curr->next;
                cnt++;
            }
        
            prev->next= curr->next;
            curr->next= NULL;
            delete curr;
        }
        length--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */