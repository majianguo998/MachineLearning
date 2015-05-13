#include <string>
#include <sstream>
#include "document.h"

int create_document(document* doc,int* max_id,string line)
{
    int wp;
    string temp;
    istringstream istream(line);

    istream>>doc->length;
    wp = 0;
    doc->num_term = 0;
    doc->words = (struct word*)malloc(sizeof(struct word) * doc->length);
    while(istream>>temp)
    {
        int word_id;
        int count;
        sscanf(temp.c_str(),"%d:%d",&word_id,&count);
        doc->words[wp].id = word_id;
        doc->words[wp].count = count;
        if(*max_id <= doc->words[wp].id)
        {
            *max_id = doc->words[wp].id + 1;
        }
        wp++;
    }
	doc->num_term = wp;
    return 1;
}
