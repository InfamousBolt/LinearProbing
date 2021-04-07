#include<iostream>
#include<cstdlib>
using namespace std;
struct slot{
    int key;
    int value;
};

struct hashtable_slot{
    int flag;
    struct slot* record;
};

struct hashtable_slot* arr;
int size=0;
int maxCap=10;

void initialize(){
    for(int i=0;i<maxCap;i++){
        arr[i].flag=0;
        arr[i].record=NULL;
    }
}

void insert(int key, int value){
    int index = key%maxCap;
    int i=index;
    struct slot* item=(struct slot*)malloc(sizeof(struct slot));
    item->key=key;
    item->value=value;
    while(arr[i].flag==1){
        if(arr[i].record->key==key){
            cout<<"Duplicate keys not allowed\n";
            return;
        }
        i=(i+1)%maxCap;
        if(i==index){
            cout<<"Hashtable full. Cannot insert\n";
            return;
        }
    }
    arr[i].flag=1;
    arr[i].record=item;
    size++;
}

int search(int key){
    int index=key%maxCap;
    int i=index;
    while(arr[i].flag!=0){
        if(arr[i].record->key==key)
            return 1;
        i=(i+1)%maxCap;
        if(i==index)
            return 0;
    }
    return 0;
}

void display(){
    for(int i=0;i<maxCap;i++){
        struct slot* temp=(struct slot*)arr[i].record;
        if(temp==NULL)
            cout<<"HashtableSlot["<<i<<"] has no elements\n";
        else{
            cout<<"HashtableSlot["<<i<<"] has element:\n";
            cout<<"Key: "<<temp->key<<" Value: "<<temp->value<<endl;
        }
    }
}

int main(){
    arr=(struct hashtable_slot*)malloc(maxCap * sizeof(struct hashtable_slot));
    initialize();
    int key,value;
    for(int i=0;i<6;i++){
        cin>>key>>value;
        insert(key,value);
    }
    display();
    if(search(36))
        cout<<"Key is present"<<endl;
    else
        cout<<"Key is not present"<<endl;
    return 0;
}