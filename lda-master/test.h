#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>
#include <string>
#include "document.h"
#include "file_access.h"
using namespace std;

int testLDA()
{
    struct corpus* cps;
    cps = read_corpus("lda-master/input/ap.dat");

	cout<<"edlsss"<<endl;

	for(int i=0;i<cps->num_docs;i++)
	{
		cout<<cps->docs[i].id<<"\t"<<cps->docs[i].length<<endl;
	}

    return 0;
}


#endif // TEST_H_INCLUDED
