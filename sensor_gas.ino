#include <LiquidCrystal_I2C.h> // Library Lcd
#include <Wire.h> //Library i2c
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // 0x27 adalah address, dan angka 16, 2 adalah kolom dan baris dari LCD

const int sensor_gas = 12; //sensor gas diletakkan di pin 12 
const int buzzer = 11; //buzzer diletakkan di pin 11
const int led_hijau = 10; //led hijau diletakkan di pin 10
const int led_merah = 9; //led merah diletakkan di pin 9
void setup()
{
lcd.init(); //inisialisasi lcd
lcd.backlight(); //menyalakan backlight
lcd.clear(); //untuk menghapus layar LCD
pinMode(sensor_gas,INPUT); //mengkonfigurasi sensor gas sebagai INPUT
pinMode(buzzer,OUTPUT); //mengkonfigurasi buzzer sebagai OUTPUT
pinMode(led_hijau,OUTPUT); //mengkonfigurasi led hijau sebagai OUTPUT
pinMode(led_merah,OUTPUT); //mengkonfigurasi led merah sebagai OUTPUT
}
void loop()
{

int nilai = digitalRead(sensor_gas); //memasukkan nilai 
if (nilai == LOW) // jika nilai sama dengan 0
{
digitalWrite(buzzer,HIGH); //buzzer aktif
lcd.setCursor(0, 0);
lcd.print("Kondisi Ruangan:");
lcd.setCursor(0, 1);
lcd.print("GAS BOCOR ");
digitalWrite(led_hijau,LOW);//led hijau mati
digitalWrite(led_merah,HIGH);//led merah aktif
}
if (nilai == HIGH) // jika nilai sama dengan 1
{
digitalWrite(buzzer,LOW);//buzzer aktif
lcd.setCursor(0, 0);
lcd.print("Kondisi Ruangan:");
lcd.setCursor(0, 1);
lcd.print("GAS AMAN.");
digitalWrite(led_hijau,HIGH);//led hijau aktif
digitalWrite(led_merah,LOW);//led merah mati
}
}
