String val = "";
boolean mark = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    val += char(Serial.read());
    delay(2);   // Can't be deleted for it needs time to read Serial1
    mark = HIGH;
  }

  if (val.length() == 1) {    //Send command without CR/ LF/ NL
    if (val == "1") {
      digitalWrite(13, HIGH); //turn on the LED on D13
      Serial.println("LED is ON!");

    }
    else if (val == "0") {
      digitalWrite(13, LOW);  //Trun off
      Serial.println("LED is OFF!");
    }
  }

  if (mark == HIGH) {
    Serial.print("Length: ");      Serial.println(val.length());
    Serial.print("Val: ");        Serial.println(val); delay(50);
    Serial.println("Done");       Serial.println();
    Serial.flush();

    val = "";
    mark = LOW;
  }
}
