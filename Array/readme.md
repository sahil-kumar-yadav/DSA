# Array

## Vector STL

- syntax

```cpp
vector<int>arr;
```

```cpp
vector<int>arr(n); // size
```

```cpp
vector<int>arr(n,-1);// size, value
```

# vector methods
![methods vector](image.png)

![alt text](image-1.png)

![alt text](image-2.png)

```cpp

## pair sum

```
void pair_sum_bruteforce(int a[], int na, int b[], int nb,int target)
{   
    int ans[2];

    for (int i = 0; i < na; i++)
    {
        for(int j = 0;j<nb;j++){
            if(a[i]+b[j] == target){
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
    }

    cout<<ans[0]<<" "<<ans[1];
}


```cpp

```





