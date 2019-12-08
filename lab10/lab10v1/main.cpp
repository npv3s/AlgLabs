#include <iostream>
#include <cstring>

int main() {
    char str1[10] = "abc";
    char str2[] = "dfg";

    char tmp[10] = "abc";
    printf("%s\n", strcat(tmp, str2));
    //tmp[10] = {'\0'};

    strcpy(tmp, "abc");
    printf("%s\n", strncat(tmp, str2, 2));
    printf("%s\n", strchr(str1, 'b'));
    printf("%d\n", strcmp(str1, str2));
    //printf("%d\n", strcmpi(str1, str2));

    tmp[10] = {'\0'};
     strcpy(tmp, str1);
     printf("%s\n", tmp);
     tmp[10] = {'\0'};
    strncpy(tmp, "1234", 3);
    printf("%s\n", tmp);
    printf("%zu\n", strlen(str1));
    //strlwr(s);
    //strset(str, 'x');
    //strrev(s);
    //strstr(s1,s2);
    //strupr(s);
    //strtok(s1,s2);
    return 0;
}