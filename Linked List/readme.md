# Linked List


## Find n/k th node in Linked list

```cpp
int findLength(Node *root)
    {
    
        Node *temp = root;
        int len = 0;
        while (temp)
        {
            temp = temp->next;
            len++;
        }
    
        return len;
    }
    int fractional_node(struct Node *head, int k) {
        // your code here
        int n = findLength(head);
        
        int nBYk = ceil(n/(1.0*k));
        
        Node *temp = head;
        
        while(--nBYk){
            temp = temp->next;
        }
        
        return temp->data;
         
    }
```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```

## 

```cpp


```



