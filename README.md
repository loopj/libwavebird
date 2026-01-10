# libwavebird

An open source implementation of Nintendo's WaveBird protocol for Silicon Labs Gecko SoCs.

`libwavebird` provides the radio configurations and encoding/decoding logic required to communicate with Nintendo WaveBird wireless controllers and receivers. It serves as the foundation of the [WavePhoenix](https://github.com/loopj/wavephoenix) project.

## Features

- Event-based radio layer demodulates and frames incoming FSK+DSSS WaveBird packets
- Packet decoding/encoding functions handle BCH error correction and CRC validation, with up to 8-bit burst error correction
- Manual channel selection and virtual pairing support
- Helpers for working with decoded WaveBird messages
  - Parse 10-bit controller IDs
  - Parse input state messages (button, stick, and trigger states)
  - Parse origin messages (stick and trigger calibration data)

## Hardware Support

This library was designed for Silicon Labs Gecko Series 1 and Series 2 SoCs which support proprietary 2.4 GHz wireless protocols. 

Radio modules based on the EFR32BG22 SoC are recommended, but it has been tested with the following SoC families:
- EFR32xG1
- EFR32xG14
- EFR32xG22

To add support for a new SoC, a `.radioconf` file for that platform will need to be created in `config/rail`.

## Installation

This library is packaged as a Silicon Labs SDK extension.

### Via Simplicity Studio

1. Follow the [Silicon Labs Guide]((https://docs.silabs.com/simplicity-studio-5-users-guide/latest/ss-5-users-guide-getting-started/install-sdk-extensions)) to add this repository as an extension.

2. Open your project's *Software Components* tab and install the `libwavebird` component.

### Using SLC-CLI

Clone into your SDK's `extension` folder and trust the extension:

```bash
slc signature trust -extpath <path_to_sdk>/extension/libwavebird
```

Add to your project's `.slcp` file:

```yaml
sdk_extension:
  - id: libwavebird
    version: 1.0.0

component:
  - id: libwavebird
    from: libwavebird
```    

## Usage

See the [examples](examples/) directory for basic usage examples.

You can also check out the [WavePhoenix source code](https://github.com/loopj/wavephoenix) for a more complete example of using this library to build a WaveBird receiver.

## Regenerating RAIL configuration files

If you make changes to the `.radioconf` files in the `config/rail` directory, you will need to regenerate the `rail_config.c` and `rail_config.h` files.

To regenerate the files, run `scripts/generate_rail_config.py`.

## Running tests

Build the test suite

```bash
cmake -Bbuild && cmake --build build
```

Run the tests

```bash
ctest --test-dir build --output-on-failure
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.