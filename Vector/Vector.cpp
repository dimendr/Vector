#include <iostream>
#include <string>
#include <array>
#include <vector>
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
        delete[] this->arr;

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
        delete[] this->arr;

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
        delete[] this->arr;
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
        delete[] this->arr;
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
        if (index > size) return 0;
        return this->arr[index];
    }

    void clear() {
        delete[] this->arr;
        this->arr = new int[0];
        this->size = 0;
    }

};


int main() {
    int a[5] = { 1, 2, 3, 4, 5 };
    Vector ai(a, 5);
    ai.print();
    ai.push_back(123);
    ai.push_front(4321);
    ai.pop_back();
    ai.pop_front();
    ai.print();
    Vector aj(ai);
    aj.print();
    ai.add(12, 3);
    ai.print();

    return 0;
}
