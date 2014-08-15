#include <string>
#include <vector>
#include <thread>
#include <unistd.h>
#include <condition_variable>

using namespace std;

template<typename T>
struct Node{
    T* data;
    Node* next;
    Node(T* d, Node* n=NULL): data(d), next(n){}
};

template<typename T>
class myqueue{

    private:
        Node<T> * begin;
        Node<T> * end;
        mutex begin_mu;
        mutex end_mu;
        long size;
        long maxSize;
    public:
        myqueue(){
            begin = end = new Node<T>(NULL);
            size = 0;
            maxSize = 10000;
        }
        void push(const T& da){ 
            Node<T>* temp = new Node<T>(new T(da));
            unique_lock<mutex> lock(begin_mu);
            if (size > maxSize){
                lock.unlock();
                return;
            }
            begin->next = temp;
            begin = temp;
            lock.unlock();
            size++;
        }   
        bool pop(T& returnVal){ 
            unique_lock<mutex> lock(end_mu);
            if (end->next != nullptr)
            {
                Node<T>* temp = end;
                end = end->next;
                T* data = end->data;
                lock.unlock();

                returnVal = *data;
                size--;
                delete data;
                delete temp;
                return true;
            }
            lock.unlock();
            return false;
        }
        bool isempty(){ 
            return end->next==nullptr;
        }
};
