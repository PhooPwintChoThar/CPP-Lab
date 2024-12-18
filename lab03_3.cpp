#include<iostream>
#include<list>

using namespace std;


list<int> mergeLists(const list<int>& list1, const list<int>& list2){
    list<int> result;
    auto it1=list1.begin();
    auto it2=list2.begin();

    while(it1 != list1.end() && it2!=list2.end()){
        if (*it1 <*it2){
            result.push_back(*it1);
            ++it1;
        }else{
            result.push_back(*it2);
            ++it2;
        }
    }

    while(it1 != list1.end()){
        result.push_back(*it1++);
    }

    while(it2 != list2.end()){
        result.push_back(*it2++);
    }

    return result;
}

int main(){
    list<int> list1={1,3,5,7};
    list<int> list2={2,4,6,8};
    list<int> mergedList= mergeLists(list1, list2);

    cout<<"Merged List";
    for(int item: mergedList){
        cout<<item;
    }
}