//UTILITIES.cpp

#include "utilities.h"

#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#endif

#include <unistd.h>
#include <stdio.h>

//Returns the content of a file passed in path
string pathToContent(string path){
    
    QFile file(path.c_str());
    string Content;
    
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //        printf("impossible to open content\n");
        Content = "";
        //        return Content;
    }
    while (!file.atEnd()) {
        //        printf("Content read\n");
        QByteArray line = file.readLine();
        Content += line.data();
    }
    
    //    printf("CONTENT = %s\n", Content.c_str());
    return Content;
}

//Verify if the word is a number
bool isStringInt(const char* word){
    
    bool returning = true;
    
    for(size_t i=0; i<strlen(word); i++){
        if(!isdigit(word[i])){
            returning = false;
            break;
        }
    }
    return returning;
}

long lopt(char *argv[], const char *name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

const char* loptions(char *argv[], const char *name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

int lopt_Spe(int i, char *argv[], const char *name, char* path)
{
//	int	i;
//	for (i = 0; argv[i]; i++){
        if (!strcmp(argv[i], name)){
            strcpy(path, argv[i+1]);
        
            if (argv[i+2] && !strcmp(argv[i+2], "--n"))
                return atoi(argv[i+3]);
            else
                return 1;
        }
//    }	
    
    return 0;
}

