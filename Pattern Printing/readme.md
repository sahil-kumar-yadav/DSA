# Pattern Printing

## solid rectangle

* * * * 
* * * * 
* * * * 
* * * * 

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

```cpp


```

```cpp


```

```cpp


```

