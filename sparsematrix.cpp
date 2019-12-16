#include <iostream>

using namespace std;

struct Element
{
    int row;
    int col;
    int val;
};


void transpose(Element E[], int size, int rows, int cols)
{
    int temp=0;
    struct Element temp1;
    for(int i=0;i<size;i++)
    {

        temp = E[i].col;
        E[i].col = E[i].row;
        E[i].row = temp;
    }
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(E[i].row>E[j].row)
            {
                temp1 = E[i];
                E[i] = E[j];
                E[j] = temp1;
            }
            else if (E[i].row==E[j].row)
            {

                if(E[i].col>E[j].col)
                {
                    temp1 = E[i];
                    E[i] = E[j];
                    E[j] = temp1;
                }
            }
        }
    }
 //   for(int i=0;i<size;i++)
   // {
     //   cout << E[i].val << " col" << E[i].col << " row" << E[i].row << " ";
    //}
    //cout << endl;

    int k=0;
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
        {
            if(E[k].col == j && E[k].row== i)
            {
                cout << E[k].val << " ";
                k++;
            } else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}


int main()
{
    int numofrow, numofcol;
    cin >> numofrow >> numofcol;
    Element elements[10000];
    int i=0;
    int currow, curcol;
    for(currow=0;currow<numofrow;currow++)
    {
        for(curcol=0;curcol<numofcol;curcol++)
        {
            int curnum=0;
            cin >> curnum;
            if(curnum!=0)
            {
                elements[i].row=currow;
                elements[i].col=curcol;
                elements[i].val=curnum;
                i++;
            }
        }
    }

    transpose(elements, i, numofrow, numofcol);



return 0;
}
