#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

#include <string>
#include <stdio.h>
using namespace std;

struct word
{
    int id;
    int count;
};

struct document
{
    struct word* words;
    int id;
    int num_term;
    int length;
};

struct corpus
{
    struct document* docs;
    int num_docs;
    int num_terms;
};

int create_document(document* doc,int* max_id,string line);

#endif // DOCUMENT_H_INCLUDED
