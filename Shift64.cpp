#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Shift64.h"
Shift64::Shift64(int _data_pin, int _clock_pin, int _al_pin, int _dl_pin) {
  data_pin = _data_pin;
  clock_pin = _clock_pin;
  al_pin = _al_pin;
  dl_pin = _dl_pin;
  pinMode(data_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  pinMode(al_pin, OUTPUT);
  pinMode(dl_pin, OUTPUT);
  digitalWrite(data_pin, LOW);
  digitalWrite(clock_pin, LOW);
  digitalWrite(al_pin, HIGH);
  digitalWrite(dl_pin, LOW);
}

void Shift64::SetAddress(byte address) {
  digitalWrite(al_pin, LOW);
  shiftOut(data_pin, clock_pin, MSBFIRST, ~address);
  digitalWrite(al_pin, HIGH);
}

void Shift64::SetData(byte data) {
  digitalWrite(dl_pin, HIGH);
  shiftOut(data_pin, clock_pin, MSBFIRST, data);
  digitalWrite(dl_pin, LOW);
}

void Shift64::BitmaskWrite(byte registers, byte out) {
  Shift64::SetAddress(registers);
  Shift64::SetData(out);
}

void Shift64::WriteByte(byte register_id, byte out) {
  Shift64::BitmaskWrite(1 << (register_id-1), out);
}
