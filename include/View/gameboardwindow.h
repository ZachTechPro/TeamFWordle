#ifndef GAMEBOARDWINDOW_H
#define GAMEBOARDWINDOW_H
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>

namespace view
{

class GameBoardWindow : public Fl_Window
{

    private:
        Fl_Button* submitGuessButton;

    public:
        static void cbSubmitGuess(Fl_Widget* widget, void* data);
        void submitGuess();
        GameBoardWindow(int width, int height, const char* title);
        virtual ~GameBoardWindow();


};
}

#endif // GAMEBOARDWINDOW_H
