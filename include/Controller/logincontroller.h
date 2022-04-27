#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <string>
#include "fileio.h"
using namespace IO;
using namespace std;
namespace Controller
{
class LoginController
{
    public:
        bool isValidLogin(const string& username);
        LoginController();
        virtual ~LoginController();

    protected:

    private:
        FileIo* fileIo;
};
}
#endif // LOGINCONTROLLER_H
