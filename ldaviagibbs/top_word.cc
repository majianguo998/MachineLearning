#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("usage: ./topword [phi_file] [vocab_file][out_file]\n");
	}
	char *phi_file = argv[1];
	char *voc_file = argv[2];
	char *out_file = argv[3];
	// read vocabulary
	ifstream voc(voc_file);
	map<int, string> vocabulary;
	string term;
	int index = 0;
	while(getline(voc,term))
	{
		vocabulary[index]=term;
		index++;
	}
	voc.close();
	//read phi
	ifstream infile(phi_file);
	ofstream top_word(out_file);
	string line;
	int topic_id = 0;
	while (getline(infile,line))
	{
		map<double,int> doc_phi;
		map<double,int>::iterator m_it = doc_phi.end();
 		double temp;
		istringstream istream(line);
		for (int i=0;i<(int)vocabulary.size();i++)
		{
			if(!(istream >> temp))
			{
				printf("error ");
				return 1;
			}
			doc_phi[temp] = i;
		}

		// cout 25 top popular word
		top_word << topic_id << endl;
		for (int w=0;w<25;w++)
		{
			m_it--;
			top_word << vocabulary[m_it->second] << "\n";
		}
		topic_id++;
	}

	top_word.close();
	infile.close();
	return 0;
}
