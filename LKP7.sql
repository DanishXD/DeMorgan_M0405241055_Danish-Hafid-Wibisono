-- MUSISI
CREATE TABLE Musisi (
    SSN CHAR(12) PRIMARY KEY,
    Nama VARCHAR(100) NOT NULL,
    Alamat VARCHAR(150),
    NoTelp VARCHAR(20)
);

-- INSTRUMEN
CREATE TABLE Instrumen (
    Nama VARCHAR(50),
    KunciMusik VARCHAR(10),
    PRIMARY KEY (Nama, KunciMusik)
);

-- RELASI MUSISI - INSTRUMEN (M:N)
CREATE TABLE MusisiInstrumen (
    SSN CHAR(12),
    Nama VARCHAR(50),
    KunciMusik VARCHAR(10),
    PRIMARY KEY (SSN, Nama, KunciMusik),
    FOREIGN KEY (SSN) REFERENCES Musisi(SSN),
    FOREIGN KEY (Nama, KunciMusik) REFERENCES Instrumen(Nama, KunciMusik)
);

-- ALBUM
CREATE TABLE Album (
    AlbumID INT PRIMARY KEY,
    Label VARCHAR(100),
    TglCopyright DATE,
    Format VARCHAR(10), -- CD, MC, dll
    ProduserSSN CHAR(12),
    FOREIGN KEY (ProduserSSN) REFERENCES Musisi(SSN)
);

-- LAGU
CREATE TABLE Lagu (
    SongID INT PRIMARY KEY,
    Judul VARCHAR(100) NOT NULL,
    Pengarang VARCHAR(100),
    AlbumID INT,
    FOREIGN KEY (AlbumID) REFERENCES Album(AlbumID)
);

-- RELASI MUSISI - LAGU (M:N, musisi menampilkan lagu)
CREATE TABLE LaguMusisi (
    SongID INT,
    SSN CHAR(12),
    PRIMARY KEY (SongID, SSN),
    FOREIGN KEY (SongID) REFERENCES Lagu(SongID),
    FOREIGN KEY (SSN) REFERENCES Musisi(SSN)
);