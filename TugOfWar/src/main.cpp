#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define ENA 9
#define IN1 7
#define IN2 6
#define ENB 10  
#define IN3 16
#define IN4 17

#define BUTTON1_PIN 15
#define BUTTON2_PIN 14

int cnt0 = 0;
int cnt1 = 0;
int cnt2 = 0;

unsigned long lastCheck = 0;
const unsigned long interval = 2000;
unsigned long gameStartTime = 0;
bool gameStarted = false;

void countdown() {
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("3...");
  delay(1000);
  lcd.setCursor(6, 0);
  lcd.print("2...");
  delay(1000);
  lcd.setCursor(6, 0);
  lcd.print("1...");
  delay(1000);
  lcd.setCursor(5, 0);
  lcd.print("Start!");
  delay(750);
  lcd.clear();
}

void waitForReset();

void startGame() {
  cnt0 = cnt1 = cnt2 = 0;
  gameStarted = false;

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Game Ready...");
  delay(1000);
  lcd.clear();

  countdown();

  gameStartTime = millis();
  lastCheck = millis();
  gameStarted = true;
}

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  lcd.begin(16, 2);

  startGame();
}

void loop() {
  if (gameStarted) {
    unsigned long elapsedSeconds = (millis() - gameStartTime) / 1000;
    lcd.setCursor(5, 0);
    lcd.print("T: ");
    lcd.print(elapsedSeconds);
    lcd.print("  ");

    lcd.setCursor(0, 1);
    lcd.print("P1:");
    lcd.print(cnt0);
    lcd.print("   ");

    lcd.setCursor(11, 1);
    lcd.print("P2:");
    lcd.print(-cnt0);
    lcd.print("   ");
  }

  if (digitalRead(BUTTON1_PIN) == LOW) {
    cnt1++;
    delay(150);
    while (digitalRead(BUTTON1_PIN) == LOW);
  }

  if (digitalRead(BUTTON2_PIN) == LOW) {
    cnt2++;
    delay(150);
    while (digitalRead(BUTTON2_PIN) == LOW);
  }

  if (millis() - lastCheck >= interval) {
    lastCheck = millis();

    Serial.print("P1: ");
    Serial.print(cnt1);
    Serial.print(" | P2: ");
    Serial.print(cnt2);

    if (cnt1 > cnt2) {
      cnt0++;
      Serial.println(" -> Player 1 wins this round!");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, 255);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 255);
      delay(1000);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    } else if (cnt2 > cnt1) {
      cnt0--;
      Serial.println(" -> Player 2 wins this round!");
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 255);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 255);
      delay(1000);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
    } else {
      Serial.println(" -> Tie.");
    }

    cnt1 = 0;
    cnt2 = 0;

    if (cnt0 >= 5 || cnt0 <= -5) {
      lcd.clear();
      if (cnt0 >= 5) {
        lcd.setCursor(0, 0);
        lcd.print("Player 1 Wins!");
        Serial.println("Player1 wins the game!");
      } else {
        lcd.setCursor(0, 0);
        lcd.print("Player 2 Wins!");
        Serial.println("Player2 wins the game!");
      }
      waitForReset();
    }
  }
}

void waitForReset() {
  lcd.setCursor(0, 1);
  lcd.print("Hold to reset");

  bool player1Won = (cnt0 >= 5);

  unsigned long holdStart = 0;

  while (true) {
    if (digitalRead(BUTTON1_PIN) == LOW || digitalRead(BUTTON2_PIN) == LOW) {
      if (holdStart == 0) holdStart = millis();

      if (millis() - holdStart > 2000) {
        if (player1Won) {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
        } else {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);          
        }
        analogWrite(ENB, 255);
        analogWrite(ENA, 255);
        delay(3000);
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);

        startGame();
        return;
      }
    } else {
      holdStart = 0;
    }
    delay(50);
  }
}
