#ifndef FAMILYMEMBER_H
#define FAMILYMEMBER_H

#include <vector>
#include "Person.h"

template <typename T>
class FamilyMember {
public:
    FamilyMember(const T& data) : data_(data) {}

    void addChild(const T& childData) {
        children_.push_back(new FamilyMember<T>(childData));
    }

    T& getData() {
        return data_;
    }

    const std::vector<FamilyMember<T>*>& getChildren() const {
        return children_;
    }

    ~FamilyMember() {
        for (FamilyMember<T>* child : children_) {
            delete child;
        }
    }

private:
    T data_;
    std::vector<FamilyMember<T>*> children_;
};

#endif
