#include<bits/stdc++.h>
using namespace std;

const int N=1000;

int A[N][N];

void mergeRow(int low_row, int row, int low_col, int col, int mid_row, int mid_col)
{
    for(int z=low_row; z<=row; z++)
    {
        int arr[N], b=low_col, c=mid_col+1, d=low_col;

        while(b <= mid_col && c <= col)
        {
            if(A[z][b] < A[z][c])
            {
                arr[d] = A[z][b]; d++; b++;
            }
            else
            {
                arr[d] = A[z][c]; d++; c++;
            }
        }

        while(b <= mid_col)
        {
            arr[d] = A[z][b]; d++; b++;
        }

        while(c<=col)
        {
            arr[d] = A[z][c]; d++; c++;
        }

        for(int t=low_col; t<=col; t++)
        {
            A[z][t] = arr[t];
        }
    }
}
void mergeCol(int low_row, int row, int low_col, int col, int mid_row, int mid_col)
{
    for(int z=low_col; z<=col; z++)
    {
        int arr[N], b=low_row, c=mid_row+1, d=low_row;

        while(b <= mid_row && c <= row)
        {
            if(A[b][z] < A[c][z])
            {
                arr[d]=A[b][z], d++, b++;
            }
            else
            {
                arr[d]=A[c][z], d++, c++;
            }
        }

        while(b <= mid_row)
        {
            arr[d]=A[b][z], d++, b++;
        }
        while(c <= row)
        {
            arr[d]=A[c][z], d++, c++;
        }
        for(int t=low_row; t<=row; t++)
        {
            A[t][z]=arr[t];
        }
    }
}

void mergeSort(int low_row,int row,int low_col,int col)
{
    if(low_row<row || low_col<col)
    {
        int mid_row=(low_row+row)/2, mid_col=(low_col+col)/2;

        mergeSort(low_row,mid_row,low_col,mid_col);
        mergeSort(mid_row+1,row,mid_col+1,col);
        mergeSort(low_row,mid_row,mid_col+1,col);
        mergeSort(mid_row+1,row,low_col,mid_col);

		mergeRow(low_row,row,low_col,col,mid_row,mid_col);
    	mergeCol(low_row,row,low_col,col,mid_row,mid_col);
    }
    return;
}
int main()
{
    int row,col; cin>>row>>col;

    for(int i=0;i<row;i++) for(int j=0;j<col;j++)cin>>A[i][j];

    mergeSort(0,row-1,0,col-1);

    for(int i=0;i<row;i++) for(int j=0;j<col;j++) cout<<A[i][j]<<" ";
}
