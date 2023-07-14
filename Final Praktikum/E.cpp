#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct road
{
    int a,b,c;

    road(int desaA, int desaB, int danger){
        a = desaA;
        b = desaB;
        c = danger;
    }
};

int find(vector<int>& desa, int x) {
    if (desa[x] != x) {
        return find(desa, desa[x]);
    }
    return x;
}

bool compRoad(const road& jalana, const road& jalanb){
    return jalana.c < jalanb.c;
}

int main() {
    int n, m, a, b, c;
    vector<road> jalan;
    
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        jalan.push_back(road(a, b, c));
    }


    sort(jalan.begin(), jalan.end(), compRoad);


    vector<int> desa(n + 1);

    for (int i = 1; i <= n; i++)
    {
        desa[i] = i;
    }

    int dangermax = 0;
    int edgeidx = 0;

    for(int i=0; i<jalan.size(); i++)
    {
        int a = jalan[i].a;
        int b = jalan[i].b;
        int bhyjln = jalan[i].c;

        if(find(desa, a) != find(desa, b))
        {
            dangermax = max(dangermax, bhyjln);
            desa[find(desa, a)] = find(desa, b);
            edgeidx++;
        }

        if (edgeidx == n-1) 
        {
            break;
        }
    }

    cout << dangermax << endl;
}