#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s, char *longestSubstring) {
    int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int maxStart = 0; // To store the starting index of the longest substring

    int charIndex[128]; // Array to track the last seen position of each character
    for (int i = 0; i < 128; i++) {
        charIndex[i] = -1; // Initialize all elements of charIndex to -1 (means no character has been seen yet)
    }

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];

        // If the current character has already been seen and its last position is after or equal to 'start'
        if (charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1; // Move 'start' to just after the last occurrence of currentChar
        }

        charIndex[currentChar] = end; // Update the last seen position of currentChar

        int currentLength = end - start + 1; // Calculate the current length of the substring

        // Update maxLength and maxStart if a longer substring is found
        if (currentLength > maxLength) {
            maxLength = currentLength;
            maxStart = start; // Store the start position of the longest substring
        }
    }

    // Copy the longest substring into the provided longestSubstring array
    strncpy(longestSubstring, s + maxStart, maxLength);
    longestSubstring[maxLength] = '\0'; // Null-terminate the substring

    return maxLength;
}

int main() {
    char str[] = "abcabcbb"; // Example input string
    char longestSubstring[128]; // Array to store the longest substring

    // Pass both the string and the longestSubstring array to the function
    int result = lengthOfLongestSubstring(str, longestSubstring); 

    // Print the results
    printf("The length of the longest substring without repeating characters is: %d\n", result);
    printf("The longest substring without repeating characters is: %s\n", longestSubstring);

    return 0;
}

