#include <iostream>
using namespace std;
//display array elements

void displayArray(int arr[],int size){
    if(size==0){
        cout<<"Array is empty"<<endl;
        return;
    }
    cout<<"Array elements are :"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" " ;
        cout<<endl;
    }
}
void insertAtEnd(int arr[],int size,int element){
    arr[size]=element;
    cout<<"Element "<<element<<" inserted at the end."<<endl;
}
void deleteAtEnd(int arr[],int &size){
    if(size==0){
        cout<<"Array is empty. Cannot delete element."<<endl;
        return;
    }
    size--;
    cout<<"Element at the end deleted."<<endl;
}
void InsertatPos(int arr[],int &size,int pos,int element){
    if (pos<0||pos>size){
        cout<<"Invalid position"<<endl;
        return;
    }
    for(int i=size;i>pos;i--){
        arr[i]=arr[i-1];
        arr[pos]=element;
        size++;
    }
}
void deleteAtPos(int arr[],int &size,int pos){
    if(size==0){
        cout<<"Array is empty. Cannot delete element."<<endl;
        return;
    }
    if(pos<0||pos>=size){
        cout<<"Invalid position"<<endl;
        return;
    }
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    cout<<"Element at position "<<pos<<" deleted."<<endl;
}
int searchElement(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
int updateElement(int arr[],int size, int oldElement,int newElement){
    int index=searchElement(arr,size,oldElement);
    if(index!=-1){
        arr[index]=newElement;
        cout<<"Element "<<oldElement<<" updated to "<<newElement<<endl;
        return index;
    }
    else{
        cout<<"Element "<<oldElement<<" not found in the array."<<endl;
        return -1;
    }
}
int main() {
    const int MAX_SIZE=100;
    int arr[MAX_SIZE];
    int size=0;
    
    while(true){
        cout<<"Menu:"<<endl;
        cout<<"1. Display Array"<<endl;
        cout<<"2. Insert at End"<<endl;
        cout<<"3. Delete at End"<<endl;
        cout<<"4. Insert at Position"<<endl;
        cout<<"5. Delete at Position"<<endl;
        cout<<"6. Search Element"<<endl;
        cout<<"7. Update Element"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                displayArray(arr,size);
                break;
            case 2:{
                int element;
                cout<<"Enter element to insert at end: ";
                cin>>element;
                insertAtEnd(arr,size,element);
                size++;
                break;
            }
            case 3:{
                deleteAtEnd(arr,size);
                break;}
            case 4:{
                int pos,element;
                cout<<"Enter position to insert element: ";
                cin>>pos;
                cout<<"Enter element to insert: ";
                cin>>element;
                InsertatPos(arr,size,pos,element);
                break;
            }
            case 5:{
                int pos;
                cout<<"Enter position to delete element: ";
                cin>>pos;
                deleteAtPos(arr,size,pos);
                break;
            }
            case 6:{
                int element;
                cout<<"Enter element to search: ";
                cin>>element;
                int index=searchElement(arr,size,element);
                if(index!=-1){
                    cout<<"Element "<<element<<" found at index "<<index<<endl;
                }
                else{
                    cout<<"Element "<<element<<" not found in the array."<<endl;
                }
                break;
            }
            case 7:{
                int oldElement,newElement;
                cout<<"Enter element to update: ";
                cin>>oldElement;
                cout<<"Enter new element: ";
                cin>>newElement;
                updateElement(arr,size,oldElement,newElement);
                break;
            }
            case 8:
                cout<<"Exiting program."<<endl;
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}
    
    
    
    
    
