#include <string.h>
#include <stdlib.h>

#ifndef STRING_SIZE
#define STRING_SIZE 50
#endif

#ifndef STRING_CHUNK_SIZE
#define STRING_CHUNK_SIZE 10
#endif




int __co;



goto run;








run: typedef struct String {
    char *start;
    int size;
    int len;

} String;

String newStringStr(char *dest) {
    int len = strlen(dest);
    String str;
    
    int size = (len+1) <= STRING_SIZE ? STRING_SIZE : STRING_SIZE+(len+1-STRING_SIZE)%STRING_CHUNK_SIZE;

    str.start = malloc(sizeof(char)*size);
    strcpy(str.start, dest);

    str.len = len;

    return str;
}



#define newString(X) \
    _Generic((X), \
            char*: newStringStr(X))
