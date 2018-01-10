#include "SurveyClass.h"
#include <map>
#include <string>
#include <iterator>

using namespace std;

SurveyClass::SurveyClass() {
    members = new LinkedList();
}

SurveyClass::SurveyClass(const SurveyClass &other) {
    if(other.members)
        this -> members = new LinkedList(*(other.members));
}

SurveyClass &SurveyClass::operator=(const SurveyClass &list) {

    if(this -> members)
        delete this -> members;

    if(list.members)
        this -> members = new LinkedList(*list.members);

    return *this;
}

SurveyClass::~SurveyClass() {
    if(members)
        delete members;
    members = 0;
}

void SurveyClass::addMember(const Member &newMember) {
    members -> pushTail(newMember);
}

float SurveyClass::calculateAverageAge() {
    int sum = 0;

    Node *curr = members -> head;

    while (curr != 0){
        sum += curr -> data.age;
        curr = curr -> next;
    }

    int average = (int) (((float) sum / (float) members -> length) * 1000);

    int lastDigit = average % 10;
    int lastSecondDigit = (int) (average / 10) % 10;

    if(lastDigit > 5){
        average = (average / 10 + 1 ) * 10;
    }else if(lastDigit < 5){
        average = (average / 10) * 10;
    }else{
        if(lastSecondDigit % 2 == 0){
            average = (average / 10) * 10;
        }else{
            average = (average / 10 + 1 ) * 10;
        }
    }



    return (float)average / 1000.0 ;
}

string SurveyClass::findMostFavouriteColor() {

    map<string, int> colorMap;

    Node *curr = members -> head;

    while (curr != 0){

        if(colorMap.find(curr -> data.color) == colorMap.end()){
            colorMap[curr -> data.color] = 1;
        }else {
            colorMap[curr -> data.color]++;
        }
        curr = curr -> next;
    }

    map<string, int>::iterator it = colorMap.begin();

    string mostFrequentColor = it -> first;

    int maxFrequence = it -> second;

    it++;

    while(it != colorMap.end()){
        if(it -> second > maxFrequence)
            mostFrequentColor = it -> first;
        it++;
    }

    return mostFrequentColor;
}
