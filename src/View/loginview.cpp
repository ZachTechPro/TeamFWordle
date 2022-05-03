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
    Fl_Box* greetingLabel = new Fl_Box(110,10,100,50,"Welcome. Please sign in with your username.");

    greetingLabel-> box(Fl_Boxtype::FL_NO_BOX);
    Fl_Box* newUserLabel = new Fl_Box(110,25,100,50,"If you're new just type your name!");

    newUserLabel-> box(Fl_Boxtype::FL_NO_BOX);
    this-> userNameInput = new Fl_Input(90,100,70,30, "username");
    this-> repeatButton = new Fl_Check_Button(180,140,130,30, "Repeat Letters?");
    Fl_Box* warningLabel = new Fl_Box(200,145,100,50,"Warning: Hard");

    warningLabel-> box(Fl_Boxtype::FL_NO_BOX);
    this->repeatButton->value(false);
    this-> setOKLocation(90, 130);
    this-> setCancelLocation(-100, -100);

    end();
}


/// \brief WIll handle a cancel event that is emitted by the cancel button
/// in this view
///
/// \return void
///
///
void LoginView::cancelHandler()
{
    exit(0);
}

/// \brief Will handle an ok event tht is emitted by the okay button
/// in this view; Will start the process to login / create the user
///
/// \return void
///
///
void LoginView::okHandler()
{
    this-> controller-> loadOrCreatePlayer(this-> userNameInput-> value());
    this-> hide();
}

/// \brief checkbox to toggle the allowance of repeated letters within a guess word
///
/// \return bool -> true if checked; false otherwise
///
///
bool LoginView::getCheckedRepeatLetters()
{
    return this->repeatButton->value();
}

/// \brief Once the player is loaded, this will allow other pieces of the system to access the player
/// that has been loaded into the application
///
/// \return Player* -- pointer to the current player
///
///
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
