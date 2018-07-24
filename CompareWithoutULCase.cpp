//
//  
//  CompareWithoutULCase
//
//  Created by foolsparadise on 2018/7/21.
//  Copyright © 2018 github.com/foolsparadise All rights reserved.
//

#include "CompareWithoutULCase.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

inline char NPT_Uppercase(char x) {
    return (x >= 'a' && x <= 'z') ? x&0xdf : x;
}
inline char NPT_Lowercase(char x) {
    return (x >= 'A' && x <= 'Z') ? x^32 : x;
}
int 
CompareN(const char* s1, const char *s2, int count, bool ignore_case)
{
    const char* me = s1;

    if (ignore_case) {
        for (unsigned int i=0; i<count; i++) {
            if (NPT_Uppercase(me[i]) != NPT_Uppercase(s2[i])) {
                return NPT_Uppercase(me[i]) - NPT_Uppercase(s2[i]);
            }
        }
        return 0;
    } else {
        for (unsigned int i=0; i<count; i++) {
            if (me[i] != s2[i]) {
                return (me[i] - s2[i]);
            }
        }
        return 0;
    }
}
int 
//CompareWithoutULCaseClass::
CompareWithoutULCase(char * str1, char * str2) 
{
	printf("%s %s\n", str1, str2);
    if(strlen(str1)!=strlen(str2)) 
    {
        printf("length not match!\n");
        return -1;
    }
	if(CompareN(str1,str2,strlen(str1),1) == 0) 
	{
		printf("match without case!\n");
        return 0;
	}
    printf("not match without case!\n");
	return -1;
}

/* 
//for test
int main(int argc , char** argv)
{
    if(argc!=3) {
        printf("Usage: xxx str1 str2\n");
        return 1;
    }  
    CompareWithoutULCase(argv[1],argv[2]);    
	
    return 0;
}
*/
