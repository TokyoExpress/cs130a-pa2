#ifndef MH_H
#define MH_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
	string entry;
	int frequency;
	int count;
};

class MH {

	public:
		MH(int k);
		void frequencyUp(int index);
		int parent(int index);
		int left(int index);
		int right(int index);
		int getCurrentSize();
		string getString(int index);
		int getFreq(int index);
		void insert(string entry, int frequency);
		void deleteMin();
		bool compare(Node x, Node y);
		void heapifyUp(int index);
		void heapifyDown(int index);
		bool full();
		string printMin();
		void clearSwaps();
		vector<int> getSwaps();

	private:
		vector<Node> heap;
		vector<int> swaps;
		int size;
		int counter;
		int currentSize;
};
#endif