#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "familyMember.h"
#include "FTT.h"
using namespace std;
int main() {
    int theLevel = 0;
    // Create family members
    Person PhineusNigellus("Phineus Nigellus", "Black", "1847", "1925", "Ursula Flint");
    Person Sirius("Sirius", "Black Jr.", "1877", "1952", "Hesper Gamp");
    Person arcturusBlackJr("Arcturus", "Black Jr.", "1901", "1991", "Melania McMillan");
    Person lycorisBlack("Lycoris", "Black", "1904", "1965");
    Person regulusBlackSr("Regulus", "Black Sr.", "1906", "1959");
    Person cygnusBlackSr("Cygnus", "Black Sr.", "1889", "1943", "Violettea Bulstrode");
    Person polluxBlack("Pollux", "Black", "1912", "1990", "Irma Crabbe");
    Person cassiopeiaBlack("Cassiopeia", "Black", "1915", "1992");
    Person doreaBlack("Dorea", "Black", "1920", "1977", "Charlus Potter");
    Person belvinaBlack("Belvina", "Black", "1886", "1962", "Lysandra Yaxley");
    Person callidoraBlack("Callidora", "Black", "1915", "0", "Harfang Longbottom");
    Person charisBlack("Charis", "Black", "1919", "1973", "Caspar Crouch");
    Person arcturusBlackSr("Arcturus", "Black Sr.", "1884", "1989", "Lysandra Yaaxley");
 
    //family tree
    FamilyMember<Person> root(PhineusNigellus);
    root.addChild(Sirius);
    root.addChild(cygnusBlackSr);
    root.addChild(belvinaBlack);
    root.addChild(arcturusBlackSr);

    FamilyMember<Person>* siriusNode = root.getChildren()[0];
    siriusNode->addChild(arcturusBlackJr);
    siriusNode->addChild(lycorisBlack);
    siriusNode->addChild(regulusBlackSr);

    FamilyMember<Person>* cygnusNode = root.getChildren()[1];
    cygnusNode->addChild(polluxBlack);
    cygnusNode->addChild(cassiopeiaBlack);
    cygnusNode->addChild(doreaBlack);

    FamilyMember<Person>* belvinaNode = root.getChildren()[2];
    
    
    FamilyMember<Person>* arcturusNode = root.getChildren()[3];
    arcturusNode->addChild(callidoraBlack);
    arcturusNode->addChild(charisBlack);

    // Traverse the family tree in preorder
    FamilyTreeTraversal<Person>::preorderTraversal(&root,theLevel);

    // Search for a person in the family tree
    string firstName;
    cout << endl << "Enter a first name in the Black Family Tree: ";
    cin >> firstName;

    vector<FamilyMember<Person>*> foundNodes;
    FamilyTreeTraversal<Person>::search(&root, firstName, foundNodes);
if (!foundNodes.empty()) {
    
    
    cout << endl << "Found the following family members:" << endl;
    cout << endl <<"----------------------------------------" ;
    for (FamilyMember<Person>* foundNode : foundNodes) {
        cout << endl ;
        cout << foundNode->getData().toString() << endl;
        
        if (!foundNode->getChildren().empty()) {
            cout << "Children of " << firstName << " "<< foundNode->getData().getLast() <<":" << endl << endl;
            for (FamilyMember<Person>* child : foundNode->getChildren()) {
                cout << "--" << child->getData().toString() << endl;
            }
        }
        cout << endl <<"------------------------------------" << endl;
    }
} else {
    cout << firstName << " not found in the family tree." << endl;
}


    
    return 0;
}


