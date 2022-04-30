#include "loginview.h"
#include <FL/Fl.H>
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include "gameboardwindow.h"
#include <iostream>
#include "okcancelwindow.h"
using namespace std;
namespace view
{

/** \brief constructor
 *
 * \param width int -- the width of the window
 * \param height int -- the height of the window
 * \param title const char* -- the title of the window
 *
 */
LoginView::LoginView() : OKCancelWindow(330, 215, "Login")
{
    this-> controller-> loadAllPlayers();
    this-> player = 0;
    begin();
    Fl_Output* t = new Fl_Output(270, 30, 0, 0, "Enter your username\n If you do not have one, go ahead and make one here.");
    this-> userNameInput = new Fl_Input(90,100,70,30, "username");
    this-> setOKLocation(90, 130);
    this-> setCancelLocation(-100, -100);
    end();
}

void LoginView::cancelHandler()
{
    cout << "cancel" << endl;
}

void LoginView::okHandler()
{
    this-> controller-> loadOrCreatePlayer(this-> userNameInput-> value());
    this-> hide();
}

Player* LoginView::getPlayer()
{
    return this-> controller-> getCurrentPlayer();
}

/** \brief Destructor
 */
LoginView::~LoginView()
{
}

}
