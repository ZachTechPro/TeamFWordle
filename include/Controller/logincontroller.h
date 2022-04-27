#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <string>
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
};
}
#endif // LOGINCONTROLLER_H
