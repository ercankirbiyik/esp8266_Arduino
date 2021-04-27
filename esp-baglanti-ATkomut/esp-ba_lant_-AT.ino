#define ag_ismi "NetMASTER Uydunet-B317"
#define ag_sifresi "ec81bffa0c665d49"
void setup() {
  Serial.begin(115200); //Seriport'u açıyoruz. Güncellediğimiz 
  //ESP modülünün baudRate değeri 115200 olduğu için bizde Seriport'u 115200 şeklinde seçiyoruz
  Serial.println("AT"); //ESP modülümüz ile bağlantı kurulup kurulmadığını kontrol ediyoruz.
  pinMode(13, OUTPUT);
  delay(3000); //ESP ile iletişim için 3 saniye bekliyoruz.

  if (Serial.find("OK")) { //esp modülü ile bağlantıyı kurabilmişsek modül "AT" komutuna "OK" komutu ile geri dönüş yapıyor.
    Serial.println("AT+CWMODE=1"); //esp modülümüzün WiFi modunu STA şekline getiriyoruz. Bu mod ile modülümüz başka ağlara bağlanabilecek.
    delay(2000);
    String baglantiKomutu = String("AT+CWJAP=\"") + ag_ismi + "\",\"" + ag_sifresi + "\"";
    Serial.println(baglantiKomutu);
    delay(5000);
  }

  Serial.print("AT+CIPMUX=1\r\n");
  delay(200);
  Serial.print("AT+CIPSERVER=1,80\r\n");
  delay(1000);
}
void loop() {
  if (Serial.available() > 0) {
    if (Serial.find("+IPD,")) {
      String metin = "<head> Hello World </head>";
      metin += "<br><a href=\" ?pin=on\"><button type='button'>ON</button></a>";
      metin += "<br><a href=\" ?pin=off\"><button type='button'>OFF</button></a>";
      String cipsend = "AT+CIPSEND=";
      cipsend += "0";
      cipsend += ",";
      cipsend += metin.length();
      cipsend += "\r\n";
      Serial.print(cipsend);
      delay(500);
      Serial.println(metin);
      led_yakma();
      Serial.println("AT+CIPCLOSE=0");

    }
  }
}

void led_yakma() {
  String gelen = "";
  char serialdenokunan;
  while (Serial.available() > 0) {
    serialdenokunan = Serial.read();
    gelen += serialdenokunan;

  }
  Serial.println(gelen);
  if ((gelen.indexOf(":GET /?pin=on") > 1)) { //on butonuna basıldığında server adresinde /?pin=on var ise
    digitalWrite(13, HIGH); //ledi yakar
  }
  if ((gelen.indexOf(":GET /?pin=off") > 1)) { // off butonuna basıldığında server adresinde /?pin=off var ise
    digitalWrite(13, LOW); //ledi söndürür
  }
}
