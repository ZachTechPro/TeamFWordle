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
string FileIo::loadWords()
{
    srand(time(0));
    fstream file;
    int counter = 0;
    vector<string> words;
    file.open("words.txt", ios::in);
    {
        string word;
        while(getline(file, word))
        {
            if(word.length() == 5)
            {

                words.push_back(word);
                counter++;
                cout<<to_string(counter);
                cout << word << endl;
            }
        }
    }
    int random = rand() % words.size();
    cout<<words[random];
    cout<<random;
    return words[random];
}

/** \brief Destructor
 */
FileIo::~FileIo()
{
    //dtor
}
}
