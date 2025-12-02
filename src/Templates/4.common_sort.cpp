#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void bubble_sort(int arr[], int n) { // 复杂度o(n2)

    for (int i = 1; i <= n; i++) {
        bool fin = true;
        for (int j = 1; j <= n - i; j++) {
            if (arr[j] > arr[j+1]) {
                
                int temp = arr[j+1];
                
                arr[j+1] = arr[j];
                arr[j] = temp;
                
                fin = false;
            
            }
        }
        if (fin) break;
    }
}

void bucket_sort(int arr[], int n,int brr[]) { //brr的范围必须开到数据上限，空间换时间，复杂度o(max(数据范围,n))

    for (int i = 1; i <= n; i++) {

        brr[(arr[i])]++;

    }

}

void quicksort(int arr[], int n) {

    sort(arr + 1, arr + n + 1); // 默认从小到大，前一个参数为起始地址，后一个为结尾地址（排序元素不包括结尾地址所指向的元素）
    /*
    struct stuinf {
        string nam;
        int score;

    };
    stuinf a;

    int compare(stuinf a, stuinf b) {

        return a.score < b.score; //重新定义>或<运算符

    }

    sort(a, a + n, compare);
    */

}

void myquicksort(int arr[], int le, int ri) {

    if (le >= ri) return;

    int key = arr[le];
    int i = le,j = ri;


     while (i < j) {

        while (i < j && arr[j] >= key) 
            j--;
        
        if (arr[j] < key) {
            
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        
        }

        while (i < j && arr[i] <= key)
            i++;

        if (arr[i] > key)  {

            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j--;

        }    

     }   

    myquicksort(arr, le, i - 1);
    myquicksort(arr, i + 1, ri);

}

void vergesort(int arr[], int st, int en) {

    if (st >= en) return;

    int m = (st + en) / 2;
    vector <int> brr(11, 0);

    vergesort(arr, st, m);
    vergesort(arr, m + 1, en);

    int i = st;
    int k = st;
    int j = m + 1;


    while (i <= m && j <= en) {

        if (arr[j] > arr[i]) {
            
            brr[k] = arr[i];
            k++;
            i++;

        }

        else {
            
            brr[k] = arr[j];
            k++;
            j++;

        }
    }

    while (i <= m) {

        brr[k] = arr[i];
        k++;
        i++;

    }

    while (j <= en) {

        brr[k] = arr[j];
        k++;
        j++;

    }

    for (int l = st; l <= en; l++) 
        arr[l] = brr[l];

}

void bucket_sort_print(int brr[], int n) {

    for (int i = 1; i <= n; i++)
        for (; brr[i]; brr[i]--)
            cout << i << " ";
    cout << endl;

}

void printarr(int a[], int n) {

    for (int i = 1; i <= 10; i++) {
        
        cout << a[i] << " ";

    }
    cout << endl;
}


int main() {

    int arr[11] = {0,4,2,31,23,4,233,2,1,23,2,};
    int brr[300];
    memset(brr, 0 ,sizeof(brr));


    //bubble_sort(arr, 10);

    //bucket_sort(arr, 10, brr);

    //quicksort(arr, 10);
    //myquicksort(arr, 1, 10);
    vergesort(arr, 1, 10);

    printarr(arr, 10);

    //bucket_sort_print(brr, 300);
    return 0;
}


int brr[505];
int aux[505];

void merge(int le, int ri, int mid) {

    int a = le;
    int b = mid + 1;
    int i = le;

    while (a <= mid && b <= ri) {

        aux[i++] = brr[a] < brr[b] ? brr[a++] : brr[b++];

    }

    while (a <= mid) {

        aux[i++] = brr[a++];

    }

    while (b <= ri) {

        aux[i++] = brr[b++];

    }

    for (int i = le; i <= ri; i++) {

        brr[i] = aux[i];

    }

}

void mymergesort1(int le, int ri) {

    while (le < ri) {

        int mid = le + ((ri - le) >> 1);

        mymergesort1(le, mid);
        mymergesort1(mid+1, ri);
        merge(le, ri, mid);
    
    }

}

void mymergesort1(int n) {

    for (int step = 1; (step << 1) <= n; step <<= 1) {

        int le = 0, ri, mid;

        while (le < n) {

            mid = le + step - 1;

            if (mid + 1 >= n) break; //已经没有右侧了

            ri = min(le + (step << 1) - 1, n - 1);

            merge(le, ri, mid);

            le = ri + 1;

        }

    }

}