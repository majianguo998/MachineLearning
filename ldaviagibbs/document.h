#ifndef DOC_H
#define DOC_H

#include <stdio.h>
#include <string>

using namespace std;

struct word
{
	int id;
	int count;
};

struct document
{
	int id;
	int num_term; // number of terms in a document. note that one term may have more than one count: <word id>:<count>
	int length; // length of lines which represent documents. length is actually the total number of <word id>:<count> in one document
	struct word* words;
};

struct corpus
{
	struct document* docs;
	int num_docs;
	int num_terms; // record how many terms are in the vocabulary. this is get from the max id of words plus 1;
};

int create_document(document* doc,int* max, string line);

#endif
