#pragma once
#include <string>

using std::string;

class Zmogus {
protected:
    string vardas_;
    string pavarde_;

public:
    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const string& v, const string& p) : vardas_(v), pavarde_(p) {}

    virtual string vardas() const = 0;
    virtual string pavarde() const = 0;

    virtual ~Zmogus() {
        vardas_.clear();
        pavarde_.clear();
    }
};



