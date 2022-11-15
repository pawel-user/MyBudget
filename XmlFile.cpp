#include "XmlFile.h"

string XmlFile::loadFilename()
{
    return FILENAME;
}

bool XmlFile::isFileEmpty() {
    CMarkup xml;
    bool fileExists = false;
    fileExists = xml.Load( loadFilename() );

    if (fileExists == true) {
        return false;
    } else {
        xml.Load( loadFilename() );
        CMarkup mResult( xml.GetResult() );
        if ( mResult.FindElem(MCD_T("read")) ) {
            int length = MCD_STRTOINT(mResult.GetAttrib(MCD_T("length")));
            if (length == 0) {
                return true;
            }
        }
    return false;
    }
}
