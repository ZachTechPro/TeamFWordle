#ifndef FILEIO_H
#define FILEIO_H
#include <string>
#include <vector>
#include "player.h"
using namespace model;
using namespace std;

namespace IO
{

class FileIo
{
    public:
        Player* loginOrCreatePlayer(const string& userName);
        vector<Player*> getPlayersList();
        bool canFindUser(const string& userName);
        string loadWords();
        FileIo();
        virtual ~FileIo();

    protected:

    private:
        void loadPlayers();
        Player* buildPlayer(vector<string> currentLineResults);
        vector<string> splitLineData(const string& lineData);
        string readFileIntoString(const string& path);
};
}
#endif // FILEIO_H
