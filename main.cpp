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

	while(current != "") {

		cout << "lol";

		if (hashtable.exists(current)) {

			cout << "1";

			index = hashtable.getIndex(current);
			minheap.frequencyUp(index);

			for (int i = 0; i < minheap.getCurrentSize(); i++) {
				hashtable.update(minheap.getString(i), i);
			}
		}

		else if (!hashtable.exists(current) && !minheap.full()) {

			cout << "2";

			minheap.insert(current);

			for (int i = 0; i < minheap.getCurrentSize(); i++) {
				hashtable.update(minheap.getString(i), i);
			}
		}

		else if (!hashtable.exists(current) && minheap.full()) {

			cout << "3";

			minheap.swapMin(current);

			for (int i = 0; i < minheap.getCurrentSize(); i++) {
				hashtable.update(minheap.getString(i), i);
			}
		}

		getline(in, current, ',');

	}

	in.close();

	out.open(argv[2]);

	for (int i = 0; i < minheap.getCurrentSize(); i++) {
		out << minheap.printMin();
		minheap.deleteMin();
	}

	out.close();

	return 0;

}