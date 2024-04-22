#include "File.h"

bool File::isFileEmpty(){
    bool isFileEmpty = true;
    fstream file;
    file.open(getFileName().c_str(), ios::app);

    if (file.good() == true){
        file.seekg(0, ios::end);
        if (file.tellg() != 0)
            isFileEmpty = false;
    }

    file.close();
    return isFileEmpty;
}

string File::getFileName(){
    return FILE_NAME;
}
