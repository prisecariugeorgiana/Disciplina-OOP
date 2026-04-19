#include <iostream>

template <typename T>
class Tree
{
private:
    struct Node
    {
        T value;
        Node** children;
        int count;
        int capacity;

        Node(const T& val)
        {
            value = val;
            count = 0;
            capacity = 10;
            children = new Node * [capacity];
        }

        ~Node()
        {
            for (int i = 0; i < count; i++)
            {
                delete children[i];
            }
            delete[] children;
        }
    };

    Node* root;

public:
    Tree()
    {
        root = nullptr;
    }

    ~Tree()
    {
        delete root;
    }

    Node* add_node(Node* parent, const T& value)
    {
        Node* newNode = new Node(value);

        if (parent == nullptr)
        {
            if (root == nullptr)
            {
                root = newNode;
            }
            else
            {
                delete newNode;
                return nullptr;
            }
        }
        else
        {
            if (parent->count == parent->capacity)
            {
                parent->capacity *= 2;
                Node** new_list = new Node * [parent->capacity];
                for (int i = 0; i < parent->count; i++)
                {
                    new_list[i] = parent->children[i];
                }
                delete[] parent->children;
                parent->children = new_list;
            }
            parent->children[parent->count++] = newNode;
        }
        return newNode;
    }

    Node* get_node(Node* parent = nullptr)
    {
        return (parent == nullptr) ? root : parent;
    }

    void delete_node(Node* node)
    {
        if (node == root)
        {
            delete root;
            root = nullptr;
        }
        else
        {
            delete node;
        }
    }

    Node* find(bool (*compare)(const T&, const T&), const T& value, Node* current = nullptr)
    {
        if (current == nullptr)
        {
            current = root;
        }

        if (current == nullptr)
        {
            return nullptr;
        }

        if (compare(current->value, value))
        {
            return current;
        }

        for (int i = 0; i < current->count; i++)
        {
            Node* res = find(compare, value, current->children[i]);
            if (res)
            {
                return res;
            }
        }
        return nullptr;
    }

    void insert(Node* parent, int index, const T& value)
    {
        if (!parent || index < 0 || index > parent->count)
        {
            return;
        }

        Node* newNode = new Node(value);

        if (parent->count == parent->capacity)
        {
            parent->capacity *= 2;
            Node** new_list = new Node * [parent->capacity];
            for (int i = 0; i < parent->count; i++)
            {
                new_list[i] = parent->children[i];
            }
            delete[] parent->children;
            parent->children = new_list;
        }

        for (int i = parent->count; i > index; i--)
        {
            parent->children[i] = parent->children[i - 1];
        }

        parent->children[index] = newNode;
        parent->count++;
    }

    void sort(Node* parent, int (*compare)(const T&, const T&) = nullptr)
    {
        if (!parent)
        {
            return;
        }

        for (int i = 0; i < parent->count - 1; i++)
        {
            for (int j = 0; j < parent->count - i - 1; j++)
            {
                bool swap = false;
                if (compare)
                {
                    if (compare(parent->children[j]->value, parent->children[j + 1]->value) > 0)
                    {
                        swap = true;
                    }
                }
                else
                {
                    if (parent->children[j + 1]->value < parent->children[j]->value)
                    {
                        swap = true;
                    }
                }

                if (swap)
                {
                    Node* temp = parent->children[j];
                    parent->children[j] = parent->children[j + 1];
                    parent->children[j + 1] = temp;
                }
            }
        }
    }

    int count(Node* start = nullptr)
    {
        if (start == nullptr)
        {
            start = root;
        }

        if (start == nullptr)
        {
            return 0;
        }

        int total = 1;
        for (int i = 0; i < start->count; i++)
        {
            total += count(start->children[i]);
        }
        return total;
    }
};

int main()
{
    Tree<int> t;

    auto root = t.add_node(nullptr, 10);

    t.add_node(root, 20);
    t.add_node(root, 5);

    std::cout << "Numar total noduri: " << t.count() << std::endl;

    return 0;
}