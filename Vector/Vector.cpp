#include <iostream>
#include <string>
#include <sstream>
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

    void print();
    
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
            if (this->arr != nullptr) {
                int* arr_copy = new int[this->size - 1];

                for (int i = 0; i < index; i++) {
                    arr_copy[i] = this->arr[i];
                }

                for (int i = index + 1; i < size; i++) {
                    arr_copy[i - 1] = this->arr[i];
                }
                this->size--;
                delete[] this->arr;
                this->arr = new int[this->size];

                for (int i = 0; i < size; i++) {
                    this->arr[i] = arr_copy[i];
                }

                delete[] arr_copy;
            }
        }
    }
    
    bool isEmpty() {
        if (this->size < 1) return true;
        return false;
    }

    void clear() {
        if (this->arr == nullptr) {
            delete[] this->arr;
        }
        this->arr = new int[0];
        this->size = 0;
    }
    
    void swap(int index_1, int index_2) {
        if (index_1 >= 0 && index_2 >= 0 && index_1 < size && index_2 < size) {
            int temp = arr[index_1];
            arr[index_1] = arr[index_2];
            arr[index_2] = temp;
        }
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

    Vector operator -(int value) {
        
        Vector a(this->arr, this->size);

        int index = a.find(value);

        if (index == -1) return a;
        a.remove(index);

        return a;
    }

    int find(int value) {
        for (int i = 0; i < this->size; i++) {

            if (value == this->arr[i]) return i;
        }
        return -1;
    }

    Vector operator -(Vector& obj) {
        Vector a(this->arr, this->size);
        for (int i = 0; i < obj.size; i++) {
            int index = a.find(obj.arr[i]);
            if (index != -1){ a.remove(index); }
        }
        return a;
    }

    ~Vector() {
        if (this->arr == nullptr)
            delete[] this->arr;
        this->size = 0;
    }
};

ostream& operator << (ostream &out, Vector obj) {
    for (int i = 0; i < obj.get_size(); i++)
        out << obj.at(i) << " ";
    return out;
}

istream& operator >> (istream &in, Vector& obj) {
    string s;
    getline(in, s);
    stringstream ss(s);
    
    int a;
    while (ss >> a) {
        obj.push_back(a);
    }
    
    return in;
}

void Vector::print() {
    for (int i = 0; i < this->size - 1; i++) {
        cout << this->arr[i] << " ";
    } cout << this->arr[this->size - 1] << endl;
}


int main() {
    Vector a;
    cin >> a;
    cout << a << endl;
    
    for (int i = 0; i < a.get_size(); i++) {
        for(int j = 0; j < a.get_size() - 1; j++) {
            if(a.at(j) > a.at(j + 1)) {
                a.swap(j, j + 1);
            }
        }
    }
    
    cout << a << endl;
    
    return 0;
}
