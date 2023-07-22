//
// Created by yjs on 2022/4/15.
//


#include <iostream>
#include <cstdlib>


using namespace std;


namespace SqlistTest {
    static const int MAXSIZE = 10;
    template<class T>
    struct SQList {
        T data[MAXSIZE];
        int length;
    };

    template<class T>
    void InitList(SQList<T> &L) {
        for (int i = 0; i < MAXSIZE; ++i) {
            L.data[i] = 0;
        }
        L.length = 0;
    }

    // 在L的位序i插入元素e (i is [1,MAXSIZE])
    template<class T>
    bool ListInsert(SQList<T> &L, int i, T e) {
        if (i < 1  || i > L.length+1) {
            return false;
        }
        if(L.length>=MAXSIZE){
            return false;
        }
        // 将 i 位置和以后的元素后移1位
        for (int j = L.length; j >= i; j--) {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = e;
        L.length++;
        return true;
    }

    template<class T>
    bool ListDelete(SQList<T> & L,int i ,T & e){
        // base case
        if(i<1 || i>L.length+1){
            return false;
        }
        e=L.data[i-1];
        for (int j = i; j < L.length; ++j) {
            L.data[j-1]=L.data[j];
        }

        L.length--;
        return true;




    }


    template<class T>
    bool GetElem(const SQList<T> & L ,int i,T& e){
        if(i<1 || i>L.length+1){
            return false;
        }
        e=L.data[i-1];
        return true;
    }

    template<class T>
    int LocateElem(const SQList<T> & L,T e){
        for (int i = 0; i < L.length; ++i) {

            if(L.data[i]==e){
                return i+1;
            }
        }
        return 0;


    }



    template<class T>
    void  PrintSQList(const SQList<T>  & L){
        cout << string(10,'#')<< " Start PrintSQList "<< string(10,'#')<<endl;
        for (int i = 0; i <MAXSIZE; ++i) {
            cout << "data[" << i << "] is [" << L.data[i] << "]" << endl;
        }
        cout << string(10,'#')<< " End PrintSQList "<< string(10,'#')<<endl;

    }


}


namespace SqlistTest2 {
    static const int initSIZE = 10;
    template<class T>
    struct SQList {
        T *data;
        int length;
        int maxSIZE;
    };

    template<class T>
    void InitList(SQList<T> &L) {
        L.data = (T *) malloc(initSIZE * sizeof(T));
        L.length = 0;
        L.maxSIZE = initSIZE;
    }

    template<class T>
    bool IncreaseSize1(SQList<T> &L, int len) {
        L.data = (T *) malloc((L.maxSIZE + len) * sizeof(T));
        if(L.data== nullptr){
            return false;

        }
        L.maxSIZE = L.maxSIZE + len;
        return true;
    }

    template<class T>
    void IncreaseSize2(SQList<T> &L, int len) {
        T *p = L.data;
        L.data = (T *) realloc(L.data, (L.maxSIZE + len) * sizeof(T));
        for (int i = 0; i < L.length; ++i) {
            L.data[i] = p[i];

        }
        L.maxSIZE = L.maxSIZE + len;
        free(p);
    }


}


int main() {

    SqlistTest::SQList<int> L;
    SqlistTest::InitList(L);
//    SqlistTest::PrintSQList(L);
    cout << SqlistTest::ListInsert(L,1,1)<<endl;
    cout << SqlistTest::ListInsert(L,2,2)<<endl;
    cout << SqlistTest::ListInsert(L,3,3)<<endl;
    cout << SqlistTest::ListInsert(L,4,4)<<endl;
    cout << SqlistTest::ListInsert(L,5,5)<<endl;
    SqlistTest::PrintSQList(L);
    int res;
    cout << SqlistTest::ListDelete(L,2,res)<<endl;

    SqlistTest::PrintSQList(L);
    cout << res<<endl;





}
