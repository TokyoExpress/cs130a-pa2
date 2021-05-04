#ifndef HT_H
#define HT_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Bucket {
	string entry;
	int index;
	bool dead;
};

class HT {

	public:
		HT(int K);
		void update(string s, int x);
		bool exists(string s);
		int getIndex(string s);
		void deleteEntry(string s);
		void insertEntry(string s);

	private:
		vector<Bucket> table;
		int K;
		int size;
		hash<string> hasher;

};
#endif