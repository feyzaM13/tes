#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Struktur untuk menyimpan informasi ternak
struct Ternak {
  string spesies;
  string warna;
  string umur;
  bool isAvailable;
};

// Struktur untuk menyimpan informasi pemilik
struct Pemilik {
  string nama;
  string alamat;
};

// Struktur untuk menyimpan informasi transaksi
struct Transaksi {
  string nama;
  string alamat;
  string tanggal;
};

class Livestock {
private:
  vector<Ternak> ternaks;
  unordered_map<string, Pemilik> pemiliks;
  vector<Transaksi> transaksis;

public:
  // Menambahkan ternak ke livestock
  void addTernak(string spesies, string warna, string umur) {
    ternaks.push_back({spesies, warna, umur, true});
  }

  // Menambahkan pemilik ke sistem
  void addPemilik(string nama, string alamat) {
    pemiliks[nama] = {nama, alamat};
  }

  // Memeriksa ketersediaan ternak
  bool checkAvailability(string spesies) {
    for (auto &ternak : ternaks) {
      if (ternak.spesies == spesies && ternak.isAvailable) {
        return true;
      }
    }
    return false;
  }

  // Menjual ternak
  string sellTernak(string spesies, string nama, string tanggal) {
    if (checkAvailability(spesies)) {
      for (auto &ternak : ternaks) {
        if (ternak.spesies == spesies) {
          ternak.isAvailable = false;
          transaksis.push_back({spesies, nama, tanggal});
          return "Penjualan berhasil";
        }
      }
    }
    return "Ternak tidak tersedia";
  }

  // Membeli ternak
  string buyTernak(string spesies, string nama, string tanggal) {
    for (auto &ternak : ternaks) {
      if (ternak.spesies == spesies && !ternak.isAvailable) {
        ternak.isAvailable = true;
        transaksis.push_back({spesies, nama, tanggal});
        return "Pembelian berhasil";
      }
    }
    return "Pembelian gagal";
  }

  // Menampilkan semua ternak
  void displayTernaks() {
    for (auto &ternak : ternaks) {
      cout << "Spesies: " << ternak.spesies << ", Warna: " << ternak.warna
           << ", Umur: " << ternak.umur
           << ", Tersedia: " << (ternak.isAvailable ? "Ya" : "Tidak") << endl;
    }
  }
};

int main() {
  Livestock livestock;
  int choice;
  string spesies, warna, umur, nama, alamat, tanggal;

  while (true) {
    cout << "\nMenu: " << endl;
    cout << "1. Tambah Ternak" << endl;
    cout << "2. Tambah Pemilik" << endl;
    cout << "3. Jual Ternak" << endl;
    cout << "4. Beli Ternak" << endl;
    cout << "5. Tampilkan Semua Ternak" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih opsi: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Masukkan spesies: ";
      cin >> spesies;
      cout << "Masukkan warna: ";
      cin.ignore();
      getline(cin, warna);
      cout << "Masukkan umur: ";
      getline(cin, umur);
      livestock.addTernak(spesies, warna, umur);
      break;

    case 2:
      cout << "Masukkan nama: ";
      cin >> nama;
      cout << "Masukkan alamat: ";
      cin.ignore();
      getline(cin, alamat);
      livestock.addPemilik(nama, alamat);
      break;

    case 3:
      cout << "Masukkan Spesies: ";
      cin >> spesies;
      cout << "Masukkan Nama: ";
      cin >> nama;
      cout << "Masukkan Tanggal Penjualan (YYYY-MM-DD): ";
      cin >> tanggal;
      cout << livestock.sellTernak(spesies, nama, tanggal) << endl;
      break;

    case 4:
      cout << "Masukkan Spesies: ";
      cin >> spesies;
      cout << "Masukkan Nama: ";
      cin >> nama;
      cout << "Masukkan Tanggal Pembelian (YYYY-MM-DD): ";
      cin >> tanggal;
      cout << livestock.buyTernak(spesies, nama, tanggal) << endl;
      break;

    case 5:
      livestock.displayTernaks();
      break;

    case 6:
      return 0;

    default:
      cout << "Opsi tidak valid!" << endl;
    }
  }

  return 0;
}