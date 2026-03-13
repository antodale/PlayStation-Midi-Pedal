
const int pedal1Pin = A0;  


const byte cc1 = 11;       // Expression (CC#11)

const byte channel = 1;    // MIDI Channel 1

int lastVal1 = -1;


void setup() {
  Serial.begin(31250); // MIDI baud rate
}

void loop() {
  int raw1 = analogRead(pedal1Pin);


  int midiVal1 = map(raw1, 0, 1023, 0, 127);


  if (abs(midiVal1 - lastVal1) > 1) {
    sendCC(cc1, midiVal1);
    lastVal1 = midiVal1;
  }

  delay(10);
}

void sendCC(byte cc, byte value) {
  Serial.write(0xB0 | ((channel - 1) & 0x0F)); // Control Change on channel
  Serial.write(cc);
  Serial.write(value);
}
