#include "fileio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <strings.h>
#include <algorithm>
#include "player.h"
#include <map>


using namespace model;
using namespace std;
namespace IO
{

/** \brief Constructor
 */
FileIo::FileIo()
{
}


bool FileIo::canFindUser(const string& userName)
{
    string filename("users.txt");
    string file_contents;
    std::map<string, std::vector<string>> csv_contents;
    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    std::vector<string> items;
    string record;

    while (std::getline(sstream, record)) {
        istringstream line(record);
        while (std::getline(line, record, delimiter)) {
            items.push_back(record);
        }

        csv_contents[items[0]] = items;
        items.clear();

    }
    string name = csv_contents["Max"][0];
    cout<<name;
    cout << "in the method" << endl;
    return true;

}
string FileIo::readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
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
                //cout<<to_string(counter);
                //cout << word << endl;
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
