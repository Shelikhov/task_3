// ��������� ����� �������:
//      T_PacketFileHeader
//      T_Packet
//      T_Packet
//      ...
//      T_Packet


// ������ ��������� ����� �������
struct T_PacketFileHeader {
  union {
     unsigned long TypeDw;
     unsigned char TypeStr[ 4 ];
  } Type; // ������������� ������� �����
          // Mes1, Mes2, Uvk1, Uvk2 - ������ �������, ����� - ��� ��������� (1 - RS, 2 - Ethernet)
          // Unf1, Unf2, Cpu1, Cpu2 - ������ �������, ����� - ��� ��������� (1 - RS, 2 - Ethernet)
          // Mes3 - ����� ������, ��� ��������� � ������ ������ ������� �������� � ����� StreamInfo ��� ������� ������
  unsigned long StreamQuan;
  unsigned long RecordsInFile;
  long          RecordTime;
  char          RecordName[ 64 ];
  long          LastChangeTime;
  char          Info[ 60 ];
};

// ��������� ������
struct T_Packet {
    unsigned long  Time;       // ����� ��������� ������ � �������������
    unsigned short DataSize;   // ������ ������ ������
    unsigned char  StreamNum;  // ����� ������, �������� ����������� �����
    unsigned char  Info;       // ��������������� ��� �������� �������������
    unsigned char  Data[ ];    // ������ ������
};

