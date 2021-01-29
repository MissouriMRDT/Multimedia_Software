import sys
from enum import Enum
import neopixel
import board
import time

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

this = sys.modules[__name__]

# The PWM pin used to control the NeoPixels
this.pixel_pin = board.D18
 
# The number of NeoPixels
this.num_pixels = 256

# Set up our neopixel array
this.pixels = neopixel.NeoPixel(this.pixel_pin, this.num_pixels, brightness=0.2, auto_write=False)

# Our default lighting mode
this.lighting_mode = LightingMode.NONE

# Our default state display
this.state = State.NONE

# Our default RGB colors
this.rgb = (0,0,0)

def clear_lights():
    """
    Turns off all the LEDS
    """
    this.pixels.fill((0, 0, 255))
    this.pixels.show()

def handle_lighting_commands(packet):
    """
    Used to handle incoming lighting commands and set the appropriate mode
    """
    # Raise error if the packet has no data
    if packet == None:
        raise TypeError

    if packet.data_id == 7004:
        state = packet.data
        lighting_mode = LightingMode.STATE
    elif packet.data_id == 7003:
        pass
    elif packet.data_id == 7002:
        this.rgb = packet.data
        lighting_mode = LightingMode.RGB

def display_rgb(rgb):
    """
    Fills the pixel matrix with the desired color
    """
    this.pixels.fill((rgb[0], rgb[1], rgb[2]))
    this.pixels.show()

def display_state(state):
    """
    Writes a color to the LED panel to indicate a rover state
    """
    if state == State.TELEOP:
        # Write BLUE to indicate teleop
        this.pixels.fill((0, 0, 255))
        this.pixels.show()
        pass
    elif state == State.AUTONOMY:
        # Write RED to indicate autonomy
        this.pixels.fill((255, 0, 0))
        this.pixels.show()
        pass
    elif state == State.REACHED_GOAL:
        # Flash Green to indicate reached goal
        this.pixels.fill((0, 255, 0))
        this.pixels.show()
        time.sleep(0.25)
        this.pixels.fill((0, 0, 0))
        this.pixels.show()
        pass
    else:
        # Default to showing no color
        this.pixels.fill((0, 0, 0))
        this.pixels.show()

def run_lighting():
    """
    Updates the lighting panel based on the current lighting mode and values
    """

    if this.lighting_mode == LightingMode.STATE:
        display_state(this.state)
    elif this.lighting_mode == LightingMode.PATTERN:
        display_rgb(this.rgb)
    elif this.lighting_mode == LightingMode.RGB:
        pass
    else:
        clear_lights()
    
