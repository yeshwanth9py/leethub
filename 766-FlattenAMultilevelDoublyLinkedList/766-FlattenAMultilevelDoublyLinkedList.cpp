// Last updated: 6/11/2026, 11:31:26 AM
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* dummy = new Node(0);  // Dummy node to simplify pointer manipulation
        Node* prev = dummy;

        flattenDFS(head, prev);

        // Detach the dummy node
        dummy->next->prev = nullptr;
        return dummy->next;
    }

private:
    void flattenDFS(Node* curr, Node*& prev) {
        if (!curr) return;

        prev->next = curr;
        curr->prev = prev;

        prev = curr;  // Update prev to the current node

        Node* nextNode = curr->next;  // Store next node because it may get overwritten

        if (curr->child) {
            flattenDFS(curr->child, prev);
            curr->child = nullptr;  // Clear the child pointer
        }

        flattenDFS(nextNode, prev);
    }
};
