#ifndef Shift64_h
#define Shift64_h

class Shift64 {
  public:
    Shift64(int _data_pin, int _clock_pin, int _al_pin, int _dl_pin);
    void BitmaskWrite(byte registers, byte out);
    void WriteByte(byte register_id, byte out);
    void SetAddress(byte address);
    void SetData(byte data);
  private:
    int data_pin, clock_pin, al_pin, dl_pin;
};
#endif
