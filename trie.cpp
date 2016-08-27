#include "trie.h"

Trie::Trie()
{
	cout << "Creating Digital Tree..." << endl;
}

Trie::~Trie()
{
	cout << "Removing Digital Tree..." << endl;
}

void Trie::Init(string dataset_path)
{
	//Load file
	util.make_index_letter(&index_letter);
	//initialize head of tree
	head = new node();
    head->count_prefix_element = 0;
    head->is_end = false;

    insert_machine(dataset_path);
}

vector<int> Trie::Search(string q, int qtd)
{
	vector<int> v;
	v = query(q, qtd);

	return v;
}

bool Trie::InsertElement(int id, string elem)
{
	if(!exist_element(id))
		insert_new_element(id, elem);
	else
		return false;

	return true;
}

bool Trie::RemoveElement(int id)
{
	if(exist_element(id))
		remove_element(id);
	else
		return false;

	return true;
}

bool Trie::UpdateElement(int id, string newElem)
{
	if(exist_element(id))
		update_element(id, newElem);
	else
		return false;

	return true;
}

///----- INSERT  ---------------------------------------------------------------------------------------
// procedimento de inserção de nova palavra na arvore
void Trie::insert(string new_word, string element_name, int id, int position)
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
bool Trie::search(string word)
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
int Trie::number_of_elements_with_prefix(string prefix)
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


// função que caminha recursivamente pela subarvore coletando as palavras cadastradas que começam com um dado prefixo
void Trie::interator_trie(node *current, bool is_prefix)
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
void Trie::words_with_prefix(string prefix, bool is_prefix)
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


// função que, a partir das respostas obtidas com a consulta da primeira palavra, é feito a consulta 
// a partir da segunda dentro dos resultados da primeira
void Trie::detail_query_elements(vector<string> words_query)
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
			if(util.search_in_string(elements_found[j].element->word, words_query[i], &index_letter))
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
     
	util.sortElements(elements_found, 0, n_elements_found-1);
	
}

// função que configura e executa uma consulta
vector<int> Trie::query(string query, int quant)
{
	vector<int> v;
    vector<string> words_query; //vector que guarda as palavras da consuta
    bool is_prefix;
	
	// faz o split separando as palavras da consulta
    if(query.find(" ") < query.size())
    {
        words_query = util.split(query, ' ');
        is_prefix = false;
    }
    else
    {
        words_query.push_back(query);
        is_prefix = true;
    }
    
	words_with_prefix(words_query[0], is_prefix); // faz a consulta de produtos da primeira palavra na trie
	util.sortElements(elements_found, 0, n_elements_found-1); // ordena as respostas dos produtos
	detail_query_elements(words_query); // faz a consulta dos restos das palavras
	
	int i;
	for(i = 0; i < n_elements_found && i < quant; i++){
		cout << elements_found[i].element->word << endl;
		v.push_back(elements_found[i].element->id);
	}

    n_elements_found = 0;
    
    return v;
	
}

void Trie::insert_new_element(int element_id, string el)
{
	// product está nesse formato: "ID*DESCRIÇÃO DO ELEMENTO"
	
	vector<string> sep = util.split(el, ' ');
	
	int id = element_id;
				
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

void Trie::remove_element(int id){
	
	Telement ne;
	
	elements.erase(id);
	elements[id] = ne;	
}

void Trie::update_element(int element_id, string el){

	Telement ne;
	elements.erase(element_id);
	elements[element_id] = ne;
	
	insert_new_element(element_id, el);
}

bool Trie::exist_element(int id){
	
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

void Trie::insert_machine(string path){
 
     ifstream myReadFile;
     string line;

     myReadFile.open(path);
     cout << "Loading database...." <<endl;
     if (myReadFile.is_open())
     {
         while (getline(myReadFile, line))
         {
            vector<string> sep = util.split(line, ' ');
			string element_name;
			
			// cout << sep[0] << endl;
			
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
 }