import drivers
from time import sleep


display = drivers.Lcd()
x = 0
try:
    print("Writing to display")
    display.lcd_display_string("No time to waste", 1)  # Write line of text to first line of display
    while True:
        x = x+1
        display.lcd_display_string("contagem:",str(x))
        print("contagem:",str(x))
        sleep(2)
except KeyboardInterrupt:
    # If there is a KeyboardInterrupt (when you press ctrl+c), exit the program and cleanup
    print("Cleaning up!")
    display.lcd_clear()