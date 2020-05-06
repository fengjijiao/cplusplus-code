#include <iostream>
using namespace std;
class List {
public:
    List * Head;
    List * Tail;
    List * Next;
    int num;
    List() {
        Head = Tail = Next = NULL;
    }
    virtual void add(int n) = 0;//添加节点
    virtual int retrive() = 0;//取值并删除节点
};
//队列
class Queue : public List {
public:
    void add(int n) {
        Queue * nLi = new Queue();
        if(!nLi) {
            cout << "内存分配失败，生成新对象失败！" << endl;
            exit(-1);
        }
        //链表末尾插入
        /*if (Tail) Tail->Next = nLi;
        nLi -> num = n;
        Tail = nLi;
        //Next = nLi;
        nLi -> Next = NULL;
        if(!Head) Head = Tail;*/
        nLi -> num = n;
        if(!Head) Head = nLi;
        if(!Tail) {
            Tail = nLi;
        }else {
            Tail -> Next = nLi;
            Tail = nLi;
        }
        if(!Next) Next = nLi;
    }
    int retrive() {
        if(!Head) {
            cout << "队列为空！" << endl;
            exit(-1);
        }
        List *p = Head;
        int result = Head -> num;
        if(Head == Tail) {//要删除的是最后一个节点
            Head = NULL;
            Tail = NULL;
            Next = NULL;
        }else {
            Head = Head -> Next;
            Next = Next -> Next;
        }
        delete p;
        return result;
    }
};
class Heap : public List {
public:
    void add(int n) {
        Heap * nLi = new Heap();
        if(!nLi) {
            cout << "内存分配失败，生成新对象失败！" << endl;
            exit(-1);
        }
        nLi -> num = n;
        Head = nLi;
        if(!Tail) {
            Tail = nLi;
        }
        if(!Next) {
            Next = nLi;
        }else {
            nLi -> Next = Next;
            Next = nLi;
        }
    }
    int retrive() {
        if(!Head) {
            cout << "堆栈为空！" << endl;
            exit(-1);
        }
        int result = Head -> num;
        List * p = Head;
        if(Head == Tail) {//要删除的是最后一个节点
            Head = NULL;
            Tail = NULL;
            Next = NULL;
        }else {
            Head = Head -> Next;
            Next = Next -> Next;
        }
        delete p;
        return result;
    }
};
int main() {
    Queue q;
    Heap h;
    for(int i=0;i<9;i++) q.add(i);
    for(int i=0;i<10;i++) cout << "队列取出：" << q.retrive() << endl;
    for(int i=0;i<9;i++) h.add(i);
    for(int i=0;i<10;i++) cout << "堆栈取出：" << h.retrive() << endl;
    return 0;
}
/*
队列取出：0
队列取出：1
队列取出：2
队列取出：3
队列取出：4
队列取出：5
队列取出：6
队列取出：7
队列取出：8
队列取出：队列为空！
//
堆栈取出：8
堆栈取出：7
堆栈取出：6
堆栈取出：5
堆栈取出：4
堆栈取出：3
堆栈取出：2
堆栈取出：1
堆栈取出：0
堆栈取出：堆栈为空！
 */
/*
队列和堆栈都是链表类型，它和数组不同的是个数是不定的，因此必须用指针来“记住”开始、末尾和下一个的位置。因此基类中有三个指针head、tail、next成员变量。还有一个成员变量num用来表示当前插入的值。另外定义2个纯虚函数store()和retrieve()来表示存贮(即增加)一个元素、处理(减少)一个元素，这是要编程的要点。

派生类里面要实现2个功能，即增加节点、删除节点。增加时首先new一个节点并对num赋值，然后修改链表的三个指针。而删除时要先修改链表的三个指针，然后再删除节点。

队列和堆栈的不同处是：队列是先进先出、后进后出；而堆栈则是先进后出、后进先出。这就是修改三个链表指针时要注意的地方。这需要有一点数据结构方面的知识。
 */
/*

                  Head Pointer                                       New Node 1                                  New Node 2

            +--------------------+                            +--------------------+           2           +--------------------+
            |                    |                            |                    |   +---------------->  |                    |
            |                    |                            |                    |   |                   |                    |
            |                    |     1                      |                    |   |                   |                    |
            |       Head +--------------------------------->  |       Head         |   |                   |       Head         |
            |                    |                            |                    |   |                   |                    |
            |                    |                            |                    |   |                   |                    |
            |                    |                            |                    |   |                   |                    |
            |                    |                            |                    |   |                   |                    |
            |                    |     1 1`s Tail is changed while new node 2 created  |                   |                    |
            |       Tail +--------------------------------->  |       Tail         |   |                   |       Tail         |
            |            +--------------------------------+   |                    |   |                   |                    |
            |                    |                        |   |                    |   |                   |                    |
            |                    |                        |   |                    |   |                   |                    |
            |                    |     1                  |   |                    |   |        2          |                    |
            |       Next +--------------------------------->  |       Next +---------------------------->  |       Next         |
            |                    |                        |   |                    |   |                   |                    |
            |                    |                        |   |                    |   |                   |                    |
            |                    |                        |   |                    |   |                   |                    |
            +--------------------+                        |   +--------------------+   |                   +--------------------+
                                                          |                            |
                                                          +----------------------------+
 */
