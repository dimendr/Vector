#include <iostream>
using namespace std;

class Vector {
private:
    int* arr;
    int size;

public:
    Vector() { this->size = 0; }

    Vector(int* arr, int size) {
        this->size = size;
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->arr[i] = arr[i];
    }

    Vector(const Vector& obj) {
        this->size = obj.size;
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++)
            this->arr[i] = obj.arr[i];
    }

    int get_size() { return this->size; }

    void push_back(int n) {
        int* arr_copy = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            arr_copy[i] = this->arr[i];
        }
        if (this->arr == nullptr) {
            delete[] this->arr;
        }

        this->arr = new int[this->size + 1];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = arr_copy[i];
        }
        delete[] arr_copy;

        this->arr[this->size] = n;
        this->size++;
    }

    void push_front(int n) {
        int* arr_copy = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            arr_copy[i] = this->arr[i];
        }
        
        if (this->arr == nullptr) {
            delete[] this->arr;
        }

        this->size++;
        this->arr = new int[this->size];
        for (int i = 1; i < this->size; i++) {
            this->arr[i] = arr_copy[i - 1];
        }
        delete[] arr_copy;

        this->arr[0] = n;
    }
    void pop_back() {
        this->size--;
        int* arr_copy = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            arr_copy[i] = this->arr[i];
        }
        
        if (this->arr == nullptr) {
            delete[] this->arr;
        }
        
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = arr_copy[i];
        }
        delete[] arr_copy;
        
    }
    
    void pop_front() {
        int* arr_copy = new int[this->size - 1];
        for (int i = 1; i < this->size; i++) {
            arr_copy[i - 1] = this->arr[i];
        }
        
        if (this->arr == nullptr) {
            delete[] this->arr;
        }
        
        this->size--;
        
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = arr_copy[i];
        }

        delete[] arr_copy;
    }

    void print() {
        for (int i = 0; i < this->size - 1; i++) {
            cout << this->arr[i] << " ";
        } cout << this->arr[this->size - 1] << endl;
    }

    void add(int value, int index) {
        int* arr_copy = new int[this->size + 1];
        for (int i = 0; i < index; i++) {
            arr_copy[i] = this->arr[i];
        }
        
        arr_copy[index] = value;
        this->size++;
        
        for (int i = index + 1; i < this->size; i++) {
            arr_copy[i] = this->arr[i - 1];
        }
        delete[] this->arr;
        
        this->arr = new int[this->size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = arr_copy[i];
        }
        
        delete[] arr_copy;
    }

    int at(int index) {
        if (index >= this->size) return 0;
        return this->arr[index];
    }
    void remove(int index) {

        if (index == 0) {
            this->pop_front();
        }
        else {
            if (this->arr == nullptr) {
                this->size--;
                int* arr_copy = new int[this->size];

                for (int i = 0; i < index; i++) {
                    arr_copy[i] = this->arr[i];
                }

                for (int i = index + 1; i < size + 1; i++) {
                    arr_copy[i - 1] = this->arr[i];
                }

                delete[] this->arr;
                this->arr = new int[this->size];

                for (int i = 0; i < size; i++) {
                    this->arr[i] = arr_copy[i];
                }

                delete[] arr_copy;
            }
        }
    }

    void clear() {
        if (this->arr == nullptr) {
            delete[] this->arr;
        }
        this->arr = new int[0];
        this->size = 0;
    }
    
    Vector operator +(int value) {
        Vector a(this->arr, this->size);
        a.push_back(value);
        return a;
    }
    
    Vector operator +(const Vector& obj) {
        Vector a(this->arr, this->size);
        for(int i = 0; i < obj.size; i++)
            a.push_back(obj.arr[i]);
        return a;
    }

    /*Vector operator -(int value) {
        Vector a(this->arr, this->size);
        a.pop_back();
        return a;
    }

    int find(int value) {

    }

    Vector operator -(const Vector& obj) {
        
    }*/

    ~Vector() {
        if (this->arr == nullptr)
            delete[] this->arr;
        this->size = 0;
        cout << "DESTRUCTOR" << endl;
    }
};


int main() {
    int d[5] = {1, 2, 3, 4, 5};
    Vector a(d, 5);
    int e[3] = {1, 2, 3};
    Vector b(e, 3);
    a.remove(1);
    
    a.print();
    
    return 0;
}
