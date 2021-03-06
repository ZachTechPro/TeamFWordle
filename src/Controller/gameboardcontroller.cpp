#include "gameboardcontroller.h"
#include <iostream>
namespace Controller
{

/** \brief Constructor
 *
 */
GameBoardController::GameBoardController()
{
    this-> fileIo = new FileIo();
    this-> guessChecker = new GuessChecker();
}

/** \brief Will loads from the words list that are of length 5
 *
 */
void GameBoardController::loadWordsForPlay()
{
    if(this->repeatLetters)
    {
        this->chosenWord = this->fileIo->loadWords();
    }
    else
    {
        this->chosenWord = this-> fileIo->loadWordsNoDuplicateLetters();
    }
}

/// \brief Checks if the guess is the a usable word
///
/// \param userGuess const string&
/// \return bool
///
///
bool GameBoardController::isValidGuess(const string& userGuess)
{
    bool isValid = false;
    for (auto word : this-> fileIo-> getWords())
    {
        if (word.compare(userGuess) == 0)
        {
            isValid = true;
        }
    }

    return isValid;
}

/// \brief Checks if the guess is the correct word
///
/// \param userGuess const string&
/// \return int*
///
///
int* GameBoardController::checkGuessAsCorrect(const string& userGuess)
{
    return this-> guessChecker-> checkGuessAsCorrect(userGuess, chosenWord);
}

/// \brief Checks if all of the letters are correct, if not returns false
///
/// \param solutionFlags int*
/// \param numCells int
/// \return bool
///
///
bool GameBoardController::checkForCompletedSolution(int* solutionFlags, int numCells)
{
    int correctLetterCorrectSpotFlag = 3;
    int hasGuessedAll = true;
    for (int flagIndex = 0; flagIndex < numCells; flagIndex++)
    {
        if (solutionFlags[flagIndex] != correctLetterCorrectSpotFlag)
        {
            hasGuessedAll = false;
        }
    }
    return hasGuessedAll;
}

/// \brief returns if the letters are allowed to repeat
///
/// \return bool
///
///
bool GameBoardController::getRepeatLetters()
{
    return this->repeatLetters;
}
/// \brief sets if the letters are allowed to repeat
///
/// \param repeat bool
/// \return void
///
///
void GameBoardController::setRepeatLetters(bool repeat)
{
    this->repeatLetters = repeat;
}

/// \brief Updates the players stats to account for the loss taken
///
/// \param player Player*
/// \return void
///
///
void GameBoardController::updateGameLostStats(Player* player)
{
    player-> setIsOnWinStreak(false);
    player-> setTotalGamesPlayed(player-> getTotalGamesPlayed() + 1);
    this-> updatePlayerAndSave(player);
}

/// \brief Updates the players stats to account for the win
///
/// \param player Player*
/// \param numGuesses int
/// \return void
///
///
void GameBoardController::updateGameWonStats(Player* player, int numGuesses)
{
    player-> setIsOnWinStreak(true);
    const int singleGuess = 1;
    const int twoGuesses = 2;
    const int threeGuesses = 3;
    const int fourGuesses = 4;
    const int fiveGuesses = 5;
    const int sixGuesses = 6;
    switch(numGuesses)
    {
    case singleGuess:
        player-> setOneTryWins(player-> getOneTryWins() + 1);
        break;

    case twoGuesses:
        player -> setTwoTryWins(player-> getTwoTryWins() + 1);
        break;

    case threeGuesses:
        player -> setThreeTryWins(player-> getThreeTryWins() + 1);
        break;

    case fourGuesses:
        player -> setFourTryWins(player-> getFourTryWins() + 1);
        break;

    case fiveGuesses:
        player -> setFiveTryWins(player-> getFiveTryWins() + 1);
        break;

    case sixGuesses:
        player -> setSixTryWins(player-> getSixTryWins() + 1);
        break;
    }

    player-> setTotalGamesPlayed(player-> getTotalGamesPlayed() + 1);

    player-> updateWinPercentage();

    if (player-> getIsOnWinStreak())
    {
        player-> setcurrentWinStreak(player-> getCurrentWinStreak() + 1);
        if (player-> getCurrentWinStreak() > player-> getMaxWinStreak())
        {
            player-> setMaxWinStreak(player-> getCurrentWinStreak());
        }
    }

    this-> updatePlayerAndSave(player);
}

/// \brief Updates the player in the list of players, and then overwrites the csv
///
/// \param player Player*
/// \return void
///
///
void GameBoardController::updatePlayerAndSave(Player* player)
{
    vector<Player*> allPlayers = this-> fileIo-> getPlayersList();
    vector<Player*> updatedPlayersList;
    for (auto currPlayer : allPlayers)
    {
        if (currPlayer-> getUserName().compare(player-> getUserName()) != 0)
        {
            updatedPlayersList.push_back(currPlayer);
        }
    }

    updatedPlayersList.push_back(player);
    this-> fileIo-> SaveFile(&updatedPlayersList[0], updatedPlayersList.size());
}

/// \brief gets the chosen word of this round
///
/// \return string
///
///
string GameBoardController::getChosenWord()
{
    return this->chosenWord;
}

/** \brief Destructor
*
*/
GameBoardController::~GameBoardController()
{
    delete this-> fileIo;
    delete this-> guessChecker;
}
}
