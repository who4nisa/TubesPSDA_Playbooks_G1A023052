#include <QApplication> // Termasuk header file untuk mengakses kelas QApplication yang menyediakan fungsionalitas aplikasi Qt
#include "playbooks.h" // Termasuk header file untuk kelas Playbooks yang merupakan antarmuka utama aplikasi
#include "user.h" // Termasuk header file untuk kelas User yang mungkin digunakan dalam aplikasi
#include "admin.h" // Termasuk header file untuk kelas Admin yang mungkin digunakan dalam aplikasi
#include "linkedlist.h"

int main(int argc, char *argv[]) { // Fungsi utama aplikasi
    QApplication app(argc, argv); // Membuat objek aplikasi Qt

    LinkedList sharedList; // Membuat satu instansi sharedList yang digunakan oleh Admin dan User


    Playbooks playbooks; // Membuat objek Playbooks untuk antarmuka utama
    playbooks.show(); // Menampilkan antarmuka utama

    QObject::connect(&playbooks, &Playbooks::adminLogin, [&sharedList]() {
        Admin *adminWindow = new Admin(&sharedList);
        adminWindow->show();
    });

    QObject::connect(&playbooks, &Playbooks::userLogin, [&sharedList]() {
        User *userWindow = new User(&sharedList);
        userWindow->show();
    });

    return app.exec(); // Menjalankan event loop aplikasi dan mengembalikan nilai setelah aplikasi selesai
}
