class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        if(index == size){
            addAtTail(val);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;

            if(size == 1) tail = NULL;
            size--;
            return;
        }

        Node* temp = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        if(nodeToDelete == tail){
            tail = temp;
        }

        delete nodeToDelete;
        size--;
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