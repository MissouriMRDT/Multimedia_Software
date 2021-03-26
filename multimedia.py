import time
from rovecomm_module.rovecomm import RoveComm, get_manifest
from enum import Enum
import lighting
from blackbox import black_box

# Initialize rovecomm
rovecomm_node = RoveComm(11000, ("", 11007))

if __name__ == "__main__":
    # Default to showing no color
    lighting.clear_lights()
    
    # Get rovecomm manifest
    manifest = get_manifest()

    # Start up blackbox logging to be default rovecomm callback
    rovecomm_node.set_default_callback(black_box.log_packets)

    # Set up the callbacks
    rovecomm_node.set_callback(manifest["Multimedia"]["Commands"]["LEDRGB"], lighting.handle_lighting_commands)
    rovecomm_node.set_callback(manifest["Multimedia"]["Commands"]["LEDPatterns"], lighting.handle_lighting_commands)
    rovecomm_node.set_callback(manifest["Multimedia"]["Commands"]["StateDisplay"], lighting.handle_lighting_commands)

    while True:
        # Keep light panel running
        lighting.run_lighting()
