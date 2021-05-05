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
	string current = "";

	getline(in, current, ',');

	int index;
	int f;
	string temp;

	while(current != "") {

		if (hashtable.exists(current)) {

			cout << "1: Current string: " << current << endl;

			index = hashtable.getIndex(current);
			minheap.frequencyUp(index);

			for (int i = 0; i < size; i++) {
				hashtable.update(minheap.getString(i), i);
			}
			minheap.clearSwaps();
		}

		else if (!hashtable.exists(current) && !minheap.full()) {

			cout << "2: Current string: " << current << endl;

			minheap.insert(current, 1);

			for (int i = 0; i < size; i++) {
				hashtable.update(minheap.getString(i), i);
			}
			minheap.clearSwaps();

			hashtable.insertEntry(current);
		}

		else if (!hashtable.exists(current) && minheap.full()) {

			cout << "3: Current string: " << current << endl;

			f = minheap.getFreq(0);
			temp = minheap.getString(0);
			minheap.deleteMin();

			for (int i = 0; i < size; i++) {
				hashtable.update(minheap.getString(i), i);
			}
			minheap.clearSwaps();

			hashtable.deleteEntry(temp);
			minheap.insert(current, f+1);

			for (int i = 0; i < size; i++) {
				hashtable.update(minheap.getString(i), i);
			}
			minheap.clearSwaps();

			hashtable.insertEntry(current);
		}

		//if (!minheap.swapsEmpty()) {

			//for (int i = 0; i < minheap.getSwapsSize(); i++) {
				//cout << "updating" << minheap.getSwap(i) << endl;
				//hashtable.update(minheap.getString(minheap.getSwap(i)), minheap.getSwap(i));
			//}

		//}

		getline(in, current, ',');
		cout << endl;

	}

	in.close();

	out.open(argv[2]);

	for (int i = 0; i < size - 1; i++) {
		out << minheap.printMin();
		minheap.deleteMin();
	}

	cout << "seg?" << endl;

	out.close();

	return 0;

}