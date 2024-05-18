#ifndef ADMIN_H // Header guard untuk mencegah pengulangan saat header di-include lebih dari sekali
#define ADMIN_H // Deklarasi awal dari header file admin.h

#include <QMainWindow> // Termasuk header file untuk QMainWindow
#include <QStandardItemModel> // Termasuk header file untuk QStandardItemModel
#include "linkedlist.h" // Termasuk header file untuk kelas LinkedList

QT_BEGIN_NAMESPACE
namespace Ui { class Admin; } // Deklarasi namespace Ui untuk kelas Admin
QT_END_NAMESPACE

class Admin : public QMainWindow // Deklarasi kelas Admin yang merupakan turunan dari QMainWindow
{
    Q_OBJECT // Macro untuk memungkinkan kelas Admin berkomunikasi dengan sinyal dan slot Qt

public:
    explicit Admin(LinkedList* sharedList, QWidget *parent = nullptr); // Modifikasi konstruktor untuk menerima sharedList
    ~Admin(); // Destruktor Admin

private slots: // Deklarasi slot untuk menangani sinyal yang dikirimkan oleh antarmuka pengguna
    void createBuku(); // Metode untuk membuat buku baru
    void readBuku(); // Metode untuk membaca data buku
    void updateBuku(); // Metode untuk memperbarui informasi buku
    void deleteBuku(); // Metode untuk menghapus buku

private:
    Ui::Admin *ui; // Antarmuka pengguna untuk kelas Admin
    LinkedList *linkedList; // Objek linked list untuk menyimpan data buku
    QStandardItemModel *model; // Objek model untuk menampilkan data buku dalam QTableView
};

#endif // ADMIN_H // Akhir dari header file admin.h dan penutup dari header guard
