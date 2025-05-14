#include<bits/stdc++.h>
using namespace std;

bool naiveMatching(string& pattern, string& text) {
    int N = text.length();
    int M = pattern.length();

    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
        {
            if(text[i+j] != pattern[j]) break;
        }

        if(j == M) {
            cout << "Pattern found at index " << i << endl;
            return true;
        }
    }
    
    return false;
}



bool RabinKarp(string& pattern, string& text) {
    int M = pattern.size();
    int N = text.size();

    int i,j;
    int q = 101;
    int p = 0;
    int t = 0;

    int h = 1;
    int d = 256;

    for (int i = 0; i < M-1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < M; i++)
    {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (i = 0; i <= N-M; i++)
    {
        if(p==t) {
            for (j = 0; j < M; j++)
            {
                if(text[j+i] != pattern[j]) break;  
            }
            

            if(j==M) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if(i < N-M) {
            t = (d * (t - text[i] * h) + text[i+M]) % q;

            if(t < 0) {
                t = t + q;
            }
        }
    }  
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    if (!naiveMatching(pattern, text)) {
        cout << "Pattern not found" << endl;
    }
    
    return 0;
}