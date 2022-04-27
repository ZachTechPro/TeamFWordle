#include "logincontroller.h"
#include <iostream>
#include <string>
using namespace std;
namespace Controller
{
LoginController::LoginController()
{
     this-> fileIo = new FileIo();
}

bool LoginController::isValidLogin(const string& username)
{
    return this-> fileIo-> canFindUser(username);
}

LoginController::~LoginController()
{
    delete this-> fileIo;
}
}
