#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
        char *source = "Alice Kaau Maingi";
        char *str = malloc(sizeof(char) * strlen(source));
        char *delim = " ";

        char *string = strtok(str, delim);

        while (string)
        {
                printf("%s\n", string);
                string = strtok(NULL, delim);
        }
        return (0);
}
