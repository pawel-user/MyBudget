#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <string.h>

#include "Markup.h"

using namespace std;

class XmlFile {
protected:
    const string FILENAME;
public:
    XmlFile(string fileName) : FILENAME(fileName) {};
    bool isFileEmpty();

    string loadFilename();
};

#endif // XMLFILE_H
