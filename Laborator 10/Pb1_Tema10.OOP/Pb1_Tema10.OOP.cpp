#include<iostream>
#include<exception>

using namespace std;
 
class Invalidexception : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

class OutOfMemory : public exception
{
    virtual const char* what() const throw()
    {
        return "Nu am sufiecienta memorie";
    }
};


class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    T List;
    int Current;
    int size;
public:
    ArrayIterator()
    {
        Current = nullptr;
    }
    ArrayIterator(T* start, int index, int size)
    {
        
        this->index = index;
        this->size = size;
    }
    ArrayIterator& operator ++ ()
    {
        if (Current == size)
            throw Invalidexception();
        this->Current++;
        Current++;
        return this;
    }
    ArrayIterator& operator -- ()
    {
        this->current--;
        return this;
    }
    bool operator== (const ArrayIterator<T>& other) const
    {
        return this->Current == other.Current;
    }
    bool operator!=(const ArrayIterator<T>& other) const
    {
        return this->Current != other.Current;
    }
    T* GetElement()
    {
        if (List != nullptr) {
            return List[Current];
        }
        return nullptr;
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array()
    {
        this->List = nullptr;
        this->Capacity = 0;
        this->Size = 0;
    }
    ~Array()
    {
        for (int i = 0; i < this->Size; i++)
        {
            delete this->List[i];
        }
    }
    Array(int capacity)
    {
        this->Size = 0;
        this->Capacity = capacity;
        this->List = new T*[capacity];
    }
    Array(const Array<T>& otherArray)
    {
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Capacity;

        if (otherArray.List != nullptr) {
            this->List = new T * [this->Capacity];

            for (int i = 0; i < this->Size; i++) {
                this->List[i] = new T(*(otherArray.List[i]));
            }
        }
        else {
            this->List = nullptr;
        }
    }
    T& operator[] (int index)
    {
        if (index < 0 || index >= Size)
        {
            throw Invalidexception();
        }
        return *(this->List[index]);
    }

    const Array<T>& operator+=(const T& newElem)
    {   
        cout << "Debug: Size=" << Size << ", Capacity=" << Capacity << endl;
        if (this->Size == this->Capacity)
        {
            throw OutOfMemory();
        }
        this->List[this->Size] = new T(newElem);
        this->Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > this->Capacity)
        {
            throw Invalidexception();
        }
        this->List[index] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < 0 || index >= this->Capacity)
        {
            throw new Invalidexception();
        }
        unsigned int currentCapacityLeft = this->Capacity - this->Size;
        if (currentCapacityLeft < otherArray.Size)
        {
            throw new OutOfMemory();
        }
        unsigned int i = this->Size;
        while (i >= index)
        {
            this->List[i + otherArray.Size] = this->List[i];
            i--;
        }
        for (i = index; i < index + otherArray.Size; i++)
        {
            this->List[i] = otherArray.List[i];
        }
        return *this;
    }
    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= this->Size)
        {
            throw new Invalidexception();
        }
        for (unsigned int i = index; i < this->Size - 2; i++)
        {
            this->List[i] = this->List[i + 1];
        }
        this->Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray) return true;

        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;

        this->Size = otherArray.Size;
        this->Capacity = otherArray.Capacity;
        this->List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            this->List[i] = new T(*otherArray.List[i]);
        }
        return true;
    }

    void Sort()
    {
        for (int i = 0; i < Size - 1; i++)
        {
            for (int j = i + 1; j < Size; j++)
            {
                if (*List[j] < *List[i])
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }
        }

    }
    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size - 1; i++)
        {
            for (int j = i + 1; j < Size; j++)
            {
                if (compare(*List[i], *List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }
        }
    }
    void Sort(Compare* comparator)
    {

        for (int i = 0; i < Size - 1; i++)
        {
            for (int j = i + 1; j < Size; j++)
            {
                if (comparator->CompareElements(List[i], List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }
        }
    }

    int BinarySearch(const T& elem)
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (*List[mid] == elem)
                return mid;

            if (*List[mid] < elem)
                left = mid + 1; 
            else
                right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = compare(*List[mid], elem);

            if (res == 0) return mid;
            if (res < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int res = comparator->CompareElements(List[mid], (void*)&elem);

            if (res == 0) return mid;
            if (res < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem) {
                return i; 
            }
        }
        return -1; 
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i], elem) == 0) {
                return i;
            }
        }
        return -1;
    }
    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0) {
                return i;
            }
        }
        return -1;
    }

    int GetSize()
    {
        return Size;
    }
    int GetCapacity()
    {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, 0);
    }
    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size);
    }
};

int main() {
    try {
        Array<int> a(10);
        a += 10;
        a += 20;
        cout << "Elementul 0: " << a[0] << endl;
        cout << "Capacitate: " << a.GetCapacity() << endl;

        cout << a[10];
    }
    catch (exception& e) {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }
    return 0;
}