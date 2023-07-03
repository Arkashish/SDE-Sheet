#include <bits/stdc++.h>
using namespace std;

//VIMP code do revise
vector<int> stringMatch(string text, string pattern)
{
    // Write your code here.
    vector<int> res;

    int d = 256; // No of characters in input
    int q = 101; // Prime number to perform mod operation
    int M = pattern.length();
    int N = text.length();

    if (M > N)
    {
        return res;
    }

    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
        // Check the hash values of current window of text and pattern
        // If the hash values match, then only check for characters one by one
        if (p == t)
        {
            // Check for characters one by one
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            // If p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
            {
                res.push_back(i + 1);
            }
        }

        // Calculate hash value for the next window of text
        // Remove leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            // We might get negative values of t, converting it to positive
            if (t < 0)
            {
                t = t + q;
            }
        }
    }

    return res;
}
