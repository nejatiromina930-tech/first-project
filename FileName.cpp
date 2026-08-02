#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

/* ---------- Validation Functions ---------- */

bool isOnlyDigits(const string& s) {
    for (char c : s)
        if (!isdigit(c)) return false;
    return true;
}

bool validCodeMelli(const string& code) {
    return code.length() == 10 && isOnlyDigits(code);
}

bool validAccountNumber(const string& acc) {
    return acc.length() == 8 && isOnlyDigits(acc);
}

bool positive(double x) {
    return x > 0;
}

/* ---------- Account Base Class ---------- */

class Account {
protected:
    string shomareHesab;
    string saheb;
    double mojoudi;

public:
    Account(string sh, string s, double m)
        : shomareHesab(sh), saheb(s), mojoudi(m) {
    }

    virtual ~Account() {}

    string getShomare() const { return shomareHesab; }
    double getMojoudi() const { return mojoudi; }

    virtual void variz(double m) {
        if (positive(m))
            mojoudi += m;
    }

    virtual bool bardasht(double m) {
        if (positive(m) && m <= mojoudi) {
            mojoudi -= m;
            return true;
        }
        return false;
    }

    virtual void show() const {
        cout << "Shomare Hesab: " << shomareHesab << endl;
        cout << "Saheb: " << saheb << endl;
        cout << "Mojoudi: " << mojoudi << endl;
    }

    virtual string type() const {
        return "Normal";
    }
};

/* ---------- Saving Account ---------- */

class SavingAccount : public Account {
    double sood;

public:
    SavingAccount(string sh, string s, double m, double so)
        : Account(sh, s, m), sood(so) {
    }

    void ezafeSood() {
        mojoudi += mojoudi * sood;
    }

    void show() const override {
        Account::show();
        cout << "Noe: Saving\n";
        cout << "Nerkh Sood: " << sood << endl;
    }

    string type() const override {
        return "Saving";
    }
};

/* ---------- Credit Account ---------- */

class CreditAccount : public Account {
    double sood;
    int aghsat;
    double mablaghVam;

public:
    CreditAccount(string sh, string s, double m, double so, int a, double v)
        : Account(sh, s, m), sood(so), aghsat(a), mablaghVam(v) {
    }

    double ghestMahane() const {
        return (mablaghVam + mablaghVam * sood) / aghsat;
    }

    void show() const override {
        Account::show();
        cout << "Noe: Credit\n";
        cout << "Mablagh Vam: " << mablaghVam << endl;
        cout << "Tedad Aghsat: " << aghsat << endl;
        cout << "Ghest Mahane: " << ghestMahane() << endl;
    }

    string type() const override {
        return "Credit";
    }
};

/* ---------- Customer Class ---------- */

class customer {
public:
    string codeMelli;
    string name;
    vector<Account*> hesabha;

    customer(string c, string n) : codeMelli(c), name(n) {}

    ~customer() {
        for (auto h : hesabha)
            delete h;
    }

    void addAccount(Account* a) {
        hesabha.push_back(a);
    }

    void showAccounts() const {
        cout << "\nCustomer: " << name << endl;
        for (auto h : hesabha) {
            h->show();
            cout << "-----------------\n";
        }
    }
};

/* ---------- Bank Class ---------- */

class Bank {
    string name;
    vector<customer*> customers;

public:
    Bank(string n) : name(n) {}

    ~Bank() {
        saveToFile("bank_data.txt");
        for (auto c : customers)
            delete c;
    }

    bool accountExists(const string& sh) const {
        for (auto c : customers)
            for (auto h : c->hesabha)
                if (h->getShomare() == sh)
                    return true;
        return false;
    }

    void addCustomer(customer* c) {
        customers.push_back(c);
    }

    void showAll() const {
        for (auto c : customers)
            c->showAccounts();
    }

    /* ---------- Auto Save ---------- */
    void saveToFile(const string& filename) {
        ofstream out(filename);
        for (auto c : customers) {
            out << "Customer " << c->codeMelli << " " << c->name << endl;
            for (auto h : c->hesabha) {
                out << "Account " << h->type() << " "
                    << h->getShomare() << " "
                    << h->getMojoudi() << endl;
            }
        }
        out.close();
    }

    /* ---------- Auto Load ---------- */
    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in) return;

        string word;
        while (in >> word) {
            if (word == "Customer") {
                string code, name;
                in >> code >> name;
                customer* c = new customer(code, name);
                customers.push_back(c);
            }
            else if (word == "Account") {
                string type, sh;
                double moj;
                in >> type >> sh >> moj;
                customers.back()->addAccount(
                    new Account(sh, customers.back()->name, moj)
                );
            }
        }
        in.close();
    }
};

/* ---------- Main ---------- */

int main() {
    Bank bank("MyBank");

    // Auto Load
    bank.loadFromFile("bank_data.txt");

    cout << "Bank System Started (Auto Load Enabled)\n";

    // نمونه تست
    customer* c1 = new customer("1234567890", "Ali");
    c1->addAccount(new Account("12345678", "Ali", 1000));
    bank.addCustomer(c1);

    bank.showAll();

    cout << "Program Finished (Auto Save Enabled)\n";
    return 0;
}
