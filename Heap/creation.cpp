#include<bits/stdc++.h>
using namespace std;

class MinPriorityQueue {
    private:
    vector<int> heap;

    // Heapify Up (for insertion)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify Down (for deletion)
    void heapifyDown(int index) {
        int size = heap.size();

        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;

            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

    public:
        void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
        }
            void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        }

    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }
        int size() {
        return heap.size();
    }
        bool isEmpty() {
        return heap.empty();
    }
        void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinPriorityQueue pq;

    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(2);

    cout << "Heap elements: ";
    pq.display();

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "After pop: ";
    pq.display();

    cout << "Size: " << pq.size() << endl;
    cout << "Is Empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
