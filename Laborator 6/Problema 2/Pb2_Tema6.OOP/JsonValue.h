#pragma once
#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <iostream>
#include <vector>
#include <string>

class JsonValue 
{
public:
    virtual ~JsonValue() {}
    virtual void print(std::ostream& out) const = 0;
    virtual operator unsigned() const = 0;
};

class NullValue : public JsonValue 
{
public:
    void print(std::ostream& out) const override 
    { 
        out << "null";
    }
    operator unsigned() const override
    {
        return 1;
    }
};

class NumberValue : public JsonValue 
{
    int val;
public:
    NumberValue(int v) : val(v) {}
    void print(std::ostream& out) const override 
    { 
        out << val; 
    }
    operator unsigned() const override
    { 
        return 1; 
    }
};

class BoolValue : public JsonValue 
{
    bool val;
public:
    BoolValue(bool v) : val(v) {}
    void print(std::ostream& out) const override
    {
        out << (val ? "true" : "false"); 
    }
    operator unsigned() const override 
    { 
        return 1;
    }
};

class StringValue : public JsonValue
{
    std::string val;
public:
    StringValue(std::string v) : val(v) 
    { 
        if (val.length() > 255) val = val.substr(0, 255); 
    }
    void print(std::ostream& out) const override 
    { 
        out << "\"" << val << "\""; 
    }
    operator unsigned() const override
    { 
        return 1;
    }
};

#endif