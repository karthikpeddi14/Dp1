#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;
        if (n == 0) {
          cout << 0 << endl;
          return 0;
        }

        int prev2 = 0;
        int prev = 1;
        int cur;
        for(int i=2 ; i<=n ; i++)
        {
                cur = prev2 + prev;
                prev2 = prev;
                prev = cur;
        }
        cout << prev << endl;
        return 0;
}
