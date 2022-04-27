#include "loginview.h"
#include <FL/Fl.H>
#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include "gameboardwindow.h"
#include <iostream>
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
LoginView::LoginView(int width, int height, const char* title) : Fl_Window(width, height, title)
{
   this-> loginButton = new Fl_Button(90, 130, 70, 30, "Login");
   this-> loginButton-> callback(cbLogin, this);
   this-> userNameInput = new Fl_Input(90,100,70,30, "username");
}

/** \brief Destructor
 */
LoginView::~LoginView()
{
    delete this-> loginButton;
}

/**< private */
void LoginView::cbLogin(Fl_Widget* widget, void* data)
{
    LoginView* window = (LoginView*) data;
    window-> login();
}

/**< private */
void LoginView::login()
{
    if (this-> controller-> isValidLogin(this-> userNameInput-> value()))
    {
        this-> hide();
    }

}

}
