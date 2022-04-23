#ifndef GAMEBOARDCONTROLLER_H
#define GAMEBOARDCONTROLLER_H
#include "fileio.h"
using namespace IO;
namespace Controller
{
class GameBoardController
{
    public:
        GameBoardController();
        void loadWordsForPlay();
        virtual ~GameBoardController();

    protected:

    private:
        FileIo* fileIo;
};
}
#endif // GAMEBOARDCONTROLLER_H
