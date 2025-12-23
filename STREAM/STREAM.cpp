#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

class Stream
{
protected:
    std::string _path;
public:
    Stream(std::string &_path)
    {
        this->_path = _path;
    }
    virtual int OpenFd() = 0;
};

class inStream : public Stream
{
private:
    std::istream& in_Stream;
    int Fd;

public:
    inStream(std::string &_path, std::istream& in_Stream) : in_Stream{in_Stream} ,Stream(_path) 
    {
    }
    int OpenFd() 
    {
        Fd = open(_path.c_str(), O_WRONLY | O_CREAT);
        return Fd;
    }

    std::istream &operator >>(std::string& inputString)
    {
        std::cout << "please Write the String \n";
        in_Stream >> inputString;
        
    }


};
// open(_path.c_str(), O_RDWR | O_CREAT);