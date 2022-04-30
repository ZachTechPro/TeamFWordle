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
    vector<Player*> players;

    auto iter = csv_contents.begin();
    while (iter != csv_contents.end()) {
        cout << "[" << iter->first << ","
                    << iter->second[0] << "]\n";
        char *p;
        int distribution[6];
        distribution[0] = stoi(iter->second[5]);
        distribution[1] = stoi(iter->second[6]);
        distribution[2] = stoi(iter->second[7]);
        distribution[3] = stoi(iter->second[8]);
        distribution[4] = stoi(iter->second[9]);
        distribution[5] = stoi(iter->second[10]);
        players.push_back(new Player(iter->second[0],stoi(iter->second[1]), atof(iter->second[2].c_str()), stoi(iter->second[3]), stoi(iter->second[4]), distribution));
        ++iter;
    }
    cout<<players[0]->getUserName();
    cout << endl;
    return 0;
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
