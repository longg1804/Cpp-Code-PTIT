#include <bits/stdc++.h>
using namespace std;

// Cấu trúc tài khoản ngân hàng
struct Account {
    string cardNumber;
    string pin;
    string name;
    double balance;
};

// Danh sách tài khoản (trong thực tế sẽ kết nối với CSDL)
vector<Account> accounts = {
    {"123456789", "1234", "Nguyen Van A", 5000000},
    {"987654321", "4321", "Tran Thi B", 3000000},
    {"456789123", "1111", "Le Van C", 10000000}
};

// Biến toàn cục lưu tài khoản hiện tại
Account* currentAccount = nullptr;

// Hàm đăng nhập
bool login() {
    string cardNumber, pin;
    cout << "\n======== DANG NHAP ATM ========\n";
    cout << "Nhap so the: ";
    cin >> cardNumber;
    cout << "Nhap ma PIN: ";
    cin >> pin;

    for (auto &acc : accounts) {
        if (acc.cardNumber == cardNumber && acc.pin == pin) {
            currentAccount = &acc;
            cout << "\nDang nhap thanh cong! Chao mung " << acc.name << "!\n";
            return true;
        }
    }

    cout << "\nSo the hoac ma PIN khong dung. Vui long thu lai!\n";
    return false;
}

// Hàm hiển thị menu chính
void showMainMenu() {
    cout << "\n======== MENU CHINH ========\n";
    cout << "1. Xem so du tai khoan\n";
    cout << "2. Rut tien\n";
    cout << "3. Chuyen khoan\n";
    cout << "4. In bien lai\n";
    cout << "5. Thoat\n";
    cout << "Chon chuc nang (1-5): ";
}

// Hàm xem số dư
void checkBalance() {
    cout << "\nSo du tai khoan cua ban: " << fixed << setprecision(0) << currentAccount->balance << " VND\n";
}

// Hàm rút tiền
void withdraw() {
    double amount;
    cout << "\nNhap so tien muon rut: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "So tien rut phai lon hon 0!\n";
        return;
    }

    if (amount > currentAccount->balance) {
        cout << "So du tai khoan khong du!\n";
        return;
    }

    if ((int)amount % 50000 != 0) {
        cout << "So tien rut phai la boi so cua 50,000 VND!\n";
        return;
    }

    currentAccount->balance -= amount;
    cout << "Rut tien thanh cong! So du con lai: " << fixed << setprecision(0) << currentAccount->balance << " VND\n";
}

// Hàm chuyển khoản
void transfer() {
    string targetCard;
    double amount;
    
    cout << "\nNhap so the nhan: ";
    cin >> targetCard;
    
    // Kiểm tra không được chuyển cho chính mình
    if (targetCard == currentAccount->cardNumber) {
        cout << "Khong the chuyen khoan cho chinh minh!\n";
        return;
    }
    
    // Tìm tài khoản đích
    Account* targetAccount = nullptr;
    for (auto &acc : accounts) {
        if (acc.cardNumber == targetCard) {
            targetAccount = &acc;
            break;
        }
    }
    
    if (targetAccount == nullptr) {
        cout << "So the nhan khong ton tai!\n";
        return;
    }
    
    cout << "Ten tai khoan nhan: " << targetAccount->name << endl;
    cout << "Nhap so tien chuyen: ";
    cin >> amount;
    
    if (amount <= 0) {
        cout << "So tien chuyen phai lon hon 0!\n";
        return;
    }
    
    if (amount > currentAccount->balance) {
        cout << "So du tai khoan khong du!\n";
        return;
    }
    
    // Thực hiện chuyển khoản
    currentAccount->balance -= amount;
    targetAccount->balance += amount;
    
    cout << "Chuyen khoan thanh cong!\n";
    cout << "So du con lai: " << fixed << setprecision(0) << currentAccount->balance << " VND\n";
}

// Hàm in biên lai
void printReceipt() {
    time_t now = time(0);
    char* dt = ctime(&now);
    
    cout << "\n======== BIEN LAI GIAO DICH ========\n";
    cout << "NGAN HANG ABC\n";
    cout << "Thoi gian: " << dt;
    cout << "So the: " << currentAccount->cardNumber << endl;
    cout << "Ten KH: " << currentAccount->name << endl;
    cout << "So du: " << fixed << setprecision(0) << currentAccount->balance << " VND\n";
    cout << "Cam on quy khach da su dung dich vu!\n";
    cout << "===================================\n";
}

int main() {
    // Thiết lập hiển thị tiền tệ
    cout << fixed << setprecision(0);
    
    while (true) {
        if (currentAccount == nullptr) {
            if (!login()) {
                continue;
            }
        }
        
        showMainMenu();
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                transfer();
                break;
            case 4:
                printReceipt();
                break;
            case 5:
                cout << "\nCam on ban da su dung dich vu ATM. Hen gap lai!\n";
                currentAccount = nullptr;
                return 0;
            default:
                cout << "\nLua chon khong hop le. Vui long chon lai!\n";
        }
    }
    
    return 0;
}
