#ifndef NODES_H
#define NODES_H

#include <iostream>
#include <unordered_map>

using namespace std;

struct Telement  
{
	int id;
	bool active;
    string word;
};

//estrutura de manipulação do Telement durante a recuperação de dados ma consulta
struct element_words
{
    short position;
    Telement* element;
};


//estrutura de cada node da arvore
struct node
{
    bool is_end;
    unsigned int count_prefix_element;
    unordered_map<int, node*> child;

};

#endif