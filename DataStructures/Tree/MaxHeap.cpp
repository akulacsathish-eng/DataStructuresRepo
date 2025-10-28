#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> array;
    void heapify(int i);

public:
    void insert(int key);
    int extractMax();
    int getMax() const;
    void deleteKey(int i);
    void increaseKey(int i, int newValue);
    void printHeap() const;
};

void Heap::heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = array.size();

    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(largest);
    }
}

void Heap::insert(int key) {
    array.push_back(key);
    int i = array.size() - 1;
    while (i != 0 && array[(i - 1) / 2] < array[i]) {
        swap(array[i], array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int Heap::extractMax() {
    if (array.empty())
        throw underflow_error("Heap underflow");

    int root = array[0];
    array[0] = array.back();
    array.pop_back();
    if (!array.empty())
        heapify(0);
    return root;
}

int Heap::getMax() const {
    if (array.empty())
        throw underflow_error("Heap is empty");
    return array[0];
}

void Heap::deleteKey(int i) {
    if (i >= array.size())
        throw out_of_range("Invalid index");
    array[i] = array.back();
    array.pop_back();
    heapify(i);
}

void Heap::increaseKey(int i, int newValue) {
    if (i >= array.size() || array[i] >= newValue)
        throw invalid_argument("Invalid index or value");
    array[i] = newValue;
    while (i != 0 && array[(i - 1) / 2] < array[i]) {
        swap(array[i], array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void Heap::printHeap() const {
    for (int val : array)
        cout << val << " ";
    cout << endl;
}

int main() {
    Heap heap;
    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    cout << "Max Heap array: ";
    heap.printHeap();

    cout << "Extracted max value: " << heap.extractMax() << endl;
    cout << "Heap after extraction: ";
    heap.printHeap();

    return 0;
}
