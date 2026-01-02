#include<bits/stdc++.h>
using namespace std;

void insertMaxHeap(vector<int>& heap, int val) {
    heap.push_back(val);
    int i = heap.size() - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}
int main() {
    vector<int> maxHeap;
    cout << "Enter elements to insert into Max Heap (-1 to stop):" << endl;
    int val;
    cin >> val;
    while (val != -1) {
        insertMaxHeap(maxHeap, val);
        cin >> val;
    }

    cout << "Max Heap elements:" << endl;
    for (int i = 0; i < maxHeap.size(); i++) {
        cout << maxHeap[i] << " ";
    }
    cout << endl;

    return 0;
}


