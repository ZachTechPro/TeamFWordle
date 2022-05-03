#ifndef GAMEBOARDWINDOW_H
#define GAMEBOARDWINDOW_H
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Table.H>
#include <Fl/Fl_Box.H>
#include <vector>
#include "gameboardcontroller.h"
using namespace Controller;
using namespace std;

namespace view
{

class GameBoardWindow : public Fl_Window
{

private:
    void resetKeyBoard();
    void resetBoard();
    int roundCount;
    bool replay = false;
    void checkForCompletedSolution(int* solutionFlags, int numCells);
    void showStatsPage();
    bool hasGuessedCompletedWord;
    Fl_Box* usernameLabel;
    Player* player;
    Fl_Button* submitGuessButton;
    Fl_Input* wordGrid[30];
    Fl_Button* keyboardGrid[27];
    Fl_Box* wordGuessLabel;
    void updateKeyboard();
    void updateColorAndDisable(Fl_Input* inputCell);
    GameBoardController* gbController;
    int rowNumber;
    void handleLetter(const string& letter);
    void buildWordleGrid();
    void buildKeyboard();
    void performFirstTimeSetup();
    void highLightLetterCell(Fl_Input* inputCell, int positionFlag);

public:
    void login();
    static void cbHandleLetter(Fl_Widget* widget, void* data);
    static void cbSubmitGuess(Fl_Widget* widget, void* data);
    bool isWordValid(const string& userGuess);
    void submitGuess();
    GameBoardWindow(int width, int height, const char* title);
    virtual ~GameBoardWindow();


};
}

#endif // GAMEBOARDWINDOW_H
