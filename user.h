#ifndef USER_H // Header guard untuk mencegah pengulangan saat header di-include lebih dari sekali
#define USER_H // Deklarasi awal dari header file user.h

#include <QMainWindow> // Termasuk header file untuk QMainWindow
#include "linkedList.h" // Termasuk header file untuk LinkedList

QT_BEGIN_NAMESPACE
namespace Ui { class User; } // Mendeklarasikan namespace Ui untuk kelas User
QT_END_NAMESPACE

class User : public QMainWindow // Deklarasi kelas User yang merupakan turunan dari QMainWindow
{
    Q_OBJECT // Macro yang memungkinkan class memiliki metode slot

public:
    explicit User(LinkedList* sharedList, QWidget *parent = nullptr); // Modifikasi konstruktor untuk menerima sharedList
    ~User(); // Destruktor User

private slots: // Deklarasi slot kelas User
    void search(); // Deklarasi metode slot untuk melakukan pencarian

private:
    Ui::User *ui; // Pointer ke antarmuka pengguna (UI) User
    LinkedList *linkedList; // Pointer ke objek LinkedList untuk menyimpan data
};

#endif // USER_H // Akhir dari header file user.h dan penutup dari header guard
