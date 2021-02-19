/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void sort(int x[], int dem)
{
    int temp;
    for (int i = 0; i < dem; i++)
        for (int j = i + 1; j < dem; j++)
            if (x[i] >= x[j])
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
}

int main()
{
    int n, a[10000], b[10000], c[10000], dem_chan = 0, dem_le = 0;
    cin >> n;
    inputArray(a, n);

    int j = 0;
    for (int i = 0; i < n; i++) // tách mảng chẵn
    {
        if (a[i] % 2 == 0)
            {b[j] = a[i]; j++; dem_chan++;}
    }
    
    j = 0;
    for (int i = 0; i < n; i++) // tách mảng lẻ
    {
        if (a[i] % 2 != 0)
            {c[j] = a[i]; j++; dem_le++;}
    }
    sort(b, dem_chan); sort(c, dem_le); // sắp xếp tăng dần trog mảng
    
    for (int i = 0; i < n; i++) // nhập lại vào mảng a
    {
        a[i] = b[i];
        if (i >= dem_chan) a[i] = c[i - dem_chan];
    }

    for (int i = 0; i < n; i++) cout << a[i] << endl;

    return 0;
}

