# Packet Logger Example

Prints all WaveBird packets received from a controller on channel 1 to a serial console.

Uses the default VCOM serial port of the selected board.

## Building

```bash
# Set the board you want to build for
BOARD=brd2710a

# Generate the project files
slc generate app.slcp --with $BOARD --output-type cmake --sdk-extensions=../.. -d target/$BOARD

# Build the project
cd target/$BOARD/packet-logger_cmake
cmake --workflow --preset project
```