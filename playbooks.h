#ifndef PLAYBOOKS_H // Header guard untuk mencegah pengulangan saat header di-include lebih dari sekali
#define PLAYBOOKS_H // Deklarasi awal dari header file playbooks.h

#include <QMainWindow> // Termasuk header file untuk QMainWindow
#include <QLineEdit> // Termasuk header file untuk QLineEdit
#include <QPushButton> // Termasuk header file untuk QPushButton
#include <QMessageBox> // Termasuk header file untuk QMessageBox

QT_BEGIN_NAMESPACE
namespace Ui { class Playbooks; } // Mendeklarasikan namespace Ui untuk kelas Playbooks
QT_END_NAMESPACE

class Playbooks : public QMainWindow { // Deklarasi kelas Playbooks yang merupakan turunan dari QMainWindow
    Q_OBJECT // Macro yang memungkinkan class memiliki metode slot

public:
    explicit Playbooks(QWidget *parent = nullptr); // Konstruktor Playbooks dengan parameter default nullptr
    ~Playbooks(); // Destruktor Playbooks

signals:
    void adminLogin();
    void userLogin();
private slots: // Deklarasi slot kelas Playbooks
    void onLoginButtonClicked(); // Deklarasi metode slot untuk menangani klik tombol login

private:
    Ui::Playbooks *ui; // Pointer ke antarmuka pengguna (UI) Playbooks

    class UserList { // Deklarasi kelas internal UserList untuk menyimpan daftar pengguna
    private:
        struct Node { // Struktur Node untuk menyimpan informasi pengguna
            QString username; // Username pengguna
            QString password; // Password pengguna
            Node* next; // Pointer ke Node selanjutnya dalam linked list

            Node(const QString& user, const QString& pass, Node* n = nullptr) // Konstruktor Node untuk menginisialisasi Node baru
                : username(user), password(pass), next(n) {}
        };

        Node* head; // Pointer ke Node pertama dalam linked list

    public:
        UserList() : head(nullptr) {} // Konstruktor UserList untuk menginisialisasi head sebagai nullptr

        ~UserList() { // Destruktor UserList untuk menghapus semua node dalam linked list
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void insert(const QString& username, const QString& password) { // Metode untuk menyisipkan pengguna baru ke dalam linked list
            Node* newNode = new Node(username, password);
            newNode->next = head;
            head = newNode;
        }

        bool find(const QString& username, const QString& password) const { // Metode untuk mencari pengguna dalam linked list berdasarkan username dan password
            Node* current = head;
            while (current) {
                if (current->username == username && current->password == password) {
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    } userList; // Deklarasi userList sebagai instance dari kelas UserList
};

#endif // PLAYBOOKS_H // Akhir dari header file playbooks.h dan penutup dari header guard
