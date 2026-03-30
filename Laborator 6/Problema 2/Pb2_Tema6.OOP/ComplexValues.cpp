#include "ComplexValues.h"

ArrayValue::~ArrayValue() 
{
    for (auto e : elements) delete e; 
}

void ArrayValue::add(JsonValue* v) 
{
    if (elements.size() < 16) elements.push_back(v);
}

void ArrayValue::print(std::ostream& out) const
{
    out << "[";
    for (size_t i = 0; i < elements.size(); ++i) 
    {
        elements[i]->print(out);
        if (i < elements.size() - 1) out << ", ";
    }
    out << "]";
}

ArrayValue::operator unsigned() const
{
    unsigned count = 1;
    for (auto e : elements) count += (unsigned)(*e);
    return count;
}

ObjectValue::~ObjectValue()
{
    for (auto m : members) delete m.value;
}

void ObjectValue::add(std::string name, JsonValue* v) 
{
    if (members.size() < 16) members.push_back({ name, v });
}

void ObjectValue::print(std::ostream& out) const
{
    out << "{";
    for (size_t i = 0; i < members.size(); ++i) 
    {
        out << "\"" << members[i].name << "\": ";
        members[i].value->print(out);
        if (i < members.size() - 1) out << ", ";
    }
    out << "}";
}

ObjectValue::operator unsigned() const 
{
    unsigned count = 1;
    for (auto m : members) count += (unsigned)(*m.value);
    return count;
}