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
        bool checkForCompletedSolution(int* solutionFlags, int numCells);
        int* checkGuessAsCorrect(const string& userGuess);
        GameBoardController();
        void loadWordsForPlay();
        virtual ~GameBoardController();

    protected:

    private:
        GuessChecker* guessChecker;
        string chosenWord;
        FileIo* fileIo;
};
}
#endif // GAMEBOARDCONTROLLER_H
