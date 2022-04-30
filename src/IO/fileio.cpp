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

vector<Player*> FileIo::getPlayersList()
{
    fstream userFile;
    userFile.open("users.txt", ios::in);
    vector<Player*> players;
    if (userFile.is_open())
    {
        vector<string> playerLineResult;
        string lineData;
        bool hasFoundUser = false;
        while(getline(userFile, lineData))
        {
            playerLineResult = this-> splitLineData(lineData);
            players.push_back(this-> buildPlayer(playerLineResult));
        }

    }
    return players;
}

/**< private */
Player* FileIo::buildPlayer(vector<string> currentLineResults)
{
    int playerUserNameIndex = 0;
    int winPercentageIndex = 1;
    int totalGamesPlayerIndex = 2;
    int currentWinStreakIndex = 3;
    int maxWinStreakIndex = 4;
    int numOneTryWinsIndex = 5;
    int numTwoTryWinsIndex = 6;
    int numThreeTryWinsIndex = 7;
    int numFourTryWinsIndex = 8;
    int numFiveTryWinsIndex = 9;
    int numSixTryWinsIndex = 10;

    string userName = currentLineResults[playerUserNameIndex];
    double winPercentage = stoi(currentLineResults[winPercentageIndex]);
    int totalGamesPlayed = stoi(currentLineResults[totalGamesPlayerIndex]);
    int currentWinStreak = stoi(currentLineResults[currentWinStreakIndex]);
    int maxWinStreak = stoi(currentLineResults[maxWinStreakIndex]);

    int winDistribution [6];
    winDistribution[0] = stoi(currentLineResults[numOneTryWinsIndex]);
    winDistribution[1] = stoi(currentLineResults[numTwoTryWinsIndex]);
    winDistribution[2] = stoi(currentLineResults[numThreeTryWinsIndex]);
    winDistribution[3] = stoi(currentLineResults[numFourTryWinsIndex]);
    winDistribution[4] = stoi(currentLineResults[numFiveTryWinsIndex]);
    winDistribution[5] = stoi(currentLineResults[numSixTryWinsIndex]);

    Player* player = new Player(userName,
                                winPercentage,
                                totalGamesPlayed,
                                currentWinStreak,
                                maxWinStreak,
                                winDistribution);
    return player;
}


vector<string> FileIo::splitLineData(const string& lineData)
{
    stringstream sstream(lineData);
    vector<string> results;

    while(sstream.good())
    {
        string substring;
        getline(sstream, substring, ',');
        results.push_back(substring);
    }

    return results;

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
