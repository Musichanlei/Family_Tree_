#ifndef FTT_H
#define FTT_H

#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "familyMember.h"

template <typename T>
class FamilyTreeTraversal {
public:
    static void preorderTraversal(FamilyMember<T>* node, int level = 0) {
        
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < level; i++) {
            std::cout << "-";
        }

        std::cout << node->getData().toString() << std::endl;

                std::vector<FamilyMember<T>*> children = node->getChildren();

        if (!children.empty()) {
            std::cout << "Children of " << node->getData().getFirst() << " " << node->getData().getLast() << ":" << std::endl;
        }

        for (FamilyMember<T>* child : children) {
            preorderTraversal(child, level + 1);
}

    }

    static void search(FamilyMember<T>* node, const std::string& name, std::vector<FamilyMember<T>*>& results) {
    if (node == nullptr) {
        return;
    }

    if (node->getData().getFirst() == name) {
        results.push_back(node);
    }

    std::vector<FamilyMember<T>*> children = node->getChildren();

    for (FamilyMember<T>* child : children) {
    search(child, name, results);
}

}

};
#endif

