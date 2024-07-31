# Array

# wave print a matrix
```cpp
Input: mat[][] = {{  1,   2,   3,   4}
                           {  5,   6,   7,   8}
                           {  9, 10, 11, 12}
                           {13, 14, 15, 16}
                           {17, 18, 19, 20}}
Output: 1 5 9 13 17 18 14 10 6 2 3 7 11 15 19 20 16 12 8 4 
```

```cpp
void wavePrint(int arr[3][4],int n,int m){
    int i = 0,j = 0;

    while(j<m){
        if(j&1){
            // j odd 
            i = n-1;
            while(i>=0){
                cout<<arr[i][j]<<" ";
                i--;
            }
        }
        else{
            // j is even 0 2 4
            i = 0;
            while(i<n){
                cout<<arr[i][j]<<" ";
                i++;
            }
        }
        cout<<endl;
        j++;

    }
}


```
## reverseWave

```cpp
Input :  1  9  4  10
         3  6  90 11
         2  30 85 72
         6  31 99 15 
Output : 10 11 72 15 99 85 90 4 9 6 30 31 6 2 3 1
```

```cpp

void ReverseWavePrint(int arr[4][4], int n, int m)
{
    int i = 0, j = m - 1;

    while (j >= 0)
    {
        if (j & 1)
        {
            // j odd // 1 3
            i = 0;
            while (i < n)
            {
                cout << arr[i][j] << " ";
                i++;
            }
        }
        else
        {
            // j is even 0 2 4
            i = n - 1;
            while (i >= 0)
            {
                cout << arr[i][j] << " ";
                i--;
            }
        }
        cout << endl;
        j--;
    }
}
```
# Print Matrix in Z form

```cpp
 Input: [[4, 5, 6, 8], 
            [1, 2, 3, 1], 
            [7, 8, 9, 4], 
            [1, 8, 7, 5]]
        
    Output: 4 5 6 8
                3
              8
            1 8 7 5
```

```cpp
void ZFormPrint(int arr[4][4], int n, int m)
{
    int i = 0, j = m - 1;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i == 0 || i == n-1 || i+j == m-1){
                cout<<arr[i][j]<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }

}

```

```cpp

```

```cpp

```


