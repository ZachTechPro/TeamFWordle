#ifndef GAMEBOARDCONTROLLER_H
#define GAMEBOARDCONTROLLER_H
#include "fileio.h"
#include "guesschecker.h"
using namespace IO;
using namespace Utils;
namespace Controller
{
class GameBoardController
{
    public:
        int* checkGuessAsCorrect(const string& userGuess);
        GameBoardController();
        void loadWordsForPlay();
        virtual ~GameBoardController();

    protected:

    private:
        GuessChecker* guessChecker;
        FileIo* fileIo;
};
}
#endif // GAMEBOARDCONTROLLER_H
