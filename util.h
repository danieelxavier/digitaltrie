#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <sstream>
#include "nodes.h"

using namespace std;

class Util
{
public:
	Util();
	~Util();
	void make_index_letter(unordered_map<int, int>* index_letter);
	vector<int> convert_string_to_indexes(string a, unordered_map<int, int>* index_letter);
	int search_in_string(string s1, string s2, unordered_map<int, int>* index_letter);
	vector<string> split(string str, char delimiter);
	void sortElements(element_words vetor[], int inicio, int fim);
	bool replace(string& str, const string& from, const string& to);

};

#endif