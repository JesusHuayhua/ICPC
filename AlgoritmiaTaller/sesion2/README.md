# Sesion 2

Binary Search

La relación matemática, de la busqueda binaria, es como la `Ley de la Monotomía`.

Consideremos a los valores menores o iguales al valor buscado como `V` y a todos los que
sean mayores, sean `F`.

- Caso 1: Todos los valores sean `F`, por lo tanto no existe el elemento buscado.
- Caso 2: Todos los valores sean `V`, por lo tanto el elemento buscado es el último.
- Caso 3: Existen tanto `V` como `F`.

```C++
class solution{
    public:
        // Return whether or n oa_i <= t
        bool Predicate(const vector<int>& a, int i, int t){
            return a[i] <= t;
        }
        bool Check(const vector<int>& a,int i, int t){
            return a[i] == t;
        }

        int search(vector<int>& nums, int target){
            int n = (int)nums.size();
            // Caso 1
            if(!Check(nums,0,target)) return -1;
            // Caso 2
            if(Predicate(nums,n-1,target)){
              if(Check(nums,n - 1,target)){
                return n - 1;
              }
              return -1;
            }
            // CASE TTTFFFF
            int l = 0;
            int r = n - 1;
            while(r - l > 1){
                int m = (l + r) / 2;
                if(Predicate(nums,m,target)){
                    l = m;
                }else{
                    r = m;
                }
            }
            // TF
            if(Check(nums,l, target)) return l;
            return -1;
        }
}
```

# Problemas:


## [Search a 2D matrix](https://leetcode.com/problems/search-a-2d-matrix/)

Para este caso; podemos ver a la matriz como si fuera un único arreglo; puesto que
el primer elemento de la siguiente fila, es mayor que el último elemento de la fila anterior.

Para hacer esto asignamos un valor a cada una de los elementos de la matriz, de la siguiente manera:

<center>
<table>
<!-- <tr><th>Ejemplo problema</th><th>Forma de verlo</th></tr> -->
<tr><td>

| 1   | 3   | 5   | 7   |
| --- | --- | --- | --- |
| 10  | 11  | 16  | 20  |
| 23  | 30  | 34  | 60  |

</td><td>

| 0   | 1   | 2   | 3   |
| --- | --- | --- | --- |
| 4   | 5   | 6   | 7   |
| 8   | 9   | 10  | 11  |

</td></tr> 
</table>
</center>

Ahora para poder recuperar el valor de alguno de los valores de la matrix(`nxm`), a travéz,
del indice que hemos fijado. Sería de la siguiente forma: `x= i/m`, y `y = i%m`.

Ejemplo: si queremos recuperar el número 20; para esta matriz de `3x4`.

> 20, tiene índice `i = 7`
>
> x = 7 / 4 = 1
>
> y = 7 % 4 = 3
    
Por lo tanto; si cumple con lo solicitado.

```C
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left = 0;
    int right = matrixSize * matrixColSize[0];
    while(right - left > 1){
        int m = (left + right) / 2;
        if(matrix[m/matrixColSize[0]][m % matrixColSize[0]] <= target){
            left = m;
        }else{
            right = m;
        }
    }
    if(matrix[left/matrixColSize[0]][left % matrixColSize[0]] == target) return true;
    else return false;
}
```
indices:

x = i/m;  y = i % m

## Variación:

| 1   | 3   | 4   | 7   |
| --- | --- | --- | --- |
| 4   | 8   | 9   | 10  |
| 7   | 10  | 14  | 17  |
 
- [Sqrt(x)](https://leetcode.com/problems/sqrtx/)

Ejemplo Nivel FUNPRO:

```C
int Raiz(int n){
    assert(n >= 0);
    int r = 0;
    while(true){
        if(r*r > n){
            return r;
        }
        r++;
    }
}
```

A esta forma se le conoce como busqueda binaria sobre el resultado

```C++
typedef long long Long;

class Solution{
    int mySqrt(int x){
        // TTFFF
        if ( x == 0) return 0;
        // Case TTTFFF
        Long l = 0;
        Long r = 1e5;
        while(r - l > 1){
            Long m = (l + r) / 2;
            if(m*m <= x){
                l = m;
            }else{
                r = m;
            }
        }
        // TF
        return l;
    }
}
```

- [Problem koko eat banana]()

```C++
typedef long long Long;
class Solution {
public:
    bool Check(const vector<int>& piles,Long k,int h){
        int n = (int)piles.size();
        Long cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += (piles[i] + k - 1) / k;
        }
        return cnt<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = (int)piles.size();
        // Case FFFFFTTTT
        Long l = 0;
        Long r = 1e9;
        while(r - l > 1){
            Long m = (l + r) / 2;
            if(Check(piles,m,h)){
                r = m;
            }else{
                l = m;
            }
        }
        return r;
    }
};
```
