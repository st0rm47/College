#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void translation(int x1, int y1, int x2, int y2, int tx, int ty) {
    setcolor(3);
    rectangle(x1, y1, x2, y2);
    setcolor(13);
    rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
    getch();
}
void rotation(int x1, int y1, int x2, int y2, double angle) {
    setcolor(3);
    rectangle(x1, y1, x2, y2);
    angle = (angle * 3.14) / 180;
    long xr = x1 + ((x2 - x1) * cos(angle) - (y2 - y1) * sin(angle));
    long yr = y1 + ((x2 - x1) * sin(angle) + (y2 - y1) * cos(angle));
    setcolor(13);
    rectangle(x1, y1, xr, yr);
    getch();
}
void scaling(int x1, int y1, int x2, int y2, int x, int y) {
    setcolor(3);
    rectangle(x1, y1, x2, y2);
    setcolor(13);
    rectangle(x1 * x, y1 * y, x2 * x, y2 * y);
    getch();
}
void reflection(int x1, int y1, int x2, int y2, int x3, int y3) {
    setcolor(3);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    setcolor(13);
    line(x1, -y1 + 500, x2, -y2 + 500);
    line(x1, -y1 + 500, x3, -y3 + 500);
    line(x2, -y2 + 500, x3, -y3 + 500);
    getch();
}
void shearing(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int shx) {
    setcolor(3);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x3, y3, x4, y4);
    line(x2, y2, x4, y4);
    x1 = x1 + shx * y1;
    x2 = x2 + shx * y2;
    x3 = x3 + shx * y3;
    x4 = x4 + shx * y4;
    setcolor(13);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x3, y3, x4, y4);
    line(x2, y2, x4, y4);
    getch();
}
int main() {
    int gd = DETECT, gm;
    int s, x, y, x1, y1, x2, y2, x3, y3, x4, y4, tx, ty, shx;
    double angle;
    initgraph(&gd, &gm, NULL);

    setcolor(WHITE);
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());

    cout << "Enter the choice of transformation:\n";
    cout << "1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing\n";
    cout << "\nSelection: ";
    cin >> s;

    switch (s) {
        case 1:
            cout << "Enter coordinates: ";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "Enter translation point: ";
            cin >> tx >> ty;
            translation(x1, y1, x2, y2, tx, ty);
            break;
        case 2:
            cout << "Enter coordinates: ";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "Enter Angle of rotation: ";
            cin >> angle;
            rotation(x1, y1, x2, y2, angle);
            break;
        case 3:
            cout << "Enter coordinates: ";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "Enter the scaling point: ";
            cin >> x >> y;
            scaling(x1, y1, x2, y2, x, y);
            break;
        case 4:
            cout << "Enter coordinates: ";
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            reflection(x1, y1, x2, y2, x3, y3);
            break;
        case 5:
            cout << "Enter coordinates: ";
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            cout << "Enter the shearing point: ";
            cin >> shx;
            shearing(x1, y1, x2, y2, x3, y3, x4, y4, shx);
            break;
        default:
            cout << "Invalid Selection\n";
            break;
    }
    closegraph();
}
