#include "HT.h"
#include <iostream>
#include <string>

using namespace std;

HT::HT(int K) {

	this->K = K;

	size = 2*K;

	bool isPrime = false;

    while (isPrime == false) {
    	size++;
    	isPrime = true;

    	for (int i = 2; i < size; i++) {
    		if (size % i == 0)
            	isPrime = false;
    	}
    }

    table.resize(size);

    for (int i = 0; i < size; i++) {
    	table[i].entry = "";
    	table[i].index = -1;
    	table[i].dead = false;
    }

}

bool HT::exists(string s) {
	return getIndex(s) == -1;
}

int HT::getIndex(string s) {

	int h = hasher(s) % size;
	int q = 0;

    for(int i = 0; i < size; i++) {

        q = h + i*i;

        if(table[i].entry == s)
            return table[i].index;

    }

    return -1;

}

void HT::insertEntry(string s) {

	cout << "htinsert";

	int h = hasher(s) % size;
	int q = 0;

	for (int i = 0; i < size; i++) {

		q = h + i*i;

		if (table[q].entry == "" || table[q].dead == true) {
			table[q].entry = s;
			table[q].index = 0;
			table[q].dead = false;
			return;
		}

	}
}

void HT::deleteEntry(string s) {

	cout << "htdelete";

	int h = hasher(s) % size;
	int q = 0;

		for (int i = 0; i < size; i++) {

			q = h + i*i;

			if (table[q].entry == "") {
				return;
			}

			else if (table[q].entry == s) {
				table[q].index = -1;
				table[q].dead = true;
				return;
			}
	}
}

void HT::update(string s, int x) {

	cout << "update";

	int h = hasher(s) % size;
	int q = 0;

		for (int i = 0; i < size; i++) {

			q = h + i*i;

			if (table[q].entry == s) {
				table[q].index = x;
			}
	}
}