# Pattern Printing

## solid rectangle

``` cpp
* * * * 
* * * * 
* * * * 
* * * * 
```

```cpp

void solid_rectangle()
{
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

```

## hollow rectangle

``` cpp
* * * * * 
*       *
*       *
*       *
* * * * *
```

```cpp

void hollow_rect()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            // 1 row // last row // first col // last col
            if (i == 1 || j == 1 || i == 5  || j == 5)
            {
                cout << "* ";
            }
            else{
                cout<<"  "; // print gap 
            }
        }
        cout<<endl;
    }
}

```
## half pyramid

```cpp
* 
* *
* * *
* * * *
```

```cpp


void half_pyramid()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

```

## inverted half pyramid
```cpp
* * * * * 
* * * *
* * *
* *
*
```

```cpp
void inverted_half_pyramid(){

    for(int i = 1;i<=5;i++){
        for(int j = 5;j>=i;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

```
## Hollow titled pyramid 

```cpp
* * * * * 
*     *
*   *
* *
*
```

```cpp
void tilted_half_pyramid()
{

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i == 1 || j == 1 || (i + j) == 5+1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

```
## solid full pyramid

```cpp
          * 
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *
```

```cpp
void full_pyramid(){
    for(int i = 1;i<=5;i++){
        for(int j = 5;j>=i;j--){
            cout<<"  ";
        }
        for(int j = 1;j<= 2*i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

```

```cpp

```

```cpp

```

```cpp

```






