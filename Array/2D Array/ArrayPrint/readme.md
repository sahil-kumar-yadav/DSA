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

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```



