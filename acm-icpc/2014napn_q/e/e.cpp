#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int N;
double Map[102][102];

double min(double a, double b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}


double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double solve(double mex, double mey, double endx, double endy, int nCannon, double cannonX[], double cannonY[])
{
    
    //MAP BUILDING
    N = nCannon;
    int i, j;
    double dis;
    Map[0][0] = 0.0;
    Map[N + 1][N + 1] = 0.0;
    Map[0][N + 1] = distance(mex, mey, endx, endy) / 5.0;
    Map[N + 1][0] = Map[0][N + 1];
    for (i = 1; i <= N; i++)
    {
        dis = distance(mex, mey, cannonX[i - 1], cannonY[i - 1]);
        Map[0][i] = dis / 5.0;
        Map[i][0] = min(dis / 5.0, 2.0 + fabs(dis - 50.0) / 5.0);
        
        
        dis = distance(endx, endy, cannonX[i - 1], cannonY[i - 1]);
        Map[N + 1][i] = dis / 5.0;
        Map[i][N + 1] = min(dis / 5.0, 2.0 + fabs(dis - 50.0) / 5.0);
        
        Map[i][i] = 0.0;
    }
    for(i = 1; i <= N; i ++)
    {
        for(j = 1; j <= N; j ++)
        {
            dis = distance(cannonX[i - 1], cannonY[i - 1], cannonX[j - 1], cannonY[j - 1]);
            Map[i][j] = min(dis / 5.0, 2.0 + fabs(dis - 50.0) / 5.0);
        }
    }
    
    //SPFA
    double d[N+2];
    d[0] = 0.0;
    for (i = 1; i <= N + 1; i ++)
    {
        d[i] = -1.0;
    }
    int q[N + 2];
    int qhead = 0;
    int qtail = 1;
    q[0] = 0;
    int u, v;
    bool has;
    while(qhead != qtail)
    {
        u = q[qhead];
        qhead += 1;
        qhead %= (N + 2);
        for(v = 0; v <= N + 1; v++)
        {
            if((d[v] < 0.0) || ((d[u] + Map[u][v] + 0.00001) < d[v]))
            {
                d[v] = d[u] + Map[u][v];
                has = false;
                for(i = qhead; i != qtail;)
                {
                    if(q[i] == v)
                    {
                        has = true;
                        break;
                    }
                    i++;
                    i %= (N + 2);
                }
                if(!has)
                {
                    q[qtail] = v;
                    qtail += 1;
                    qtail %= (N + 2);
                }
            }
        }
    }
    return d[N + 1];
}

int main()
{
    int i;
    double mex;// = 25.0;
    double mey;// = 100.0;
    cin>>mex>>mey;
    double endx;// = 190.0;
    double endy;// = 57.5;
    cin>>endx>>endy;
    int nCannon;// = 4;
    cin>>nCannon;
    double x[100],y[100];
    for (i=0;i<nCannon;++i) {
        cin>>x[i]>>y[i];
    }
    /*x[0] = 125.0;
    x[1] = 75.0;
    x[2] = 45.0;
    x[3] = 185.0;
    y[0] = 67.5;
    y[1] = 125.0;
    y[2] = 72.5;
    y[3] = 102.5;*/
    double result;
    result = solve(mex, mey, endx, endy, nCannon, x, y);
    printf("%.6f\n", result);
    return 0;
}

