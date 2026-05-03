#include <cstdio>

template <typename K, typename V>
class Map
{
private:
    struct Element
    {
        K key;
        V value;
        int index;
    };

    Element* data;
    int current_count;
    int capacity;

public:
    Map()
    {
        current_count = 0;
        capacity = 10;
        data = new Element[capacity];
    }

    ~Map()
    {
        delete[] data;
    }

    V& operator[](const K& key)
    {
        for (int i = 0; i < current_count; i++)
        {
            if (data[i].key == key)
            {
                return data[i].value;
            }
        }

        if (current_count == capacity)
        {
            capacity *= 2;
            Element* newData = new Element[capacity];
            for (int i = 0; i < current_count; i++) newData[i] = data[i];
            delete[] data;
            data = newData;
        }

        data[current_count].key = key;
        data[current_count].index = current_count;
        return data[current_count++].value;
    }

    void Set(const K& key, const V& value)
    {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value)
    {
        for (int i = 0; i < current_count; i++)
        {
            if (data[i].key == key)
            {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }

    int Count()
    {
        return current_count;
    }

    void Clear()
    {
        current_count = 0;
    }

    bool Delete(const K& key)
    {
        for (int i = 0; i < current_count; i++)
        {
            if (data[i].key == key)
            {
                for (int j = i; j < current_count - 1; j++)
                {
                    data[j] = data[j + 1];
                    data[j].index = j;
                }
                current_count--;
                return true;
            }
        }
        return false;
    }

    Element* begin() { return &data[0]; }
    Element* end() { return &data[current_count]; }
};

int main()
{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto const& e : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", e.index, e.key, e.value);
    }

    m[20] = "result";

    printf("\nDupa modificare:\n");
    for (auto const& e : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", e.index, e.key, e.value);
    }

    return 0;
}