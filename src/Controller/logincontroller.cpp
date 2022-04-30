#include "logincontroller.h"
#include <iostream>
#include <string>
using namespace std;
namespace Controller
{
LoginController::LoginController()
{
     this-> fileIo = new FileIo();
     this-> currentPlayer = 0 ;
}

void LoginController::loadOrCreatePlayer(const string& username)
{
    for (Player* currPlayer : this-> activePlayers)
    {
        if (currPlayer-> getUserName().compare(username) == 0)
        {
            this-> currentPlayer = currPlayer;
            return;
        }
    }

    this-> currentPlayer = new Player();
    this-> currentPlayer-> setUserName(username);
}

vector<Player*> LoginController::getActivePlayers()
{
    return this-> activePlayers;
}

void LoginController::loadAllPlayers()
{
    this-> activePlayers = this-> fileIo-> getPlayersList();
}

Player* LoginController::getCurrentPlayer()
{
    return this-> currentPlayer;
}

LoginController::~LoginController()
{
    delete this-> fileIo;
}
}
