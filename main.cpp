#include <iostream>
#include "trie.h"

using namespace std;

int main()
{
	Trie *t = new Trie();
	t->Init("paises");

	t->InsertElement(1, "anderson");
	t->UpdateElement(1, "and");
	t->RemoveElement(1);
	vector<int> v = t->Search("A", 5);


	cout << "Result:" << endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	delete t;
	return 0;
}