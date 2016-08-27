#include "util.h"

Util::Util()
{
	
}

Util::~Util()
{
	
}

void Util::make_index_letter(unordered_map<int, int>* index_letter)
{
    index_letter->insert(pair<int,int>(65,1));		//A
    index_letter->insert(pair<int,int>(97,1));		//a
    index_letter->insert(pair<int,int>(194,1));		//Â
    index_letter->insert(pair<int,int>(226,1));		//â
    index_letter->insert(pair<int,int>(196,1));		//Ä
    index_letter->insert(pair<int,int>(228,1));		//ä
    index_letter->insert(pair<int,int>(192,1));		//À
    index_letter->insert(pair<int,int>(224,1));		//à
    index_letter->insert(pair<int,int>(229,1));		//å
    index_letter->insert(pair<int,int>(197,1));		//Å
    index_letter->insert(pair<int,int>(193,1));		//Á
    index_letter->insert(pair<int,int>(225,1));		//á
    index_letter->insert(pair<int,int>(195,1));		//Ã
    index_letter->insert(pair<int,int>(227,1));		//ã

    index_letter->insert(pair<int,int>(66,2));		//B
    index_letter->insert(pair<int,int>(98,2));		//b

    index_letter->insert(pair<int,int>(67,3));		//C
    index_letter->insert(pair<int,int>(99,3));		//c

    index_letter->insert(pair<int,int>(68,4));		//D
    index_letter->insert(pair<int,int>(100,4));		//d

    index_letter->insert(pair<int,int>(69,5));		//E
    index_letter->insert(pair<int,int>(101,5));		//e
    index_letter->insert(pair<int,int>(201,5));		//É
    index_letter->insert(pair<int,int>(233,5));		//é
    index_letter->insert(pair<int,int>(203,5));		//Ë
    index_letter->insert(pair<int,int>(235,5));		//ë
    index_letter->insert(pair<int,int>(200,5));		//È
    index_letter->insert(pair<int,int>(232,5));		//è
    index_letter->insert(pair<int,int>(202,5));		//Ê
    index_letter->insert(pair<int,int>(234,5));		//ê

    index_letter->insert(pair<int,int>(70,6));		//F
    index_letter->insert(pair<int,int>(102,6));		//f

    index_letter->insert(pair<int,int>(71,7));		//G
    index_letter->insert(pair<int,int>(103,7));		//g

    index_letter->insert(pair<int,int>(72,8));		//H
    index_letter->insert(pair<int,int>(104,8));		//h

    index_letter->insert(pair<int,int>(73,9));		//I
    index_letter->insert(pair<int,int>(105,9));		//i
    index_letter->insert(pair<int,int>(207,9));		//Ï
    index_letter->insert(pair<int,int>(239,9));		//ï
    index_letter->insert(pair<int,int>(204,9));		//Ì
    index_letter->insert(pair<int,int>(236,9));		//ì
    index_letter->insert(pair<int,int>(205,9));		//Í
    index_letter->insert(pair<int,int>(237,9));		//í
    index_letter->insert(pair<int,int>(206,9));		//Î
    index_letter->insert(pair<int,int>(238,9));		//î

    index_letter->insert(pair<int,int>(74,10));		//J
    index_letter->insert(pair<int,int>(106,10));		//j

    index_letter->insert(pair<int,int>(75,11));		//K
    index_letter->insert(pair<int,int>(107,11));		//k

    index_letter->insert(pair<int,int>(76,12));		//L
    index_letter->insert(pair<int,int>(108,12));		//l

    index_letter->insert(pair<int,int>(77,13));		//M
    index_letter->insert(pair<int,int>(109,13));		//m

    index_letter->insert(pair<int,int>(78,14));		//N
    index_letter->insert(pair<int,int>(209,14));		//Ñ
    index_letter->insert(pair<int,int>(241,14));		//ñ
    index_letter->insert(pair<int,int>(110,14));		//n

    index_letter->insert(pair<int,int>(79,15));		//O
    index_letter->insert(pair<int,int>(111,15));		//o
    index_letter->insert(pair<int,int>(212,15));		//Ô
    index_letter->insert(pair<int,int>(244,15));		//ô
    index_letter->insert(pair<int,int>(214,15));		//Ö
    index_letter->insert(pair<int,int>(246,15));		//ö
    index_letter->insert(pair<int,int>(210,15));		//Ò
    index_letter->insert(pair<int,int>(242,15));		//ò
    index_letter->insert(pair<int,int>(211,15));		//Ó
    index_letter->insert(pair<int,int>(243,15));		//ó
    index_letter->insert(pair<int,int>(213,15));		//Õ
    index_letter->insert(pair<int,int>(245,15));		//õ

    index_letter->insert(pair<int,int>(80,16));		//P
    index_letter->insert(pair<int,int>(112,16));		//p

    index_letter->insert(pair<int,int>(81,17));		//Q
    index_letter->insert(pair<int,int>(113,17));		//q

    index_letter->insert(pair<int,int>(82,18));		//R
    index_letter->insert(pair<int,int>(114,18));		//r

    index_letter->insert(pair<int,int>(83,19));		//S
    index_letter->insert(pair<int,int>(115,19));		//s

    index_letter->insert(pair<int,int>(84,20));		//T
    index_letter->insert(pair<int,int>(116,20));		//t

    index_letter->insert(pair<int,int>(85,21));		//U
    index_letter->insert(pair<int,int>(117,21));		//u
    index_letter->insert(pair<int,int>(220,21));		//Ü
    index_letter->insert(pair<int,int>(252,21));		//ü
    index_letter->insert(pair<int,int>(217,21));		//Ù
    index_letter->insert(pair<int,int>(249,21));		//ù
    index_letter->insert(pair<int,int>(218,21));		//Ú
    index_letter->insert(pair<int,int>(250,21));		//ú
    index_letter->insert(pair<int,int>(219,21));		//Û
    index_letter->insert(pair<int,int>(251,21));		//û

    index_letter->insert(pair<int,int>(86,22));		//V
    index_letter->insert(pair<int,int>(118,22));		//v

    index_letter->insert(pair<int,int>(87,23));		//W
    index_letter->insert(pair<int,int>(119,23));		//w

    index_letter->insert(pair<int,int>(88,24));		//X
    index_letter->insert(pair<int,int>(120,24));		//x

    index_letter->insert(pair<int,int>(89,25));		//Y
    index_letter->insert(pair<int,int>(121,25));		//y
    index_letter->insert(pair<int,int>(376,25));		//Ÿ
    index_letter->insert(pair<int,int>(255,25));		//ÿ
    index_letter->insert(pair<int,int>(221,25));		//Ý
    index_letter->insert(pair<int,int>(253,25));		//ý

    index_letter->insert(pair<int,int>(90,26));		//Z
    index_letter->insert(pair<int,int>(122,26));		//z

    index_letter->insert(pair<int,int>(48,27));		//0
    index_letter->insert(pair<int,int>(49,28));		//1
    index_letter->insert(pair<int,int>(50,29));		//2
    index_letter->insert(pair<int,int>(51,30));		//3
    index_letter->insert(pair<int,int>(52,31));		//4
    index_letter->insert(pair<int,int>(53,32));		//5
    index_letter->insert(pair<int,int>(54,33));		//6
    index_letter->insert(pair<int,int>(55,34));		//7
    index_letter->insert(pair<int,int>(56,35));		//8
    index_letter->insert(pair<int,int>(57,36));		//9

    index_letter->insert(pair<int,int>(32,37));		//ESPAÇO
    index_letter->insert(pair<int,int>(33,38));		//!
    index_letter->insert(pair<int,int>(34,39));		//"
    index_letter->insert(pair<int,int>(35,40));		//#
    index_letter->insert(pair<int,int>(36,41));		//$
    index_letter->insert(pair<int,int>(37,42));		//%
    index_letter->insert(pair<int,int>(38,43));		//&
    index_letter->insert(pair<int,int>(39,44));		//'
    index_letter->insert(pair<int,int>(40,45));		//(
    index_letter->insert(pair<int,int>(41,46));		//)
    index_letter->insert(pair<int,int>(42,47));		//*
    index_letter->insert(pair<int,int>(43,48));		//+
    index_letter->insert(pair<int,int>(44,49));		//,
    index_letter->insert(pair<int,int>(45,50));		//-
    index_letter->insert(pair<int,int>(46,51));		//.
    index_letter->insert(pair<int,int>(47,52));		//BARRA
    index_letter->insert(pair<int,int>(58,53));		//:
    index_letter->insert(pair<int,int>(59,54));		//));
    index_letter->insert(pair<int,int>(60,55));		//<
    index_letter->insert(pair<int,int>(62,56));		//>
    index_letter->insert(pair<int,int>(61,57));		//=
    index_letter->insert(pair<int,int>(63,58));		//?
    index_letter->insert(pair<int,int>(64,59));		//@
    index_letter->insert(pair<int,int>(91,60));		//[
    index_letter->insert(pair<int,int>(93,61));		//]
    index_letter->insert(pair<int,int>(92,62));		//CONTRA-BARRA
    index_letter->insert(pair<int,int>(94,63));		//^
    index_letter->insert(pair<int,int>(95,64));		//_
    index_letter->insert(pair<int,int>(96,65));		//`
    index_letter->insert(pair<int,int>(123,66));		//{
    index_letter->insert(pair<int,int>(125,67));		//}
    index_letter->insert(pair<int,int>(126,68));		//~
    index_letter->insert(pair<int,int>(124,69));		//|
    index_letter->insert(pair<int,int>(170,70));		//ª
    index_letter->insert(pair<int,int>(186,71));		//º
    index_letter->insert(pair<int,int>(191,72));		//¿
    index_letter->insert(pair<int,int>(174,73));		//®
    index_letter->insert(pair<int,int>(172,74));		//¬
    index_letter->insert(pair<int,int>(189,75));		//½
    index_letter->insert(pair<int,int>(188,76));		//¼
    index_letter->insert(pair<int,int>(161,77));		//¡
    index_letter->insert(pair<int,int>(171,78));		//«
    index_letter->insert(pair<int,int>(187,79));		//»
    index_letter->insert(pair<int,int>(169,80));		//©
    index_letter->insert(pair<int,int>(208,81));		//Ð
    index_letter->insert(pair<int,int>(166,82));		//¦
    index_letter->insert(pair<int,int>(175,83));		//¯
    index_letter->insert(pair<int,int>(180,84));		//´
    index_letter->insert(pair<int,int>(190,85));		//¾
    index_letter->insert(pair<int,int>(177,86));		//±
    index_letter->insert(pair<int,int>(167,87));		//§
    index_letter->insert(pair<int,int>(247,88));		//÷
    index_letter->insert(pair<int,int>(176,89));		//°
    index_letter->insert(pair<int,int>(185,90));		//¹
    index_letter->insert(pair<int,int>(178,91));		//²
    index_letter->insert(pair<int,int>(179,92));		//³
    index_letter->insert(pair<int,int>(168,93));		//¨

    index_letter->insert(pair<int,int>(248,94));		//ø
    index_letter->insert(pair<int,int>(216,94));		//Ø
    index_letter->insert(pair<int,int>(163,95));		//£
    index_letter->insert(pair<int,int>(402,96));		//ƒ
    index_letter->insert(pair<int,int>(181,97));		//µ
    index_letter->insert(pair<int,int>(199,98));		//Ç
    index_letter->insert(pair<int,int>(231,98));		//ç
}

// função que converte os caracteres de string nos indexes pré estabelecidos na função make_index_letter
vector<int> Util::convert_string_to_indexes(string a, unordered_map<int, int>* index_letter)
{
    vector<int> v;

    setlocale(LC_ALL,"");
    wchar_t w[a.length()];
    const char* nw = a.c_str();
    mbsrtowcs(w, &nw, a.length(), NULL);
    w[a.length()] = 0;

    for(unsigned int i = 0; i < wcslen(w); i++)
    {
        v.push_back(index_letter->at(w[i]));
    }

    return v;
}


//função que procura uma sbstring dentro de uma string, retornando o número da posição em que a substring inicia dentro da string
int Util::search_in_string(string s1, string s2, unordered_map<int, int>* index_letter)
{	
	if(s2.size() != 0)
	{
		// converte os caracteres das duas strings m nossos indexes
		vector<int> v1 = convert_string_to_indexes(s1, index_letter);
		vector<int> v2 = convert_string_to_indexes(s2, index_letter);
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

// FAZER AS CONSULTAS CONSULTAS ---------------------------------------------------------------------

// função que faz o split de strings separando por espaço
vector<string> Util::split(string str, char delimiter) {
	
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
void Util::sortElements(element_words vetor[], int inicio, int fim){

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

bool Util::replace(string& str, const string& from, const string& to) {
	
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
