#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int NV = 101;
const int inf = 0x7f7f7f7f;
 
int n, m, a, b, w, gra[NV][NV];
bool mark[NV];
//weightȨֵ��pre��¼�ߵ�ǰһ����
int weight[NV], pre[NV];
 
int prim (int src) {
    int  id;
    int ans = 0;
    memset(mark,false,sizeof(mark));
    for (int i = 1; i <= n; i++) {
        weight[i] = gra[src][i];
        pre[i] = src;
    }
    mark[src] = true;
    //n���ڵ�������Ҫn - 1���߹�����С������
    for (int i = 1; i < n; i++) {
        id = -1;
        for (int j = 1; j <= n; j++) {
            if (mark[j] ) continue;
            ///Ȩֵ��С�Ҳ�����������
            if (id == -1 || weight[j] < weight[id]) {
                id = j;
            }
        }
        if (gra[ pre[id] ][ id ] == inf) return -1;
        ans += gra[ pre[id] ][ id ];
        mark[id] = true;
        //���µ�ǰ�ڵ㵽�����ڵ��Ȩֵ�� ����Ȩֵ��Ϣ
        for (int j = 1; j <= n; j++) {
            if (mark[j]) continue;
            if (weight[j] > gra[id][j]) {
                weight[j] = gra[id][j];
                pre[j] = id;
            }//if
        }
    }//for
    return ans;
}
 
int main() {
    while(~scanf("%d", &n), n) {
        for (int i = 1; i <= n; i++) {
            gra[i][i] = 0;
            for (int j = i + 1; j <= n; j++) {
                gra[i][j] = inf;
            }
        }//for
        m = n * (n - 1) / 2;
        while (m--) {
            scanf("%d%d%d", &a, &b, &w);
            gra[a][b] = gra[b][a] = w;
        }
        printf("%d\n",prim(1));
    }
    return 0;
}