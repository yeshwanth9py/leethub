// Last updated: 6/11/2026, 11:27:28 AM
class Node{
    public:
        string data;
        Node* next;
        Node* prev;
        Node(string d){
            data = d;
            next = nullptr;
            prev = nullptr;
        }
};

class BrowserHistory {
public: 
    Node* head;
    Node* cur;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        cur = head;
    }
    
    void visit(string url) {
        Node* newn = new Node(url);
        cur->next = newn;
        newn->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {
        int st = 0;
        while(st<steps && cur && cur->prev){
            cur = cur->prev;
            st++;
        }
        return cur->data;
    }
    
    string forward(int steps) {
        int st = 0;
        while(st<steps && cur && cur->next){
            cur = cur->next;
            st++;
        }
        return cur->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */