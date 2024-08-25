#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

void floydWarshall(vector<vector<int>> &arr, int n) {
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (arr[i][j] > arr[i][k] + arr[k][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<vector<int>> arr;

    cin>>n;
    cin>>m;
    for (int i=0;i<n;i++)
    {
        vector<int> line;
        for (int j=0;j<n;j++)
        {
            if (i==j)
                line.push_back(0);
            else
                line.push_back(INF);
        }
        arr.push_back(line);
    }
    for (int i=0;i<m;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        if (arr[x-1][y-1] > z)
            arr[x-1][y-1] = z;
    }
    floydWarshall(arr, n);
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j] != INF)
                cout<<arr[i][j];
            else
                cout<<0;
            if(j != n-1)
                cout<<" ";
            else
                cout<<"\n";
        }
    }
}
