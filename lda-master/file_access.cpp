#include <stdio.h>
#include <fstream>
#include <iostream>
#include "document.h"
#include "file_access.h"

using namespace std;

struct corpus* read_corpus(char* corpus_path)
{
    ifstream infile(corpus_path);
    string line;
    corpus* cps = (struct corpus*)malloc(sizeof(struct corpus));
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
    }
    cps->num_terms = doc_count;
    infile.close();
    return cps;
}
