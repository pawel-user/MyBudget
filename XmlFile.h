#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XmlFile {
protected:
    const string FILENAME;
public:
    XmlFile(string fileName) : FILENAME(fileName){};
};

#endif // XMLFILE_H
