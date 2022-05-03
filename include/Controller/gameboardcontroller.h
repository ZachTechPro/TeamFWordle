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
    void updateGameLostStats(Player* player);
    void updateGameWonStats(Player* player, int numGuesses);
    bool checkForCompletedSolution(int* solutionFlags, int numCells);
    int* checkGuessAsCorrect(const string& userGuess);
    bool getRepeatLetters();
    void setRepeatLetters(bool repeat);
    GameBoardController();
    void loadWordsForPlay();
    virtual ~GameBoardController();

protected:

private:
    bool repeatLetters = false;
    GuessChecker* guessChecker;
    string chosenWord;
    FileIo* fileIo;
};
}
#endif // GAMEBOARDCONTROLLER_H
