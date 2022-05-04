/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath> // fabs()
using namespace std;
#define MAXSIZE 7
#define PRECISION 1e-6

/*To calculate the cross product of two 2D vectors
- input:
    vector1: double x1, double y1
    vector2: double x2, double y2
- output:
    cross product result
*/
double cross_product(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}

/*To convert x, y coordinates of vertexes to the side vectors
- input:
    double x_vertex[]: array that contains x coordinates of vertexes
    double y_vertex[]: array that contains y coordinates of vertexes
    double x_vector[]: array that contains x coordinates of side vectors
    double y_vector[]: array that contains y coordinates of side vectors
    int num: the quantity of the vertexes
*/
void vertex2vector(const double x_vertex[], const double y_vertex[], double x_vector[], double y_vector[], int num)
{
    for (int i = 0; i < num; ++i)
    {
        x_vector[i] = x_vertex[(i+1)%num] - x_vertex[i];
        y_vector[i] = y_vertex[(i+1)%num] - y_vertex[i];
    }
}

/*To judge if the polygon is convex.
- input:
    double x_coord[]: array that contains x coordinates of side vector.
    double y_coord[]: array that contains y coordinates of side vector.
    int num: the quantity of the vertexes
- output:
    if the polygon is convex, return 1;
    else return 0.
*/
int ifconvex(const double x_coord[], const double y_coord[], int num)
{
    int ifcounter = -1; // clockwise by default
    double curr;
    for (int i = 0; i < num; ++i)
    {
        curr = cross_product(x_coord[i], y_coord[i], x_coord[(i+1)%num], y_coord[(i+1)%num]);
        if (i)
        {
            if (curr * ifcounter < PRECISION) // not convex or 3 points at a line
                return 0;
        }
        else
            if (fabs(curr) < PRECISION) // 3 points at a line
                return 0;    
            else if (curr > 0)
                ifcounter = 1; // counterclockwise
    }
    return 1;
}

/*To get the area of a convex polygon
- input:
    double x_coord[]: array that contains x coordinates of side vector.
    double y_coord[]: array that contains y coordinates of side vector.
    int num: the quantity of the vertexes
- output:
    double area.
*/
double get_area(const double x_coord[], const double y_coord[], int num)
{
    double area = 0;
    double triangle_area = 0;
    double curr_x = x_coord[0];
    double curr_y = y_coord[0];
    for (int i = 1; i < num - 1; ++i)
    {
        // area = sum of area of num - 2 triangles
        triangle_area = cross_product(curr_x, curr_y, x_coord[i], y_coord[i]) / 2.0;
        area += triangle_area;
        curr_x += x_coord[i];
        curr_y += y_coord[i];
    }
    if (area < 0)
        area = -area; // clockwise
    return area;
}

int main()
{
    double x_vertex[MAXSIZE] = { 0 };
    double y_vertex[MAXSIZE] = { 0 };
    double x_vector[MAXSIZE] = { 0 };
    double y_vector[MAXSIZE] = { 0 };
    int num = 0;
    double x = 0, y = 0;
    while (1)
    {
        cout << "请输入多边形的顶点数量(4-7)" << endl;
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if(num >= 4 && num <= 7)
            break;
    }
    cout << "请按顺时针/逆时针方向输入" << num << "个顶点的x,y坐标：" << endl;
    for (int i = 0; i < num; ++i)
    {
        while (1)
        {
            cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
            cin >> x >> y;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(65536, '\n');
            }
            else
                break;
        }
        x_vertex[i] = x;
        y_vertex[i] = y;
    }
    vertex2vector(x_vertex, y_vertex, x_vector, y_vector, num);
    if (ifconvex(x_vector, y_vector, num))
        cout << "凸" << num << "边形的面积=" << get_area(x_vector, y_vector, num) << endl;
    else
        cout << "不是凸" << num << "边形" << endl;
    return 0;
}
