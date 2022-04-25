#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "gameboardwindow.h"
using namespace view;
int main (int argc, char ** argv)
{

  GameBoardWindow gameWindow(540, 375, "Team F Wordle");
  gameWindow.show();

  int exitCode = Fl::run();
  return(exitCode);
}
