#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <string>
#include "document.h"
#include "file_access.h"
using namespace std;

int testLDA()
{
    struct corpus* cps;
    cps = read_corpus("lda-master/input/ap.dat");

    return 0;
}


#endif // TEST_H_INCLUDED
