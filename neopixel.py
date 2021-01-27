import time
import board
import neopixel
from rovecomm import RoveCommEthernetUdp, RoveCommPacket
from enum import Enum

class State(Enum):
    TELEOP = 0
    AUTONOMY = 1
    REACHED_GOAL = 2
    NONE = 3

class LightingMode(Enum):
    NONE = 0
    STATE = 1
    PATTERN = 2
    RGB = 3

# The PWM pin used to control the NeoPixels
pixel_pin = board.D18
 
# The number of NeoPixels
num_pixels = 30
 
# Order of pixel color
ORDER = neopixel.RGB
 
# Set up our neopixel array
pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=0.2, auto_write=False, pixel_order=ORDER)

# Initialize rovecomm
rovecomm_node = RoveCommEthernetUdp(11000, ("", 11112))

def set_state(state):
    """
    Writes a color to the LED panel to indicate a rover state
    """
    if state == State.TELEOP:
        # Write BLUE to indicate teleop
        pixels.fill((0, 0, 255))
        pixels.show()
        pass
    elif state == State.AUTONOMY:
        # Write RED to indicate autonomy
        pixels.fill((255, 0, 0))
        pixels.show()
        pass
    elif state == State.REACHED_GOAL:
        # Flash Green to indicate reached goal
        pixels.fill((0, 255, 0))
        pixels.show()
        time.sleep(0.25)
        pixels.fill((0, 0, 0))
        pixels.show()
        pass
    else:
        # Default to showing no color
        pixels.fill((0, 0, 0))
        pixels.show()

if __name__ == "__main__":
    # Default to showing no color
    pixels.fill((0, 0, 0))
    pixels.show()

    # Our default lighting mode
    lighting_mode = LightingMode.NONE

    # Our default state
    state = State.NONE
        
    while True:
        packet = rovecomm_node.read()

        if packet.data_id == 7004:
            state = packet.data
            lighting_mode = LightingMode.STATE

        if lighting_mode == LightingMode.STATE:
            set_state(state)
        elif lighting_mode == LightingMode.PATTERN:
            pass
        elif lighting_mode == LightingMode.RGB:
            pass
    
