// Last updated: 6/11/2026, 11:30:56 AM
class Node{
    public:
        int val;
        Node* next;
        Node(){
            next = nullptr;
        }
        Node(int v){
            val = v;
            next = nullptr;
        }
};

class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if(head == nullptr){
            return -1;
        }
        int ct = 0;
        Node* temp = head;
        while(ct<index){
            if(!temp){
                return -1;
            }
            temp = temp->next;
            ct++;
        }

        if(temp){
            return temp->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        if(head == nullptr){
            head = new Node(val);
            return;
        }

        Node* temp = head;
        head = new Node(val);
        head->next = temp;
        
    }
    
    void addAtTail(int val) {
        if(head == nullptr){
            head = new Node(val);
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = new Node(val);

    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(!head) return;
        int cnt = 0;
        Node* temp = head;
        while(cnt<index-1 && temp){
            temp = temp->next;
            cnt++;
        }
        if(temp == nullptr) return;
        Node* nxt = temp->next;
        temp->next = new Node(val);
        temp->next->next = nxt;
    }
    
    void deleteAtIndex(int index) {
        if(!head) return;
        if(index == 0){
            head = head->next;
            return;
        }
        int cnt = 0;
        Node* temp = head;
        while(cnt<index-1 && temp){
            temp = temp->next;
            cnt++;
        }
        if(temp == nullptr) return;
        temp->next = temp->next?temp->next->next:nullptr;
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