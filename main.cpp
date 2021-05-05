#include <iostream>
#include <vector>
#include <fstream>
#include "MH.h"
#include "HT.h"

using namespace std;

int main(int argc, char *argv[]) {

	ifstream in;
	ofstream out;
	in.open(argv[3]);
	int size = atoi(argv[3]);
	in.close();

	MH minheap(size);
	HT hashtable(size);

	in.open(argv[1]);
	string current;

	getline(in, current, ',');

	int index;
	int f;
	string temp;

	while(current != "") {

		cout << "current:" << current << " ";

		if (hashtable.exists(current)) {

			cout << "1: " << hashtable.getIndex(current) << endl;

			index = hashtable.getIndex(current);
			minheap.frequencyUp(index);

			if (!minheap.swapsEmpty()) {
				for (int i = 0; i < minheap.getSwapsSize(); i++) {
					hashtable.update(minheap.getString(minheap.getSwap(i)), minheap.getSwap(i));
				}
			}
			minheap.clearSwaps();
		}

		else if (!hashtable.exists(current) && !minheap.full()) {

			cout << "2" << endl;

			minheap.insert(current, 1);

			if (!minheap.swapsEmpty()) {
				for (int i = 0; i < minheap.getSwapsSize(); i++) {
					hashtable.update(minheap.getString(minheap.getSwap(i)), minheap.getSwap(i));
				}
			}
			minheap.clearSwaps();

			hashtable.insertEntry(current);
		}

		else if (!hashtable.exists(current) && minheap.full()) {

			cout << "3" << endl;

			f = minheap.getFreq(0);
			temp = minheap.getString(0);
			minheap.deleteMin();

			hashtable.deleteEntry(temp);

			if (!minheap.swapsEmpty()) {
				for (int i = 0; i < minheap.getSwapsSize(); i++) {
					hashtable.update(minheap.getString(minheap.getSwap(i)), minheap.getSwap(i));
				}
			}
			minheap.clearSwaps();

			minheap.insert(current, f+1);

			if (!minheap.swapsEmpty()) {
				for (int i = 0; i < minheap.getSwapsSize(); i++) {
					hashtable.update(minheap.getString(minheap.getSwap(i)), minheap.getSwap(i));
				}
			}
			minheap.clearSwaps();

			hashtable.insertEntry(current);
		}

		for (int i = 0; i < size - 1; i++) {
			cout << minheap.getString(i) << ":" << minheap.getFreq(i) << " ";
		}

		cout << endl;

		getline(in, current, ',');

	}

	in.close();

	out.open(argv[2]);

	minheap.sort();

    for(int i = 0; i < minheap.getCurrentSize(); i++) {
        out << minheap.print(i);
	}

	//for (int i = 0; i < size - 1; i++) {
	//	out << minheap.printMin();
	//	minheap.deleteMin();
	//}
	//out << minheap.printMin() << endl;

	out.close();

	return 0;

}