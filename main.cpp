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
		}

		else if (!hashtable.exists(current) && !minheap.full()) {

			cout << "2: Current string: " << current << endl;

			minheap.insert(current, 1);
			hashtable.insertEntry(current);
		}

		else if (!hashtable.exists(current) && minheap.full()) {

			cout << "3: Current string: " << current << endl;

			f = minheap.getFreq(0);
			temp = minheap.getString(0);
			minheap.deleteMin();
			hashtable.deleteEntry(temp);
			minheap.insert(current, f+1);
			hashtable.insertEntry(current);
		}

		cout << "here" << endl;

		if (!minheap.swapsEmpty()) {

			for (int i = 0; i < minheap.getSwaps().size() - 1; i++) {
				hashtable.update(minheap.getString(minheap.getSwaps()[i]), minheap.getSwaps()[i]);
			}

		}

		cout << "here2" << endl;

		for (int i = 0; i < size; i++) {
			cout << minheap.getString(i) << ":" << minheap.getFreq(i) << " ";
		}

		cout << "clearswaps" << endl;
		minheap.clearSwaps();

		getline(in, current, ',');
		cout << endl;

	}

	in.close();

	out.open(argv[2]);

	for (int i = 0; i < size - 1; i++) {
		out << minheap.printMin();
		minheap.deleteMin();
	}

	out << minheap.printMin() << endl;

	out.close();

	return 0;

}