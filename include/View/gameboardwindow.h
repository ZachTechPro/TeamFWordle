#ifndef GAMEBOARDWINDOW_H
#define GAMEBOARDWINDOW_H
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Table.H>
#include <vector>
#include "gameboardcontroller.h"
using namespace Controller;
using namespace std;

namespace view
{

class GameBoardWindow : public Fl_Window
{

    private:
        Fl_Button* submitGuessButton;
        Fl_Input* wordGrid[30];
      //  Fl_Input* guessWordInput1;
       // Fl_Input* guessWordInput2;
      //  Fl_Input* guessWordInput3;
      //  Fl_Input* guessWordInput4;
     //   Fl_Input* guessWordInput5;
        GameBoardController* gbController;
        void performFirstTimeSetup();
        void highLightLetterCell(Fl_Input* inputCell, int positionFlag);

    public:
        static void cbSubmitGuess(Fl_Widget* widget, void* data);
        void submitGuess();
        GameBoardWindow(int width, int height, const char* title);
        virtual ~GameBoardWindow();


};
}

#endif // GAMEBOARDWINDOW_H
