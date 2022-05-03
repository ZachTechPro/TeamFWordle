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

/// \brief gets the list of players from the csv
///
/// \return vector<Player*>
///
///
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
    int isOnWinStreakIndex = 11;

    string userName = currentLineResults[playerUserNameIndex];
    double winPercentage = stoi(currentLineResults[winPercentageIndex]);
    int totalGamesPlayed = stoi(currentLineResults[totalGamesPlayerIndex]);
    int currentWinStreak = stoi(currentLineResults[currentWinStreakIndex]);
    int maxWinStreak = stoi(currentLineResults[maxWinStreakIndex]);
    bool isOnWinStreak = currentLineResults[isOnWinStreakIndex] == "1";
    int winDistribution [6];
    winDistribution[0] = stoi(currentLineResults[numOneTryWinsIndex]);
    winDistribution[1] = stoi(currentLineResults[numTwoTryWinsIndex]);
    winDistribution[2] = stoi(currentLineResults[numThreeTryWinsIndex]);
    winDistribution[3] = stoi(currentLineResults[numFourTryWinsIndex]);
    winDistribution[4] = stoi(currentLineResults[numFiveTryWinsIndex]);
    winDistribution[5] = stoi(currentLineResults[numSixTryWinsIndex]);

    Player* player = new Player(userName,
                                totalGamesPlayed,
                                winPercentage,
                                currentWinStreak,
                                maxWinStreak,
                                winDistribution,
                                isOnWinStreak);
    return player;
}

/// \brief gets the list of words
///
/// \return vector<string>
///
///
vector<string> FileIo::getWords()
{
    return this-> words;
}

///< private
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
    this-> words = words;
    int random = rand() % words.size();
    return words[random];
}

/// \brief loads the words with no duplicate letters
///
/// \return string
///
///
string FileIo::loadWordsNoDuplicateLetters()
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
                if(areCharactersUnique(word))
                {
                    words.push_back(word);
                    counter++;
                }

            }
        }
    }
    this-> words = words;
    int random = rand() % words.size();
    return words[random];

}
///< private
bool FileIo::areCharactersUnique(string str)
{
    int checker = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        int val = (str[i]-'a');
        if ((checker & (1 << val)) > 0)
            return false;
        checker |=  (1 << val);
    }

    return true;
}
/// \brief saves the list of players to the csv
///
/// \param players[] Player*
/// \param playerLength int
/// \return void
///
///
void FileIo::SaveFile(Player* players[], int playerLength)
{
    string fileName = "users.txt";
    fstream file;
    file.open(fileName, ios::out);
    for(int i = 0; i < playerLength; i++)
    {
        Player* player = players[i];
        file << (player->getUserName() + "," + to_string(player->getWinPercentage()) + ","
                 + to_string(player->getTotalGamesPlayed()) + "," + to_string(player->getCurrentWinStreak())
                 + "," + to_string(player->getMaxWinStreak()) + "," + to_string(player->getOneTryWins())
                 +"," + to_string(player->getTwoTryWins()) +"," + to_string(player->getThreeTryWins())
                 + "," + to_string(player->getFourTryWins()) + "," + to_string(player->getFiveTryWins())
                 + "," + to_string(player->getSixTryWins())) + "," + to_string(player-> getIsOnWinStreak()) + "\n";
    }
    file.close();

}

/** \brief Destructor
 */
FileIo::~FileIo()
{
    //dtor
}
}
