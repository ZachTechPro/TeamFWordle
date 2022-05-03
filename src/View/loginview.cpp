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
    Fl_Box* greetingLabel = new Fl_Box(110,50,100,50,"Welcome. Please sign in with your username.");

    greetingLabel-> box(Fl_Boxtype::FL_NO_BOX);
    this-> userNameInput = new Fl_Input(90,100,70,30, "username");
    this-> repeatButton = new Fl_Check_Button(180,100,130,30, "Repeat Letters?");
    Fl_Box* warningLabel = new Fl_Box(200,115,100,50,"Warning: Hard");

    warningLabel-> box(Fl_Boxtype::FL_NO_BOX);
    this->repeatButton->value(false);
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
bool LoginView::getCheckedRepeatLetters()
{
    return this->repeatButton->value();
}
Player* LoginView::getPlayer()
{
    cout<<to_string(this->repeatButton->value());
    return this->controller->getCurrentPlayer();

}



/** \brief Destructor
 */
LoginView::~LoginView()
{
}

}
