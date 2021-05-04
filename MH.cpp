#include "MH.h"
#include <iostream>
#include <vector>

using namespace std;

MH::MH(int k) {
	size = k;
	heap.resize(size);
	counter = 0;
	currentSize = 0;
}

int MH::parent(int index){
    return (index-1)/2;
}

int MH::left(int index){
    return 2*index + 1;
}

int MH::right(int index){
    return 2*index + 2;
}

void MH::frequencyUp(int index) {
	heap[index].frequency++;
	heapifyDown(index);
}

int MH::getCurrentSize() {
    return currentSize;
}

string MH::getString(int index) {
    return heap[index].entry;
}

int MH::getFreq(int index) {
	return heap[index].frequency;
}

void MH::insert(string entry, int frequency) {

	cout << "insert" << endl;

    Node n;

    n.entry = entry;
    n.frequency = frequency;
    n.count = counter;

    heap[currentSize] = n;
    currentSize++;
    counter++;

    for (int i = 0; i < getCurrentSize(); i++) {
                cout << getString(i) << ":" << getFreq(i) << " ";
            }

    heapifyUp(currentSize - 1);

}

void MH::deleteMin(){

	cout << "deletemin" << endl;

    if(currentSize == 0)
        return;

    if(currentSize == 1)
        currentSize--;

    swap(heap[0], heap[currentSize - 1]);
    currentSize--;
    heapifyDown(0);
}

void MH::heapifyDown(int index){

	cout << "heapifydown" << endl;

    int l = left(index);
    int r = right(index);
    int min = index;

    if (l < currentSize && compare(heap[l], heap[index])) {

        min = l;

    }
    if (r < currentSize && compare(heap[r], heap[min])) {

        min = r;

    }
    if (min != index) {

        swap(heap[index], heap[min]);
        heapifyDown(min);

    }
}

void MH::heapifyUp(int index){

	cout << "heapup" << endl;

    if (index && compare(heap[index], heap[parent(index)])) {

        swap(heap[index], heap[parent(index)]);
        heapifyUp(parent(index));

    }
}

bool MH::compare(Node x, Node y){
    if(x.frequency > y.frequency)
        return false;
    if(x.frequency < y.frequency)
        return true;
    else
    	return x.count > y.count;
}

bool MH::full(){
    return currentSize == size;
}

string MH::printMin(){
    return heap[0].entry + ":" + to_string(heap[0].frequency) + ",";
}
