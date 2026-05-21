#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

enum class ContactType {
    FRIEND,
    ACQUAINTANCE,
    COLLEAGUE
};

class Contact {
protected:
    std::string name;
    ContactType type;

public:
    Contact(std::string n, ContactType t) : name(n), type(t) {}
    virtual ~Contact() = default;

    std::string getName() const { return name; }
    ContactType getType() const { return type; }

    virtual void displayInfo() const = 0;
};

class Friend : public Contact {
private:
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string address;

public:
    Friend(std::string n, std::string dob, std::string phone, std::string addr)
        : Contact(n, ContactType::FRIEND), dateOfBirth(dob), phoneNumber(phone), address(addr) {
    }

    void displayInfo() const override {
        std::cout << "[Prieten] Nume: " << name << ", Data Nasterii: " << dateOfBirth
            << ", Telefon: " << phoneNumber << ", Adresa: " << address << "\n";
    }
};

class Acquaintance : public Contact {
private:
    std::string phoneNumber;

public:
    Acquaintance(std::string n, std::string phone)
        : Contact(n, ContactType::ACQUAINTANCE), phoneNumber(phone) {
    }

    void displayInfo() const override {
        std::cout << "[Cunostinta] Nume: " << name << ", Telefon: " << phoneNumber << "\n";
    }
};

class Colleague : public Contact {
private:
    std::string phoneNumber;
    std::string company;
    std::string address;

public:
    Colleague(std::string n, std::string phone, std::string comp, std::string addr)
        : Contact(n, ContactType::COLLEAGUE), phoneNumber(phone), company(comp), address(addr) {
    }

    void displayInfo() const override {
        std::cout << "[Coleg] Nume: " << name << ", Telefon: " << phoneNumber
            << ", Companie: " << company << ", Adresa: " << address << "\n";
    }
};

class AddressBook {
private:
    std::vector<std::shared_ptr<Contact>> contacts;

public:
    void addContact(std::shared_ptr<Contact> contact) {
        contacts.push_back(contact);
        std::cout << "Adaugat: " << contact->getName() << "\n";
    }

    std::shared_ptr<Contact> searchByName(const std::string& searchName) const {
        for (const auto& contact : contacts) {
            if (contact->getName() == searchName) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Friend>> getFriends() const {
        std::vector<std::shared_ptr<Friend>> friendsList;
        for (const auto& contact : contacts) {
            if (contact->getType() == ContactType::FRIEND) {
                friendsList.push_back(std::dynamic_pointer_cast<Friend>(contact));
            }
        }
        return friendsList;
    }

    void deleteContact(const std::string& searchName) {
        auto it = std::remove_if(contacts.begin(), contacts.end(),
            [&searchName](const std::shared_ptr<Contact>& c) {
                return c->getName() == searchName;
            });

        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            std::cout << "Sters contactul: " << searchName << "\n";
        }
        else {
            std::cout << "Contactul " << searchName << " nu a fost gasit.\n";
        }
    }

    void displayAll() const {
        std::cout << "\nContinut Agenda";
        for (const auto& contact : contacts) {
            contact->displayInfo();
        }
        std::cout<<" ";
    }
};

int main() {
    AddressBook agenda;

    agenda.addContact(std::make_shared<Friend>("Andrei", "12-05-1999", "0722123456", "Str. Florilor"));
    agenda.addContact(std::make_shared<Colleague>("Mihai", "0744987654", "IT Corp", "Bd. Unirii"));
    agenda.addContact(std::make_shared<Acquaintance>("Elena", "0766111222"));
    agenda.addContact(std::make_shared<Friend>("Diana", "08-11-1998", "0788333444", "Aleea Rozelor"));

    agenda.displayAll();

    std::string deCautat = "Mihai";
    std::cout << "\nCautam pe " << deCautat << "...\n";
    auto gasit = agenda.searchByName(deCautat);
    if (gasit) {
        std::cout << "Gasit: ";
        gasit->displayInfo();
    }
    else {
        std::cout << "Nu a fost gasit.\n";
    }

    std::cout << "\nLista doar cu Prieteni:\n";
    auto prieteni = agenda.getFriends();
    for (const auto& f : prieteni) {
        f->displayInfo();
    }

    std::cout << "\n";
    agenda.deleteContact("Elena");

    agenda.displayAll();

    return 0;
}