#include "player.h"

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

void Player::setOneTryWins(int newWinNumber)
{
    this->oneTry = newWinNumber;
}
void Player::setTwoTryWins(int newWinNumber)
{
    this->twoTry = newWinNumber;
}
void Player::setThreeTryWins(int newWinNumber)
{
    this->threeTry = newWinNumber;
}
void Player::setFourTryWins(int newWinNumber)
{
    this->fourTry = newWinNumber;
}
void Player::setFiveTryWins(int newWinNumber)
{
    this->fiveTry = newWinNumber;
}
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
