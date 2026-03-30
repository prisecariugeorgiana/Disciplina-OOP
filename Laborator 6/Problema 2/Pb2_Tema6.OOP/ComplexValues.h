#pragma once
#ifndef COMPLEXVALUES_H
#define COMPLEXVALUES_H

#include "JsonValue.h"

class ArrayValue : public JsonValue 
{
    std::vector<JsonValue*> elements;
public:
    ~ArrayValue();
    void add(JsonValue* v);
    void print(std::ostream& out) const override;
    operator unsigned() const override;
};

class ObjectValue : public JsonValue
{
    struct Pair 
    { 
        std::string name; JsonValue* value; 
    };
    std::vector<Pair> members;
public:
    ~ObjectValue();
    void add(std::string name, JsonValue* v);
    void print(std::ostream& out) const override;
    operator unsigned() const override;
};

#endif