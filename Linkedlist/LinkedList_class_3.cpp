#include <iostream>
#include <map>
using namespace std;

// 📘 Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 🧩 Utility function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// 🧠 1️⃣ Reverse a Linked List
class ReverseListSolution {
public:
    // Recursive reversal helper
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        if (curr == NULL) return prev;
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        return reverseUsingRecursion(prev, curr);
    }

    // Main function to reverse
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverseUsingRecursion(prev, curr);
    }
};

// 🧭 2️⃣ Middle of Linked List
class MiddleNodeSolution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};

// 💎 3️⃣ Palindrome Check Linked List
class PalindromeSolution {
public:
    // Reverse helper
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        if (curr == NULL) return prev;
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        return reverseUsingRecursion(prev, curr);
    }

    // Find middle node
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    // Compare two lists
    bool compareList(ListNode* head1, ListNode* head2) {
        while (head2 != NULL) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    // Main function to check palindrome
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // 0 or 1 node is always palindrome

        // Step 1️⃣: Find middle
        ListNode* midNode = middleNode(head);

        // Step 2️⃣: Split list
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // Step 3️⃣: Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);

        // Step 4️⃣: Compare both halves
        bool ans = compareList(head, head2);
        return ans;
    }
};

// 🔄 4️⃣ Cycle Detection in Linked List
class CycleDetectionSolution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> table;
        ListNode* temp = head;
        while (temp != NULL) {
            if (table[temp] == true) {
                return true; // cycle present
            }
            table[temp] = true;
            temp = temp->next;
        }
        return false; // no cycle
    }
};

// 🧮 MAIN FUNCTION FOR TESTING ALL CASES
int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List:\n";
    printList(head);

    // 1️⃣ Reverse Linked List
    ReverseListSolution rev;
    ListNode* reversed = rev.reverseList(head);
    cout << "\nReversed Linked List:\n";
    printList(reversed);

    // Recreate list again for other tests
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 2️⃣ Find Middle Node
    MiddleNodeSolution midSol;
    ListNode* mid = midSol.middleNode(head);
    cout << "\nMiddle Node Value: " << mid->val << "\n";

    // 3️⃣ Palindrome Check
    // Create palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    ListNode* palHead = new ListNode(1);
    palHead->next = new ListNode(2);
    palHead->next->next = new ListNode(3);
    palHead->next->next->next = new ListNode(2);
    palHead->next->next->next->next = new ListNode(1);

    PalindromeSolution palSol;
    cout << "\nPalindrome Check: " << (palSol.isPalindrome(palHead) ? "Yes" : "No") << "\n";

    // 4️⃣ Cycle Detection
    // Create cycle manually
    ListNode* cycleHead = new ListNode(10);
    cycleHead->next = new ListNode(20);
    cycleHead->next->next = new ListNode(30);
    cycleHead->next->next->next = new ListNode(40);
    cycleHead->next->next->next->next = cycleHead->next; // Create cycle

    CycleDetectionSolution cycleSol;
    cout << "\nCycle Detection: " << (cycleSol.hasCycle(cycleHead) ? "Cycle Present" : "No Cycle") << "\n";

    return 0;
}
