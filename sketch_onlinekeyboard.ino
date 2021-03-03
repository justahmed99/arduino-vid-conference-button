#include "Keyboard.h"

/*--------------
code by : justahmed99
website : https://justahmed99.com
-------------*/
// these inputs are being used for setting up what kind of video conference app you use
// these form 4 bit binary digits from 0000 to 1111 because we use 4 dip switch in this program
const int input0 = 8;
const int input1 = 7;
const int input2 = 6;
const int input3 = 5;

// the red button (redButton) is for handle video / camera
// the green button (greenButton) is for handle audio / microphone
const int redButton = 16;
const int greenButton = 10;

int value0 = 0;
int value1 = 0;
int value2 = 0;
int value3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(input0, INPUT);
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);

  pinMode(redButton, INPUT);
  pinMode(greenButton, INPUT);
}

void loop() {
  value0 = digitalRead(input0);
  value1 = digitalRead(input1);
  value2 = digitalRead(input2);
  value3 = digitalRead(input3);
  
  if (value3 == LOW && value2 == LOW && value1 == LOW && value0 == LOW) {
    // 0000
    Serial.println("0 - Zoom");
    if (digitalRead(redButton) == HIGH) {
      // start or stop camera
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('v');
      Keyboard.releaseAll();
      delay(100);
    }

    if (digitalRead(greenButton) == HIGH) {
      // mute or unmute microphone
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('a');
      Keyboard.releaseAll();
      delay(100);
    }
  } else if (value3 == LOW && value2 == LOW && value1 == LOW && value0 == HIGH) {
    // 0001
    Serial.println("1 - Microsoft Teams");
    if (digitalRead(redButton) == HIGH) {
      // start or stop camera
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('m');
      Keyboard.releaseAll();
      delay(100);
    }

    if (digitalRead(greenButton) == HIGH) {
      // mute or unmute microphone
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('o');
      Keyboard.releaseAll();
      delay(100);
    }
  } else if (value3 == LOW && value2 == LOW && value1 == HIGH && value0 == LOW) {
    // 0010
    Serial.println("2 - Google Meet");
    if (digitalRead(redButton) == HIGH) {
      // start or stop camera
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('e');
      Keyboard.releaseAll();
      delay(100);
    }

    if (digitalRead(greenButton) == HIGH) {
      // mute or unmute microsoft
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('d');
      Keyboard.releaseAll();
      delay(100);
    }
  } else if (value3 == LOW && value2 == LOW && value1 == HIGH && value0 == HIGH) {
    // 0011
    Serial.println("3");
  } else if (value3 == LOW && value2 == HIGH && value1 == LOW && value0 == LOW) {
    // 0100
    Serial.println("4");
  } else if (value3 == LOW && value2 == HIGH && value1 == LOW && value0 == HIGH) {
    // 0101
    Serial.println("5");
  } else if (value3 == LOW && value2 == HIGH && value1 == HIGH && value0 == LOW) {
    // 0110
    Serial.println("6");
  } else if (value3 == LOW && value2 == HIGH && value1 == HIGH && value0 == HIGH) {
    // 0111
    Serial.println("7");
  } else if (value3 == HIGH && value2 == LOW && value1 == LOW && value0 == LOW) {
    // 1000
    Serial.println("8");
  } else if (value3 == HIGH && value2 == LOW && value1 == LOW && value0 == HIGH) {
    // 1001
    Serial.println("9");
  } else if (value3 == HIGH && value2 == LOW && value1 == HIGH && value0 == LOW) {
    // 1010
    Serial.println("10");
  } else if (value3 == HIGH && value2 == LOW && value1 == HIGH && value0 == HIGH) {
    // 1011
    Serial.println("11");
  } else if (value3 == HIGH && value2 == HIGH && value1 == LOW && value0 == LOW) {
    // 1100
    Serial.println("12");
  } else if (value3 == HIGH && value2 == HIGH && value1 == LOW && value0 == HIGH) {
    // 1101
    Serial.println("13");
  } else if (value3 == HIGH && value2 == HIGH && value1 == HIGH && value0 == LOW) {
    // 1110
    Serial.println("14");
  } else if (value3 == HIGH && value2 == HIGH && value1 == HIGH && value0 == HIGH) {
    // 1111
    Serial.println("15");
  } 
}
