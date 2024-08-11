#include <iostream>
#include <string>

// Subject interface
class BankAccount {
public:
    virtual void deposit(int amount) = 0;
    virtual void withdraw(int amount) = 0;
    virtual void checkBalance() = 0;
};

// RealObject class
class RealBankAccount : public BankAccount {
private:
    std::string accountNumber;
    int balance;
public:
    RealBankAccount(std::string accountNumber, int balance) : accountNumber(accountNumber), balance(balance) {}
    void deposit(int amount) {
        balance += amount;
        std::cout << "Deposited " << amount << std::endl;
    }
    void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew " << amount << std::endl;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }
    void checkBalance() {
        std::cout << "Balance: " << balance << std::endl;
    }
};

// Proxy class
class BankAccountProxy : public BankAccount {
private:
    RealBankAccount* realAccount;
public:
    BankAccountProxy(RealBankAccount* realAccount) : realAccount(realAccount) {}
    void deposit(int amount) {
        realAccount->deposit(amount);
    }
    void withdraw(int amount) {
        if (amount <= 1000) {
            realAccount->withdraw(amount);
        } else {
            std::cout << "Withdrawal amount exceeds limit" << std::endl;
        }
    }
    void checkBalance() {
        realAccount->checkBalance();
    }
};

int main() {
    RealBankAccount* account = new RealBankAccount("1234567890", 1000);
    BankAccountProxy* proxy = new BankAccountProxy(account);
    proxy->deposit(500);
    proxy->withdraw(200);
    proxy->checkBalance();
    proxy->withdraw(1500); // Exceeds limit
    delete account;
    delete proxy;
    return 0;
}