// Leetcode : First Unique Character in a String
// https://leetcode.com/explore/interview/card/apple/344/array-and-strings/2018/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    // Input can only be lowercase English Alphabet.
    char* input = (char*)malloc(sizeof(char) * 100) ;
    scanf("%s", input);

    // Calloc used to initialize everuthing to zero.
    // Since the size remains same, this is O(1) space.
    // ---
    // We are trying to mimic unordered map as the char read is the key 
    // and the corresponding value is either the frequency of the char in the string or index at which the current char is. 
    int* freq = (int*)calloc(26, sizeof(int));
    int* indx = (int*)calloc(26, sizeof(int));

    // O(n) time
    for (int i = 0; input[i] != '\0'; i++)
    {
        int loc = input[i] - 'a';
        freq[loc]++;
        indx[loc] = i;
    }

    // O(1) time, independent of input size.
    int min_indx = INT_MAX;
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] == 1)
        {
            min_indx = (min_indx > indx[i]) ? indx[i] : min_indx;
        }
    }
    
    min_indx = (min_indx == INT_MAX) ? -1 : min_indx;

    printf("%d\n", min_indx);

    free(input);
    free(freq);
    free(indx);
    return 0;
}