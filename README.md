# esp8266_Arduino
lm35 Sıcaklık sensörü ile oda sıcaklığının ölçülüp esp8266 ile internet ortamına belirlenen süre aralığında aktarılması.
ThingSpeak platformuna kayıt olup hesap açıldıktan sonra açılan bu hesap esp8266 modülü ve Arduino ile haberleşmemizi sağlayacaktır. (TimeZone kısmının doğru olduğuna dikkat edilmesi ve doğru bölgenin seçildiğinden emin olunması lazım ki verilerin anlık alınmasını sağlayabilelim.)
ThingSpeak platformuna giriş yapıldıktan sonra Channels->MyChannels'tan yeni bir kanal oluşturulur ve sırası ile isim, açıklama ve oluşturulacak sıcaklık zaman grafiğinin sıcaklık kısmını field1'e yazmak gerekmektedir.(Farklı birşey de yazılabilir veya daha sonra değiştirilebilir.)
Kanalımızdaki seçeneklerden grafiğimizi görebilir, yapmış olduğumuz isimlendirmeleri değiştirebilir ve Apı Keyslerimizi görebiliriz.
[ESP8266-bağlantı-şeması]ndaki gibi gerekli bağlantılar dikkatlice yapıldıktan sonra kodumuzu Arduino'ya yüklüyoruz (yüklerken Rx,Tx pinlerini çıkarıp yükleme tamamlandıktan sonra tekrar takmak gerekmektedir)
