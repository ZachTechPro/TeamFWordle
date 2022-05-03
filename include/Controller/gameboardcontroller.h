#ifndef GAMEBOARDCONTROLLER_H
#define GAMEBOARDCONTROLLER_H
#include "fileio.h"
#include <FL/Fl_Output.H>
#include "guesschecker.h"
using namespace IO;
using namespace Utils;
namespace Controller
{
class GameBoardController
{

public:
    bool isValidGuess(const string& userGuess);
    void updateGameLostStats(Player* player);
    void updateGameWonStats(Player* player, int numGuesses);
    bool checkForCompletedSolution(int* solutionFlags, int numCells);
    int* checkGuessAsCorrect(const string& userGuess);
    bool getRepeatLetters();
    void setRepeatLetters(bool repeat);
    GameBoardController();
    void loadWordsForPlay();
    virtual ~GameBoardController();
    string getChosenWord();

protected:

private:
    void updatePlayerAndSave(Player* player);
    bool repeatLetters = false;
    GuessChecker* guessChecker;
    string chosenWord;
    FileIo* fileIo;
};
}
#endif // GAMEBOARDCONTROLLER_H
