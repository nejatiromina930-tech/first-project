import csv


class Contact:
    def __init__(self, name, phone):
        if not phone.isdigit():
            raise ValueError("Phone number bayad faghat adad bashad")
        self.name = name
        self.phone = phone

    def show(self):
        print(self.name, "-", self.phone)


class PhoneBook:
    def __init__(self):
        self.list = []

    def add(self, name, phone):
        try:
            c = Contact(name, phone)
            self.list.append(c)
            print("Contact add shod")
        except ValueError:
            print("Phone eshtebah ast, dobare talash kon")

    def save(self):
        f = open("contacts.csv", "w", newline="")
        w = csv.writer(f)
        w.writerow(["name", "phone"])
        for c in self.list:
            w.writerow([c.name, c.phone])
        f.close()
        print("Contacts save shod")

    def load(self):
        try:
            f = open("contacts.csv", "r")
            r = csv.DictReader(f)
            for row in r:
                try:
                    c = Contact(row["name"], row["phone"])
                    self.list.append(c)
                except ValueError:
                    pass
            f.close()
            print("Contacts load shod")
        except FileNotFoundError:
            print("File nist, phonebook jadid sakhte shod")

    def show_all(self):
        if len(self.list) == 0:
            print("Hich contacti nist")
        for c in self.list:
            c.show()



pb = PhoneBook()
pb.load()

while True:
    print("\n1. Add contact")
    print("2. Show all")
    print("3. Save & Exit")

    try:
        ch = int(input("Select: "))
    except ValueError:
        print("Lotfan adad vared kon")
        continue

    if ch == 1:
        n = input("Name: ")
        p = input("Phone: ")
        pb.add(n, p)

    elif ch == 2:
        pb.show_all()

    elif ch == 3:
        pb.save()
        print("Exit...")
        break

    else:
        print("Option eshtebah ast")

