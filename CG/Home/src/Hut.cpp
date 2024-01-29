#include <graphics.h>
#include <sstream> // Add the missing include statement

int main(){
    int gd=DETECT, gm;
    initgraph(&gd, &gm, NULL);
    circle(100, 100, 50);
    rectangle(50, 150, 150, 250);
    closegraph();
    return 0;
}