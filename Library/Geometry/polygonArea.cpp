#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265359;

/*
 *  polygonArea = n * triangleArea;
 *  triangleArea = a * h / 2;
 *  t = 360 / (2 * n);
 *  tan t = (a/2) / h;
 *  h = (a/2) / tan t;
 *  triangleArea = a * a / (4 * tan t);
 *  polygonArea = n * a * a / (4 * tan t);
 *
 */

double polygonArea(const int &n, const double &a) {
    if (a < 0 && n < 0)
        return -1;
    return (a * a * n) / (4 * tan(PI / n));
}