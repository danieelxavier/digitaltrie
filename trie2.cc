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

using namespace std;

unordered_map<int, int> index_letter; //hash map que guarda o dicionario de indexes dos caracteres, onde
                            //<inteiro referende ao caractere, index do caractere referente de acordo com nosso dicionario>
         
//estrutura de armazenamento de cada elemento da base, onde são guardados o id e a string da descrição.                                           
struct Telement  
{
	int id;
	bool active;
    string word;
} *Element;


//estrutura de manipulação do Telement durante a recuperação de dados ma consulta
struct element_words
{
    short position;
    Telement* element;
} *ElementWords;


//estrutura de cada node da arvore
struct node
{
    bool is_end;
    unsigned int count_prefix_element;
    unordered_map<int, node*> child;

} *head;


//inicia uma nova arvore
void init()
{
    head = new node();
    head->count_prefix_element = 0;
    head->is_end = false;

}

unordered_map<int, Telement> elements; // hash map que guarda os elements

unordered_map<node*, list<element_words> > word_lists_element; // hash map que guarda os ponteiros dos elementos de acordo com as palavras chave da trie


//procedimento que cria o dicionario de indexes e popula o hash map "index_letter"
void make_index_letter()
{
    index_letter[65] = 1;		//A
    index_letter[97] = 1;		//a
    index_letter[194] = 1;		//Â
    index_letter[226] = 1;		//â
    index_letter[196] = 1;		//Ä
    index_letter[228] = 1;		//ä
    index_letter[192] = 1;		//À
    index_letter[224] = 1;		//à
    index_letter[229] = 1;		//å
    index_letter[197] = 1;		//Å
    index_letter[193] = 1;		//Á
    index_letter[225] = 1;		//á
    index_letter[195] = 1;		//Ã
    index_letter[227] = 1;		//ã

    index_letter[66] = 2;		//B
    index_letter[98] = 2;		//b

    index_letter[67] = 3;		//C
    index_letter[99] = 3;		//c

    index_letter[68] = 4;		//D
    index_letter[100] = 4;		//d

    index_letter[69] = 5;		//E
    index_letter[101] = 5;		//e
    index_letter[201] = 5;		//É
    index_letter[233] = 5;		//é
    index_letter[203] = 5;		//Ë
    index_letter[235] = 5;		//ë
    index_letter[200] = 5;		//È
    index_letter[232] = 5;		//è
    index_letter[202] = 5;		//Ê
    index_letter[234] = 5;		//ê

    index_letter[70] = 6;		//F
    index_letter[102] = 6;		//f

    index_letter[71] = 7;		//G
    index_letter[103] = 7;		//g

    index_letter[72] = 8;		//H
    index_letter[104] = 8;		//h

    index_letter[73] = 9;		//I
    index_letter[105] = 9;		//i
    index_letter[207] = 9;		//Ï
    index_letter[239] = 9;		//ï
    index_letter[204] = 9;		//Ì
    index_letter[236] = 9;		//ì
    index_letter[205] = 9;		//Í
    index_letter[237] = 9;		//í
    index_letter[206] = 9;		//Î
    index_letter[238] = 9;		//î

    index_letter[74] = 10;		//J
    index_letter[106] = 10;		//j

    index_letter[75] = 11;		//K
    index_letter[107] = 11;		//k

    index_letter[76] = 12;		//L
    index_letter[108] = 12;		//l

    index_letter[77] = 13;		//M
    index_letter[109] = 13;		//m

    index_letter[78] = 14;		//N
    index_letter[209] = 14;		//Ñ
    index_letter[241] = 14;		//ñ
    index_letter[110] = 14;		//n

    index_letter[79] = 15;		//O
    index_letter[111] = 15;		//o
    index_letter[212] = 15;		//Ô
    index_letter[244] = 15;		//ô
    index_letter[214] = 15;		//Ö
    index_letter[246] = 15;		//ö
    index_letter[210] = 15;		//Ò
    index_letter[242] = 15;		//ò
    index_letter[211] = 15;		//Ó
    index_letter[243] = 15;		//ó
    index_letter[213] = 15;		//Õ
    index_letter[245] = 15;		//õ

    index_letter[80] = 16;		//P
    index_letter[112] = 16;		//p

    index_letter[81] = 17;		//Q
    index_letter[113] = 17;		//q

    index_letter[82] = 18;		//R
    index_letter[114] = 18;		//r

    index_letter[83] = 19;		//S
    index_letter[115] = 19;		//s

    index_letter[84] = 20;		//T
    index_letter[116] = 20;		//t

    index_letter[85] = 21;		//U
    index_letter[117] = 21;		//u
    index_letter[220] = 21;		//Ü
    index_letter[252] = 21;		//ü
    index_letter[217] = 21;		//Ù
    index_letter[249] = 21;		//ù
    index_letter[218] = 21;		//Ú
    index_letter[250] = 21;		//ú
    index_letter[219] = 21;		//Û
    index_letter[251] = 21;		//û

    index_letter[86] = 22;		//V
    index_letter[118] = 22;		//v

    index_letter[87] = 23;		//W
    index_letter[119] = 23;		//w

    index_letter[88] = 24;		//X
    index_letter[120] = 24;		//x

    index_letter[89] = 25;		//Y
    index_letter[121] = 25;		//y
    index_letter[376] = 25;		//Ÿ
    index_letter[255] = 25;		//ÿ
    index_letter[221] = 25;		//Ý
    index_letter[253] = 25;		//ý

    index_letter[90] = 26;		//Z
    index_letter[122] = 26;		//z

    index_letter[48] = 27;		//0
    index_letter[49] = 28;		//1
    index_letter[50] = 29;		//2
    index_letter[51] = 30;		//3
    index_letter[52] = 31;		//4
    index_letter[53] = 32;		//5
    index_letter[54] = 33;		//6
    index_letter[55] = 34;		//7
    index_letter[56] = 35;		//8
    index_letter[57] = 36;		//9

    index_letter[32] = 37;		//ESPAÇO
    index_letter[33] = 38;		//!
    index_letter[34] = 39;		//"
    index_letter[35] = 40;		//#
    index_letter[36] = 41;		//$
    index_letter[37] = 42;		//%
    index_letter[38] = 43;		//&
    index_letter[39] = 44;		//'
    index_letter[40] = 45;		//(
    index_letter[41] = 46;		//)
    index_letter[42] = 47;		//*
    index_letter[43] = 48;		//+
    index_letter[44] = 49;		//,
    index_letter[45] = 50;		//-
    index_letter[46] = 51;		//.
    index_letter[47] = 52;		//BARRA
    index_letter[58] = 53;		//:
    index_letter[59] = 54;		//;
    index_letter[60] = 55;		//<
    index_letter[62] = 56;		//>
    index_letter[61] = 57;		//=
    index_letter[63] = 58;		//?
    index_letter[64] = 59;		//@
    index_letter[91] = 60;		//[
    index_letter[93] = 61;		//]
    index_letter[92] = 62;		//CONTRA-BARRA
    index_letter[94] = 63;		//^
    index_letter[95] = 64;		//_
    index_letter[96] = 65;		//`
    index_letter[123] = 66;		//{
    index_letter[125] = 67;		//}
    index_letter[126] = 68;		//~
    index_letter[124] = 69;		//|
    index_letter[170] = 70;		//ª
    index_letter[186] = 71;		//º
    index_letter[191] = 72;		//¿
    index_letter[174] = 73;		//®
    index_letter[172] = 74;		//¬
    index_letter[189] = 75;		//½
    index_letter[188] = 76;		//¼
    index_letter[161] = 77;		//¡
    index_letter[171] = 78;		//«
    index_letter[187] = 79;		//»
    index_letter[169] = 80;		//©
    index_letter[208] = 81;		//Ð
    index_letter[166] = 82;		//¦
    index_letter[175] = 83;		//¯
    index_letter[180] = 84;		//´
    index_letter[190] = 85;		//¾
    index_letter[177] = 86;		//±
    index_letter[167] = 87;		//§
    index_letter[247] = 88;		//÷
    index_letter[176] = 89;		//°
    index_letter[185] = 90;		//¹
    index_letter[178] = 91;		//²
    index_letter[179] = 92;		//³
    index_letter[168] = 93;		//¨

    index_letter[248] = 94;		//ø
    index_letter[216] = 94;		//Ø

    index_letter[163] = 95;		//£
    index_letter[402] = 96;		//ƒ
    index_letter[181] = 97;		//µ

    index_letter[199] = 98;		//Ç
    index_letter[231] = 98;		//ç

}

// função que converte os caracteres de string nos indexes pré estabelecidos na função make_index_letter
vector<int> convert_string_to_indexes(string a)
{
    vector<int> v;

    setlocale(LC_ALL,"");
    wchar_t w[a.length()];
    const char* nw = a.c_str();
    mbsrtowcs(w, &nw, a.length(), NULL);
    w[a.length()] = 0;

    for(unsigned int i = 0; i < wcslen(w); i++)
    {
        v.push_back(index_letter[w[i]]);
    }

    return v;
}

//função que procura uma sbstring dentro de uma string, retornando o número da posição em que a substring inicia dentro da string
int search_in_string(string s1, string s2)
{	
	if(s2.size() != 0)
	{
		// converte os caracteres das duas strings m nossos indexes
		vector<int> v1 = convert_string_to_indexes(s1);
		vector<int> v2 = convert_string_to_indexes(s2);
		int position = 1;
		
		//compara os caracteres procurando a substring
		for(unsigned int i = 0; i < v1.size(); i++)
		{
			int at = v2[0];
			if(v1[i] == 37) position++;

			if(at == v1[i] && (i == 0 || v1[i-1] == 37))
			{
				unsigned int j = 1;
				unsigned int k = i+1;
				if(j < v2.size() && k < v1.size())
				{
					while(j < v2.size() && k < v1.size())
					{
						if(v2[j] != v1[k])
						{
							break;
						}
						else if(j+1 == v2.size())
						{
							return position;
						}

						j++;
						k++;
					}
				}
				else
				{
					return position;
				}
			}

		}

		return 0;
	}
	else
	{
		cout << "--- ATENÇÃO ----------------------------------------------------------------- " << endl; 
		cout << "String vazia foi procurada na palavra " << s1 << endl; 
		cout << "Reportar ao Daniel se acontecer muitas vezes" << endl;
		cout << "----------------------------------------------------------------------------- " << endl;
		return 0;
	}
}


///----- INSERT  ---------------------------------------------------------------------------------------
// procedimento de inserção de nova palavra na arvore
void insert(string new_word, string element_name, int id, int position)
{

    // este bloco transforma a string em const char*
    setlocale(LC_ALL,"");
    wchar_t w[new_word.length()];
    const char* nw = new_word.c_str();
    mbsrtowcs(w, &nw, new_word.length(), NULL);
    w[new_word.length()] = 0;

    node *current = head;

	current->count_prefix_element++; //incrementa o numero de elementos que a subarvore que inicia neste nó contem

    // percorre a arvore adicionando novos nodes (caso necessário) para cada letra da palavra
    for(unsigned int i = 0; i < wcslen(w); i++)
    {
        int letter = index_letter[w[i]];

        if(current->child[letter] == NULL)
        {
            current->child[letter] = new node();
        }

		current->child[letter]->count_prefix_element++; //incrementa o numero de elementos que a subarvore que inicia neste nó contem

        current = current->child[letter];
    }

	
	// adiciona o novo elemento ao hash map de elementos, usando o nome do elemento apenas caso a posição da new_word seja 1, pra evitar duplicação
    if(position == 1)
    {
		
		elements[id].word = element_name;
		elements[id].id = id;
		elements[id].active = true;
	}

	
	/* caso a palavra está entrando na trie pela primeira vez, no ultimo node é criado uma lista para guardar ponteiros para 
	   elementos que possuam esta palavra no nome */
    if(current->is_end == false)
    {
        current->is_end = true; // informa que o node é o ultimo node daquela palavra

		list<element_words> listElements;
		word_lists_element[current] = listElements;

    }

	// cria uma nova referencia na lista, guardando o id do elemento e a posição da palavra no nome do elemento
    
	element_words ew;
	ew.position = position;
	ew.element = &elements[id];
	word_lists_element[current].push_back(ew); // é inserido na lista
	
}


///----- SEARCH -----------------------------------------------------------------------------------------
// função que indica se uma palavra está cadastrada na arvore
bool search(string word)
{
    setlocale(LC_ALL,"");
    wchar_t w[word.length()];
    const char* nw = word.c_str();

    node *current = head;

    mbsrtowcs(w, &nw, word.length(), NULL);
    w[word.length()] = 0;

    for(unsigned int i = 0; i < wcslen(w); i++)
    {
        if(current->child[index_letter[w[i]]] == NULL)
        {
            return false;
        }

        current = current->child[index_letter[w[i]]];
    }

    return current->is_end;
}

///----- NUMERO DE PALAVRAS COM O PREFIXO -------------------------------------------------------------
// função que informa quantas palavras na arvore um dado prefixo possui
int number_of_elements_with_prefix(string prefix)
{
    setlocale(LC_ALL,"");

    wchar_t w[prefix.length()];
    const char* nw = prefix.c_str();

    mbsrtowcs(w, &nw, prefix.length(), NULL);
    w[prefix.length()] = 0;
    node *current = head;

    for (unsigned int i = 0; i < wcslen(w); i++)
    {

        if(current->child[index_letter[w[i]]] == NULL)
        {
            return 0;
        }
        else
        {
            current = current->child[index_letter[w[i]]];
        }

    }

    return current->count_prefix_element;
}

///----- CAMINHA NA ARVORE PEGANDO AS PALAVRAS ---------------------------------------------------------

element_words elements_found[600000];
int n_elements_found = 0;


// função que caminha recursivamente pela subarvore coletando as palavras cadastradas que começam com um dado prefixo
void interator_trie(node *current, bool is_prefix)
{
    // comando basico
    if(current->is_end == true)
    {
		
		for (list<element_words>::iterator it = word_lists_element[current].begin(); it != word_lists_element[current].end(); ++it)
		{
			element_words ew = *it;
			if(ew.element->active && (n_elements_found == 0 || elements_found[n_elements_found-1].element->id != ew.element->id)){
				elements_found[n_elements_found] = *it;
				n_elements_found++;
			}

		}
		
    }

	// comando recursivo: utiliza um for, pois cada node possui um hash map de filhos. O for percorre todos os filhos
	// funciona apenas se a consulta possui mais de uma palavra ou uma palavra completa que termine com espaço
    if(is_prefix == true)
    {
        for (unordered_map<int, node*>::iterator i = current->child.begin(); i != current->child.end(); ++i)
        {
			if(current->child[i->first] != NULL)
			{
				interator_trie(current->child[i->first], is_prefix);
			}
        }
    }

}


///----- PEGA AS PALAVRAS COM O PREFIXO ----------------------------------------------------------------
// função que pega o prefixo, caminha até achar o ultimo node do prefixo (acha a subarvore)
// utiliza o interator_trie para percorrer a subarvore e pegar as palavras
void words_with_prefix(string prefix, bool is_prefix)
{

    setlocale(LC_ALL,"");
    wchar_t w[prefix.length()+1];
    const char* nw = prefix.c_str();
    mbsrtowcs(w, &nw, prefix.length(), NULL);
    w[prefix.length()] = 0;


    node *current = head;

    for (unsigned int i = 0; i < wcslen(w); i++)
    {

        if(current->child[index_letter[w[i]]] == NULL)
        {
            return;
        }
        else
        {
            current = current->child[index_letter[w[i]]];
        }
    }

    interator_trie(current, is_prefix);

}



// FAZER AS CONSULTAS CONSULTAS ---------------------------------------------------------------------

// função que faz o split de strings separando por espaço
vector<string> split(string str, char delimiter) {
	
	if(delimiter != ' ')
		str = " " + str + " ";
	
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    

    while(getline(ss, tok, delimiter)) {
		
        internal.push_back(tok);
    }
    return internal;
}


// procedimento que ordena o vetor de resultados de acordo com a posição da palavra de consulta no nome do produto
void sortElements(element_words vetor[], int inicio, int fim){

	int pivo, i, j, meio;
	element_words aux;

	i = inicio;
	j = fim;

	meio = (int) ((i + j) / 2);
	pivo = vetor[meio].position;

	do{
		while (vetor[i].position < pivo) i = i + 1;
		while (vetor[j].position > pivo) j = j - 1;

		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}

	}while(j > i);

	if(inicio < j) sortElements(vetor, inicio, j);
	if(i < fim) sortElements(vetor, i, fim);

}


// função que, a partir das respostas obtidas com a consulta da primeira palavra, é feito a consulta 
// a partir da segunda dentro dos resultados da primeira
void detail_query_elements(vector<string> words_query)
{
	element_words aux_vet[n_elements_found+1];
    int n_respostas = n_elements_found;
    
    // passa todos os produtos pro vetor auxiliar
    for(int i = 0; i < n_elements_found; i++)
	{
		aux_vet[i] = elements_found[i];
	}

	// percorre o vetor de respostas procurando a segunda palavra
	// depois percorre as respostas que tenham as duas primeiras palavras e procura-se a terceira,
	// assim sucessivamente até a n-ésima palavra
	// por fim, insere-se no vetor found o resultado das buscas.
    for(unsigned int i = 1; i < words_query.size(); i++)
    {
        n_respostas = 0;

        for( int j = 0; j < n_elements_found; j++)
        {
			if(search_in_string(elements_found[j].element->word, words_query[i]))
            {
                aux_vet[n_respostas] = elements_found[j];
                n_respostas++;
            }
        }

        for(int i = 0; i < n_respostas; i++) 
        {
            elements_found[i] = aux_vet[i];
        }

        n_elements_found = n_respostas;

    }
     
	sortElements(elements_found, 0, n_elements_found-1);
	
}



// função que configura e executa uma consulta
string query(string query, int quant)
{
	
    vector<string> words_query; //vector que guarda as palavras da consuta
    bool is_prefix;
	
	// faz o split separando as palavras da consulta
    if(query.find(" ") < query.size())
    {
        words_query = split(query, ' ');
        is_prefix = false;
    }
    else
    {
        words_query.push_back(query);
        is_prefix = true;
    }
    
	words_with_prefix(words_query[0], is_prefix); // faz a consulta de produtos da primeira palavra na trie
	sortElements(elements_found, 0, n_elements_found-1); // ordena as respostas dos produtos
	detail_query_elements(words_query); // faz a consulta dos restos das palavras
	

    n_elements_found = 0;
    
    return "foi";
	
}


// ---- INSERE AS PALAVRAS DO BANCO NO MAP DE PALAVRAS --------------------------------------------

bool replace(string& str, const string& from, const string& to) {
	
	bool ret = true;
	string aux = str;
	
	while (ret == true)
	{
		size_t start_pos = aux.rfind(from);
		if(start_pos == string::npos){
			ret = false;
		}
		else {
			str.replace(start_pos, from.length(), to);
			aux.replace(start_pos, from.length(), "¬");
			ret = true;
		}
	}
	
    return ret;
}


void insert_new_element(string element_id, string el)
{
	// product está nesse formato: "ID*DESCRIÇÃO DO ELEMENTO"
	
	vector<string> sep = split(el, ' ');
	
	int id = atoi(element_id.c_str());
				
	string element_name;

	for(unsigned int j = 0; j < sep.size(); ++j){
		if(j == 0)
			element_name = sep[j];
		else
			element_name = element_name + " " + sep[j];

	}
	
	for(unsigned int i = 0; i < sep.size(); ++i){
		insert(sep[i], element_name, id, i+1);
	}
	
	sep.clear();

}

void remove_element(int id){
	
	Telement ne;
	
	elements.erase(id);
	elements[id] = ne;
	
}

void update_element(string element_id, string el){

	Telement ne;
	elements.erase(atoi(element_id.c_str()));
	elements[atoi(element_id.c_str())] = ne;
	
	insert_new_element(element_id, el);
}

bool exist_element(int id){
	
	Telement e;
	
	if(elements.find(id) != elements.end())
		e = elements[id];
	else
		return false;
	
	if (e.active == false)
		return false;
	else
		return true;
}


 void insert_machine(){
 
     ifstream myReadFile;
     string line;
 
 
     myReadFile.open("paises");
 
     cout << "Carregando base de dados...." <<endl;
 
 
     if (myReadFile.is_open())
     {
         while (getline(myReadFile, line))
         {
 
             vector<string> sep = split(line, ' ');
 
			string element_name;
			
			cout << sep[0] << endl;
			
			int id = atoi(sep[0].c_str());
			
			element_name = sep[1];
			for(unsigned int j = 2; j < sep.size(); ++j){
				element_name = element_name + " " + sep[j];
 
             }
 
			for(unsigned int i = 1; i < sep.size(); ++i){
 
                 insert(sep[i], element_name, id, i);
             }
            
         }
     }
     else{
		 cout << "Erro ao ler o arquivo" << endl;
	 }
 
     myReadFile.close();
 
     system("clear");
 }


int main()
{

    make_index_letter();
    init();


    insert_machine();


    char w[50];

    cout << elements.size() << endl;
    do{
        cout << "\n------------------------------------------------------" << endl;
        scanf ("%[^\n]s", w);
        setbuf(stdin, NULL);
        
        vector<string> spl = split(w, '*');
		int key = atoi(spl[0].c_str());
		
		string found;
		
		if(key == 1 && spl.size() == 3){ //busca somente produto -> 3*string de busca*num de retorno
			int quant = atoi(spl[2].c_str());
			found = query(spl[1], quant);
			cout << spl[1] << endl;
		}
		else if(key == 0 && spl.size() == 3){ //insere item -> 0*id*nome
			int id = atoi(spl[1].c_str());
			
			if(!exist_element(id)){
				insert_new_element(spl[1], spl[2]);
				found = "Produto inserido";
			}
			else{
				found = "id de produto \'" + spl[1] + "\' já existe";
			}
			
		}
		else if(key == 9 && spl.size() == 2){ //remove um item -> 4*id
			int id = atoi(spl[1].c_str());

			if(exist_element(id)){
				remove_element(id);
				found = "Produto removido";
			}
			else{
				found = "Não há nenhum produto com o id \'" + spl[1] + "\'";
			}
				
		}
		else if(key == 2 && spl.size() == 3){ //altera item -> 9*id*nome
			int id = atoi(spl[1].c_str());

			if(exist_element(id)){
				update_element(spl[1], spl[2]);
				found = "Produto alterado";
			}
			else{
				found = "Não há nenhum produto com o id \'" + spl[1] + "\'";
			}

		}
		else{
			found = "comando_invalido";
		}
		
		cout << found.c_str() << endl << endl;
        
        cout << "------------------------------------------------------" << endl;


    }while(strcmp(w, "0"));



}
























