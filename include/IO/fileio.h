#ifndef FILEIO_H
#define FILEIO_H
#include <string>

using namespace std;

namespace IO
{

class FileIo
{
    public:
        bool canFindUser(const string& userName);
        string loadWords();
        FileIo();
        virtual ~FileIo();

    protected:

    private:
        string readFileIntoString(const string& path);
};
}
#endif // FILEIO_H
