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

    Node n;

    n.entry = entry;
    n.frequency = frequency;
    n.count = counter;

    heap[currentSize] = n;
    currentSize++;
    counter++;

    heapifyUp(currentSize - 1);

}

void MH::deleteMin(){

    if(currentSize == 0)
        return;

    if(currentSize == 1)
        currentSize--;

    swap(heap[0], heap[currentSize - 1]);
    currentSize--;
    heapifyDown(0);
}

void MH::heapifyDown(int index){

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
        swaps.push_back(index);
        swaps.push_back(min);
        heapifyDown(min);

    }
}

void MH::heapifyUp(int index){

    if (index && compare(heap[index], heap[parent(index)])) {

        swap(heap[index], heap[parent(index)]);
        swaps.push_back(index);
        swaps.push_back(parent(index));
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

string MH::print(int index){
    return heap[index].entry + ":" + to_string(heap[index].frequency) + ",";
}

bool MH::swapsEmpty() {
    return swaps.size() == 0;
}

int MH::getSwapsSize() {
    return swaps.size();
}

int MH::getSwap(int i) {
    return swaps[i];
}

void MH::clearSwaps() {
    swaps.clear();
}

void MH::sort(){

    vector<Node> sorted = heap;

    for(int i = 0; i < currentSize - 1; i++) {

        int min = i;

        for(int j = i + 1; j < currentSize; j++) {

            if(compare(sorted[j], sorted[min]))
                min = j;

        }

        swap(sorted[i], sorted[min]);
    }

    heap = sorted;
}