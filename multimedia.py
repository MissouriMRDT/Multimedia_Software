import time
from rovecomm_module.rovecomm import RoveComm
from enum import Enum
import lighting

# Initialize rovecomm
rovecomm_node = RoveComm(11000, ("", 11007))

if __name__ == "__main__":
    # Default to showing no color
    lighting.clear_lights()

    # Set up the callbacks
    rovecomm_node.set_callback(7001, lighting.handle_lighting_commands)
    rovecomm_node.set_callback(7002, lighting.handle_lighting_commands)
    rovecomm_node.set_callback(7003, lighting.handle_lighting_commands)

    while True:
        # Keep light panel running
        lighting.run_lighting()
