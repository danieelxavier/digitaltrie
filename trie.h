#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <semaphore.h>
#include <algorithm>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <wchar.h>
#include <xlocale.h>
#include <stdio.h>
#include <fstream>
#include <unordered_map>
#include <list>
#include <sstream>
#include "nodes.h"
#include "util.h"

using namespace std;

class Trie
{
public:
	Trie();
	~Trie();
	void Init(string dataset_path);
	vector<int> Search(string query, int qtd);
	bool InsertElement(int id, string elem);
	bool RemoveElement(int id);
	bool UpdateElement(int id, string newElem);

private:
	unordered_map<int, int> index_letter; //hash map que guarda o dicionario de indexes dos caracteres, onde
    //<inteiro referende ao caractere, index do caractere referente de acordo com nosso dicionario>
	Telement *Element;
	element_words *ElementWords;
	node *head;
	element_words elements_found[600000];
	int n_elements_found = 0;
	Util util;
	unordered_map<int, Telement> elements; // hash map que guarda os elements
	unordered_map<node*, list<element_words> > word_lists_element; // hash map que guarda os ponteiros dos elementos de acordo com as palavras chave da trie


	//methods
	void insert(string new_word, string element_name, int id, int position);
	bool search(string word);
	int number_of_elements_with_prefix(string prefix);
	void interator_trie(node *current, bool is_prefix);
	void words_with_prefix(string prefix, bool is_prefix);
	void detail_query_elements(vector<string> words_query);
	vector<int> query(string query, int quant);
	void insert_new_element(int element_id, string el);
	void remove_element(int id);
	void update_element(int element_id, string el);
	bool exist_element(int id);
	void insert_machine(string path);

};

#endif