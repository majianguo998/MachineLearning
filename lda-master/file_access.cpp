#include <stdio.h>
#include <fstream>
#include <iostream>
#include "document.h"
#include "file_access.h"

using namespace std;

corpus* read_corpus(char* corpus_path)
{
    ifstream infile(corpus_path);
    string line;
    corpus* cps = (corpus*)malloc(sizeof(struct corpus));
	cps->docs  = NULL; //对语料库中的docs初始化，必须的一步
    int doc_count = 0;
    if(!infile)
    {
        cout<<"unable to open input file."<<endl;
        return 0;
    }
    cps->num_terms = 0;

    while(getline(infile,line))
    {
        cps->docs = (struct document*)realloc(cps->docs,sizeof(struct document) * (doc_count+1));
        if(cps->docs == NULL)
        {
            cout<<"out of memory."<<endl;
            exit(1);
        }
        cps->docs[doc_count].id = doc_count;
        create_document(&cps->docs[doc_count],&cps->num_terms,line);
        doc_count++;

		if(doc_count%100 == 0) cout<<doc_count<<endl;

    }
	cps->num_docs = doc_count;
    infile.close();
    return cps;
}
