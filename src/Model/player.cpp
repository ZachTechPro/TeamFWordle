#include "player.h"
#include <iostream>
using namespace std;
namespace model
{


/** \brief constructor
 */
Player::Player()
{
    this-> userName = "";
    this-> winPercentage = 0.0;
    this-> totalGamesPlayed = 0;
    this-> currentWinStreak = 0;
    this-> maxWinStreak = 0;
}
Player::Player(const string& name, int totalGamesPlayed, double winPercentage, int currentWinStreak, int maxWinStreak, int winDistribution[6])
{
    this->userName = name;
    this->totalGamesPlayed = totalGamesPlayed;
    this->winPercentage = winPercentage;
    this->currentWinStreak = currentWinStreak;
    this->maxWinStreak = maxWinStreak;
    this->oneTry = winDistribution[0];
    this->twoTry = winDistribution[1];
    this->threeTry = winDistribution[2];
    this->fourTry = winDistribution[3];
    this->fiveTry = winDistribution[4];
    this->sixTry = winDistribution[5];
}


/** \brief set the user's name
 *
 * \param userName const string& -- the username
 * \return void
 *
 */
void Player::setUserName(const string& userName)
{
    this-> userName = userName;
}

/** \brief sets the user's total games played
 *
 * \param totalGames int -- the total games played
 * \return void
 *
 */
void Player::setTotalGamesPlayed(int totalGames)
{
    this-> totalGamesPlayed = totalGames;
}


/** \brief sets the user's win percentage
 *
 * \param winPercentage double -- the win percentage
 * \return void
 *
 */
void Player::setWinPercentage(double winPercentage)
{
    this-> winPercentage = winPercentage;
}


/** \brief sets the current win streak
 *
 * \param currWinStreak int -- the win streak
 * \return void
 *
 */
void Player::setcurrentWinStreak(int currWinStreak)
{
    this-> currentWinStreak = currWinStreak;
}


/** \brief sets the max win streak
 *
 * \param winStreak int -- the max win streak
 * \return void
 *
 */
void Player::setMaxWinStreak(int winStreak)
{
    this-> maxWinStreak = winStreak;
}

/** \brief gets the win percentage
 *
 * \return double -- the win percentage
 *
 */
double Player::getWinPercentage()
{
    return this-> winPercentage;
}

/** \brief gets the username
 *
 * \return string -- the username
 *
 */
string Player::getUserName()
{
    return this-> userName;
}


/** \brief gets the total number of games played
 *
 * \return int -- total games played
 *
 */
int Player::getTotalGamesPlayed()
{
    return this-> totalGamesPlayed;
}


/** \brief gets the current win streak
 *
 * \return int -- the current win streak
 *
 */
int Player::getCurrentWinStreak()
{
    return this-> currentWinStreak;
}

/** \brief gets the max win streak
 *
 * \return int -- the max win streak
 *
 */
int Player::getMaxWinStreak()
{
    return this-> maxWinStreak;
}
/** \brief gets the one try wins
 *
 * \return int -- the one try wins
 *
 */
int Player::getOneTryWins()
{
    return this-> oneTry;
}
/** \brief gets the two try wins
 *
 * \return int -- the two try wins
 *
 */
int Player::getTwoTryWins()
{
    return this-> twoTry;
}
/** \brief gets the three try wins
 *
 * \return int -- the three try wins
 *
 */
int Player::getThreeTryWins()
{
    return this-> threeTry;
}
/** \brief gets the four try wins
 *
 * \return int -- the four try wins
 *
 */
int Player::getFourTryWins()
{
    return this-> fourTry;
}
/** \brief gets the five try wins
 *
 * \return int -- the five try wins
 *
 */
int Player::getFiveTryWins()
{
    return this-> fiveTry;
}
/** \brief gets the six try wins
 *
 * \return int -- the six try wins
 *
 */
int Player::getSixTryWins()
{
    return this-> sixTry;
}

/** \brief sets the one try wins
 *
 * \param newWinNumber int -- the one try wins
 * \return void
 *
 */
void Player::setOneTryWins(int newWinNumber)
{
    this->oneTry = newWinNumber;
}

/** \brief sets the two try wins
 *
 * \param newWinNumber int -- the two try wins
 * \return void
 *
 */
void Player::setTwoTryWins(int newWinNumber)
{
    this->twoTry = newWinNumber;
}

/** \brief sets the three try wins
 *
 * \param newWinNumber int -- the three try wins
 * \return void
 *
 */
void Player::setThreeTryWins(int newWinNumber)
{
    this->threeTry = newWinNumber;
}


/** \brief sets the four try wins
 *
 * \param newWinNumber int -- the four try wins
 * \return void
 *
 */
void Player::setFourTryWins(int newWinNumber)
{
    this->fourTry = newWinNumber;
}

/** \brief sets the five try wins
 *
 * \param newWinNumber int -- the five try wins
 * \return void
 *
 */
void Player::setFiveTryWins(int newWinNumber)
{
    this->fiveTry = newWinNumber;
}

/** \brief sets the six try wins
 *
 * \param newWinNumber int -- the six try wins
 * \return void
 *
 */
void Player::setSixTryWins(int newWinNumber)
{
    this->sixTry = newWinNumber;
}





/** \brief destructor
 */
Player::~Player()
{
}
}
