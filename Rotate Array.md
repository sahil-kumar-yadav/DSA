```javascript

void revese(int arr[],int start,int end){
        
        while(start<end){
            swap(arr[start++],arr[end--]);
        }
    }

void rotateArr(int arr[], int d, int n){
         d=d%n;
        revese(arr,0,n-1);
        revese(arr,0,n-d-1);
        revese(arr,n-d,n-1);
    }

```
