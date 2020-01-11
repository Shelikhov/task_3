// Структура файла пакетов:
//      T_PacketFileHeader
//      T_Packet
//      T_Packet
//      ...
//      T_Packet


// Данные заголовка файла пакетов
struct T_PacketFileHeader {
  union {
     unsigned long TypeDw;
     unsigned char TypeStr[ 4 ];
  } Type; // Идентификатор формата файла
          // Mes1, Mes2, Uvk1, Uvk2 - старые форматы, цифра - тип протокола (1 - RS, 2 - Ethernet)
          // Unf1, Unf2, Cpu1, Cpu2 - старые форматы, цифра - тип протокола (1 - RS, 2 - Ethernet)
          // Mes3 - новый формат, тип протокола и формат данных пакетов хранится в полях StreamInfo для каждого потока
  unsigned long StreamQuan;
  unsigned long RecordsInFile;
  long          RecordTime;
  char          RecordName[ 64 ];
  long          LastChangeTime;
  char          Info[ 60 ];
};

// Структура пакета
struct T_Packet {
    unsigned long  Time;       // Время получения пакета в миллисекундах
    unsigned short DataSize;   // Размер данных пакета
    unsigned char  StreamNum;  // Номер потока, которому принадлежит пакет
    unsigned char  Info;       // Зарезервировано для будущего использования
    unsigned char  Data[ ];    // Данные пакета
};

