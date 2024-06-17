#include <stdio.h>
#include <math.h>
#include <graphics.h>
int no_of_vertices;

void translation(float transformation_matrix[3][3]);
void rotation(float transformation_matrix[3][3]);
void reflection(float transformation_matrix[3][3]);
void shearing(float transformation_matrix[3][3]);
void scaling(float transformation_matrix[3][3]);
void coordinate(int vertices[][3]);
void draw_figure(int vertices[][3]);
void mul_matrix(int matrix_A[][3], float matrix_B[][3]);
void translation(int vertices[][3], int Tx, int Ty);
void reflection_on_xaxis(int vertices[][3]);

int main()
{
    int gd = DETECT, gm, color;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    int opt;
    float transformation_matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    line(0, 240, 640, 240);
    line(320, 0, 320, 480);
    printf("Enter the no of vertices: ");
    scanf("%d", &no_of_vertices);
    int vertices[no_of_vertices][3];
    coordinate(vertices);
    draw_figure(vertices);
    printf("\nChoose the transformation operation:\n");
    printf("1-Translation\n2-Rotation\n3-Reflection\n4-Shearing\n5-Scaling");
    printf("\nEnter option: ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        translation(transformation_matrix);
        break;
    case 2:
        rotation(transformation_matrix);
        break;
    case 3:
        reflection(transformation_matrix);
        break;
    case 4:
        shearing(transformation_matrix);
        break;
    case 5:
        scaling(transformation_matrix);
        break;
    default:
        break;
    }
    mul_matrix(vertices, transformation_matrix);
    draw_figure(vertices);
    getch();
    closegraph();
    return 0;
}
void coordinate(int vertices[][3])
{
    int i;
    for (i = 0; i < no_of_vertices; i++)
    {
        printf("\nEnter the coordinate of vertex %d\n", i + 1);
        printf("X = ");
        scanf("%d", &vertices[i][0]);
        printf("Y = ");
        scanf("%d", &vertices[i][1]);
        vertices[i][2] = 1;
    }
}
void draw_figure(int vertices[][3])
{
    int i;
    reflection_on_xaxis(vertices);
    translation(vertices, 320, 240);
    for (i = 0; i < no_of_vertices - 1; i++)
    {
        line(vertices[i][0], vertices[i][1], vertices[i + 1][0], vertices[i + 1][1]);
    }
    line(vertices[no_of_vertices - 1][0], vertices[no_of_vertices - 1][1],
         vertices[0][0], vertices[0][1]);
    translation(vertices, -320, -240);
    reflection_on_xaxis(vertices);
}
void translation(float transformation_matrix[3][3])
{
    int Tx, Ty;
    printf("\nEnter the translation point:\nTx = ");
    scanf("%d", &Tx);
    printf("Ty = ");
    scanf("%d", &Ty);
    transformation_matrix[2][0] = Tx;
    transformation_matrix[2][1] = Ty;
}
void translation(int vertices[][3], int Tx, int Ty)
{
    float tra_matrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    tra_matrix[2][0] = Tx;
    tra_matrix[2][1] = Ty;
    mul_matrix(vertices, tra_matrix);
}
void rotation(float transformation_matrix[3][3])
{
    int angle;
    printf("\nEnter the angle of rotation : ");
    scanf("%d", &angle);
    double rad = (angle * 3.14159 / 180.0);
    transformation_matrix[0][0] = cos(rad);
    transformation_matrix[1][0] = -sin(rad);
    transformation_matrix[0][1] = sin(rad);
    transformation_matrix[1][1] = cos(rad);
}
void reflection(float transformation_matrix[3][3])
{
    int reflection_type;
    printf("\nChoose the type of reflection to perform:\n1-reflection about X-axis");
    printf("\n2-Reflection about Y-axis\n3-Reflection about line x=y\nEnter the type: ");
    scanf("%d", &reflection_type);
    switch (reflection_type)
    {
    case 1:
        transformation_matrix[1][1] = -1;
        break;
    case 2:
        transformation_matrix[0][0] = -1;
        break;
    case 3:
        transformation_matrix[0][0] = 0;
        transformation_matrix[1][0] = 1;
        transformation_matrix[0][1] = 1;
        transformation_matrix[1][1] = 0;
        break;
    default:
        break;
    }
}
void reflection_on_xaxis(int vertices[][3])
{
    float ref_matrix[3][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    mul_matrix(vertices, ref_matrix);
}
void shearing(float transformation_matrix[3][3])
{
    int Shx, Shy;
    printf("\nEnter the shearing point:\nShx = ");
    scanf("%d", &Shx);
    printf("Shy = ");
    scanf("%d", &Shy);
    transformation_matrix[1][0] = Shx;
    transformation_matrix[0][1] = Shy;
}
void scaling(float transformation_matrix[3][3])
{
    int Sx, Sy;
    printf("\nEnter the scaling point:\nSx = ");
    scanf("%d", &Sx);
    printf("Sy = ");
    scanf("%d", &Sy);
    transformation_matrix[0][0] = Sx;
    transformation_matrix[1][1] = Sy;
}
void mul_matrix(int matrix_A[][3], float matrix_B[][3])
{
    int temp_matrix[no_of_vertices][3];
    int i, j, k;
    for (i = 0; i < no_of_vertices; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp_matrix[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                temp_matrix[i][j] += int(round(matrix_A[i][k] * matrix_B[k][j]));
            }
        }
    }
    for (i = 0; i < no_of_vertices; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matrix_A[i][j] = temp_matrix[i][j];
        }
    }
}
