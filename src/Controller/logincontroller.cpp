#include "logincontroller.h"
#include <iostream>
#include <string>
using namespace std;
namespace Controller
{
/// \brief Constructor
///
LoginController::LoginController()
{
    this-> fileIo = new FileIo();
    this-> currentPlayer = 0 ;
}

/// \brief Loads player if it exists else creates new user
///
/// \param username const string&
/// \return void
///
///
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
    this-> activePlayers.push_back(this-> currentPlayer);
}

/// \brief gets the list of players
///
/// \return vector<Player*>
///
///
vector<Player*> LoginController::getActivePlayers()
{
    return this-> activePlayers;
}

/// \brief loads all players into the list
///
/// \return void
///
///
void LoginController::loadAllPlayers()
{
    this-> activePlayers = this-> fileIo-> getPlayersList();
}

/// \brief gets the current player
///
/// \return Player*
///
///
Player* LoginController::getCurrentPlayer()
{
    return this-> currentPlayer;
}

/// \brief destructor
///
LoginController::~LoginController()
{
    delete this-> fileIo;
}
}
