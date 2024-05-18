#ifndef LINKEDLIST_H // Header guard untuk mencegah pengulangan saat header di-include lebih dari sekali
#define LINKEDLIST_H // Deklarasi awal dari header file linkedlist.h

#include <QString> // Termasuk header file untuk QString

struct Node { // Struktur Node untuk menyimpan informasi buku
    QString judul; // Judul buku
    QString penerbit; // Nama penerbit buku
    int tahunTerbit; // Tahun terbit buku
    QString sinopsis; // Sinopsis buku
    Node* next; // Pointer ke Node selanjutnya dalam linked list
};

class LinkedList { // Deklarasi kelas LinkedList untuk menyimpan dan mengelola data buku dalam linked list
public:
    LinkedList(); // Konstruktor LinkedList untuk menginisialisasi linked list
    ~LinkedList(); // Destruktor LinkedList untuk menghapus semua node dalam linked list
    void insert(const QString& judul, const QString& penerbit, int tahunTerbit, const QString& sinopsis); // Metode untuk menyisipkan buku baru ke dalam linked list
    bool update(const QString& judul, const QString& penerbit, int tahunTerbit, const QString& sinopsis); // Metode untuk memperbarui informasi buku dalam linked list
    bool remove(const QString& judul); // Metode untuk menghapus buku dari linked list berdasarkan judul
    Node* getHead() { return head; } // Metode untuk mendapatkan pointer ke kepala linked list
    Node* find(const QString& judul); // Metode untuk mencari buku dalam linked list berdasarkan judul

private:
    Node* head; // Pointer ke Node pertama dalam linked list
};

#endif // LINKEDLIST_H // Akhir dari header file linkedlist.h dan penutup dari header guard
