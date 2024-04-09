// 3. BLA algorithm for positive slope

#include <iostream>
#include <graphics.h>
using namespace std;

void BLA(int X1, int Y1, int X2, int Y2){
    int x = X1, y = Y1;
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    putpixel(x,y,WHITE);
    int p = (2 * dy - dx);
    
    while (x <= X2){
        if (p < 0){
            x++;
            p = p + 2 * dy;
        }
        else{
            x++;
            y++;
            p = p + (2 * dy) - (2 * dx);
        }
        putpixel(x,y,WHITE);
    }
}
int main(){
    int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "Enter the coordinates of the first point: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point: ";
    cin >> x2 >> y2;

    BLA(x1, y1, x2, y2);
    getch();
    closegraph();
}
