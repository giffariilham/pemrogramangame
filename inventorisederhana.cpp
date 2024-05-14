#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    // Daftar item yang tersedia
    vector<string> availableItems {"knife", "apple", "book", "gloves", "gun", "lamp", "map", "ammo", "umbrella", "watch"};

    vector<string> inventory; // Inventori awalnya kosong
    char choice = ' ';
    srand(time(0)); // Inisialisasi generator angka acak dengan waktu saat ini

    while(choice != '4') {
        cout << "\nMenu: " << endl;
        cout << "1. Display inventory"<< endl; // Menampilkan inventori
        cout << "2. Add item" << endl; // Menambahkan item
        cout << "3. Remove item" << endl; // Menghapus item
        cout << "4. Exit" << endl; // Keluar
        cout << "Your choice (1/2/3/4): ";
        cin >> choice;

        switch(choice) {
            case '1':
                // Menampilkan inventori
                cout << "\nYour Inventory:" << endl;
                if (inventory.empty()) {
                    cout << "Your inventory is empty." << endl; // Inventori Anda kosong
                } else {
                    for(const string& item : inventory) {
                        cout << item << endl;
                    }
                }
                break;
            case '2': {
                // Menambahkan item
                if (!availableItems.empty()) {
                    int randomIndex = rand() % availableItems.size();
                    string newItem = availableItems[randomIndex];
                    
                    // Memeriksa apakah item sudah ada di inventori
                    if (std::find(inventory.begin(), inventory.end(), newItem) != inventory.end()) {
                        cout << "You already have this item in your inventory." << endl; // Anda sudah memiliki item ini di inventori
                    } else {
                        inventory.push_back(newItem);
                        cout << "You obtained: " << newItem << endl; // Anda mendapatkan
                        cout << "Item successfully added to inventory." << endl; // Item berhasil ditambahkan ke inventori
                        
                        // Menghapus item dari availableItems
                        availableItems.erase(availableItems.begin() + randomIndex);
                    }
                } else {
                    cout << "No items available to add." << endl; // Tidak ada item tersedia untuk ditambahkan
                }
                break;
            }
            case '3': {
                // Menghapus item
                if (inventory.empty()) {
                    cout << "Your inventory is already empty." << endl; // Inventori Anda sudah kosong
                } else {
                    string itemToDelete;
                    cout << "\nEnter the item you want to remove: ";
                    cin >> itemToDelete;
                    auto it = find(inventory.begin(), inventory.end(), itemToDelete);
                    if(it != inventory.end()) {
                        inventory.erase(it);
                        cout << "Item successfully removed from inventory." << endl; // Item berhasil dihapus dari inventori
                        
                        // Menambahkan item kembali ke availableItems
                        availableItems.push_back(itemToDelete);
                    } else {
                        cout << "Item not found in inventory." << endl; // Item tidak ditemukan dalam inventori
                    }
                }
                break;
            }
            case '4':
                // Keluar dari program
                cout << "Thank you for using this program. See you next time!" << endl; // Terima kasih telah menggunakan program ini. Selamat tinggal!
                break;
            default:
                // Pilihan tidak valid
                cout << "Invalid choice. Please choose." << endl; // Pilihan tidak valid. Silakan pilih 1, 2, 3, atau 4.
        }
    }

    return 0;
}
