#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <string>
#include "fileio.h"
#include <vector>
using namespace model;
using namespace IO;
using namespace std;
namespace Controller
{
class LoginController
{
    public:
        Player* getCurrentPlayer();

        vector<Player*> getActivePlayers();
        void loadOrCreatePlayer(const string& username);
        void loadAllPlayers();
        LoginController();
        virtual ~LoginController();

    protected:

    private:
        Player* currentPlayer;
        vector<Player*> activePlayers;

        FileIo* fileIo;
};
}
#endif // LOGINCONTROLLER_H
