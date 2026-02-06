from graphviz import Digraph

# Buat diagram ERD dengan Graphviz
dot = Digraph(comment="ERD Sistem Manajemen Kesehatan", format="png")
dot.attr(rankdir="LR", size="8")

# Node entitas
dot.node("Pasien", '''Pasien|{PasienID (PK)|Nama|TanggalLahir|NomorBPJS}''', shape="record")
dot.node("Dokter", '''Dokter|{DokterID (PK)|Nama|Spesialis|Departemen}''', shape="record")
dot.node("Appointment", '''Appointment|{AppointmentID (PK)|Tanggal|Waktu|Status|PasienID (FK)|DokterID (FK)}''', shape="record")
dot.node("Tindakan", '''Tindakan|{TindakanID (PK)|Tipe|Biaya|AppointmentID (FK)}''', shape="record")

# Relasi dengan Crow's Foot (gunakan label)
dot.edge("Pasien", "Appointment", label="1..*")
dot.edge("Dokter", "Appointment", label="1..*")
dot.edge("Appointment", "Tindakan", label="1..*")

# Simpan ke file
file_path = "/mnt/data/erd_kesehatan"
dot.render(file_path)

file_path + ".png"