#include <wiringPi.h>
#include <stdio.h>

#define OUTPUT_PIN 7 
#define DASH_DELAY 300
#define DOT_DELAY 100
#define CHAR_DELAY 300

char *conversion_map[26] ={".-","-...","-.-.","-..",".","..-.","--.","..","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};


void dash() {
    digitalWrite(OUTPUT_PIN, HIGH);
    delay(DASH_DELAY);
    digitalWrite(OUTPUT_PIN, LOW);

    delay(CHAR_DELAY);
}

void dot() {
    digitalWrite(OUTPUT_PIN, HIGH);
    delay(DOT_DELAY);
    digitalWrite(OUTPUT_PIN, LOW);
    delay(CHAR_DELAY);
}

int main(int argc, char ** argv) {
    char * string = argv[1];
    char * morse_string;
    char current_char;

    wiringPiSetup () ;
    pinMode (OUTPUT_PIN, OUTPUT) ;

    puts(string);
    while(*string) {
        current_char = (*string | 32);

        if (current_char - 'a' >= 0 && current_char - 'a' < 26) {
            morse_string = conversion_map[current_char - 'a'];
            while(*morse_string) {
                if (*morse_string == '.') {
                    dot();
                } else if (*morse_string == '-') {
                    dash();
                }

                morse_string++;
            }
        }
        delay(CHAR_DELAY);
        string++;
    }
    return 0;
}
