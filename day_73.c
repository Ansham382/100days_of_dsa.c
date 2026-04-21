/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int count[26] = {0};  // For lowercase letters

    // Taking input
    printf("Enter a string: ");
    scanf("%s", str);

    // Count frequency of each character
    for(int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }

    // Find first non-repeating character
    for(int i = 0; str[i] != '\0'; i++) {
        if(count[str[i] - 'a'] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            return 0;
        }
    }

    // If all characters repeat
    printf("$\n");

    return 0;
}
