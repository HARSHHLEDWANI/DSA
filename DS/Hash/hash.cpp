#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> hashMap;
    int choice;
    string key;
    int value;

    while(true){
        cout << "Menu:" << endl;
        cout << "1. Insert/Update Key-Value Pair" << endl;
        cout << "2. Delete Key" << endl;
        cout << "3. Search Key" << endl;
        cout << "4. Display All Key-Value Pairs" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                hashMap[key] = value;
                cout << "Key-Value pair (" << key << ", " << value << ") inserted/updated." << endl;
                break;

            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                if(hashMap.erase(key)){
                    cout << "Key " << key << " deleted." << endl;
                }else{
                    cout << "Key " << key << " not found." << endl;
                }
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if(hashMap.find(key) != hashMap.end()){
                    cout << "Key " << key << " found with value " << hashMap[key] << "." << endl;
                }else{
                    cout << "Key " << key << " not found." << endl;
                }
                break;
            case 4:
                cout << "Key-Value Pairs in Hash Map:" << endl;
                for(const auto& pair : hashMap){
                    cout << pair.first << ": " << pair.second << endl;
                }
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}