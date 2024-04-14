// 5. Midpoint Circle Algorithm

#include <iostream>
#include <graphics.h>
using namespace std;

void plotCirclePoints(int X, int Y, int x, int y) {
    putpixel(X + x, Y + y, WHITE);
    putpixel(X - x, Y + y, WHITE);
    putpixel(X + x, Y - y, WHITE);
    putpixel(X - x, Y - y, WHITE);
    putpixel(X + y, Y + x, WHITE);
    putpixel(X - y, Y + x, WHITE);
    putpixel(X + y, Y - x, WHITE);
    putpixel(X - y, Y - x, WHITE);
}
void MidpointCircle(int X1, int Y1, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    plotCirclePoints(X1, Y1, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        plotCirclePoints(X1, Y1, x, y);
    }
}
int main() {
    int x1, y1, r;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Enter the coordinates of the center: ";
    cin >> x1 >> y1;
    cout << "Enter the radius: ";
    cin >> r;

    MidpointCircle(x1, y1, r);
    getch();
    closegraph();
}
