
/*
 第3回Arduino勉強会
 複数センサ（24ページ目）
*/

// 定数の宣言
const int analogInPin1 = A0;  // アナログ入力ピン1
const int analogInPin2 = A2;  // アナログ入力ピン2
const int analogOutPin = 9;   // アナログ出力ピン(LEDピン)
// 変数の宣言
int sensorValue1 = 0;         // センサ読み取り値1
int sensorValue2 = 0;         // センサ読み取り値2
int outputValue = 0;          // LED出力値

// 初期化
void setup() {
  Serial.begin(9600);   // シリアル開始
}

// メイン処理の記述
void loop() {
  // もし、データを受信していたら
  if (Serial.available() > 0) {
    // バッファをクリアするため1バイト読み込み(読み込んだ値は使用しない)
    Serial.read();
    //センサ値読み取り
    sensorValue1 = analogRead(analogInPin1);
    sensorValue2 = analogRead(analogInPin2);
    // シリアルに文字列形式で出力
    Serial.print(sensorValue1);
    Serial.print(",");
    Serial.println(sensorValue2);   
    //LEDを光らせる(動作確認用)
    //センサ入力値をマッピングして調整
    outputValue = map(sensorValue1, 0, 1023, 0, 255);
    analogWrite(analogOutPin, outputValue);
  } 
  delay(2);//待機
}
