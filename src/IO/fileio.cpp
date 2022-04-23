#include "fileio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <strings.h>
#include <algorithm>

using namespace std;
namespace IO
{

/** \brief Constructor
 */
FileIo::FileIo()
{
    //ctor
}

/** \brief will load the words from words.txt for the word list.
 *
 */
void FileIo::loadWords()
{
    fstream file;
    file.open("words.txt", ios::in);
    {
        string word;
        while(getline(file, word))
        {
            if(word.length() == 5)
            {
                cout << word << endl;
            }
        }
    }
}

/** \brief Destructor
 */
FileIo::~FileIo()
{
    //dtor
}
}
