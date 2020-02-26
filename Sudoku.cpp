#include <iostream>
using namespace std;

//global variables
bool sign = false;
int num[9][9];

//functions
void Input();
void Output();
bool Check(int n, int key);
int DFS(int n);
 

int main()
{
    Input();
    DFS(0);
    Output();
    return 0;
}
 
void Input()
{
    char temp[9][9];                             //set a temporary array
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            cin >> temp[i][j];
            num[i][j] = temp[i][j] - '0';        //make the temp array into an [int type] array
        }
    }
}
 
void Output()
{
    cout << endl;
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
            cout << num[i][j] << " ";
        cout << endl;
    }
}
 
bool Check(int n, int key)
{
    for (int i=0; i<9; i++)
    {
        int j = n / 9;                //calculate the row number
        if (num[j][i] == key)         //check if there is a repetitive number in the same row
			return false;
    }
    
    for (int i=0; i<9; i++)       
    {
        int j = n % 9;                //calculate the column number
        if (num[i][j] == key)         //check if there is a repetitive number in the same column
			return false;      
    }
    
    int x = n/9/3*3;                 //calculate the first row number of a 3*3 square
    int y = n%9/3*3;                 //calculate the first column number of a 3*3 square
    for (int i=x; i<x+3; i++)
    {
        for (int j=y; j<y+3; j++)
            if (num[i][j] == key)    //check if a 3*3 square has a repetitive number
				return false;
    }
    
	return true;
}

int DFS(int n)
{
    if (n > 80)                     //if all filled in
    {
        sign = true;
        return 0;                   //end of function
    }
    if (num[n/9][n%9] != 0)         //if the blank has been filled in
        DFS(n+1);                   //go to the next blank
    else
    {
        for (int i=1; i<=9; i++)
        {
            if (Check(n, i) == true)
            {
                num[n/9][n%9] = i;   //if no repetitive number
                DFS(n+1);            //go to the next blank
                
				if (sign == true)    //if finished
					return 0;        //end of function
                
				num[n/9][n%9] = 0;   //if something wrong while iteration, remove the number
            }
        }
    }
}
