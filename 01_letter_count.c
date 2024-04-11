#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count = 0;

    printf("Enter a string: ");
    scanf( "%s", str);

    for(int i = 0; str[i] != '\0'; ++i) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ') {
            ++count;
        }
    }

    printf("Number of letters: %d", count);

    return 0;
}

/*Observations
This program will accuratly count the number of letters in a given sting though if there is space between tw0o words it would not count it*/

  

