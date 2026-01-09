# libwavebird

An open source implementation of the WaveBird protocol for Silicon Labs Gecko SoCs, used in [WavePhoenix](https://github.com/loopj/wavephoenix).

Currently supports Silicon Labs Gecko Series 1 and Series 2 SoCs. Tested with the EFR32FG1, EFR32FG14, EFR32MG22, and EFR32BG22 SoCs.

In theory this library **should** work with any Gecko Series 1 or Series 2 SoC that has proprietary 2.4GHz support. A `.radioconf` file for that platform will need to be created in `config/rail`.

## Installation

This library is provided as an SLC SDK extension and component.

### Using Simplicity Studio

If you are using Simplicity Studio, following the instructions in [this guide](https://docs.silabs.com/simplicity-studio-5-users-guide/latest/ss-5-users-guide-getting-started/install-sdk-extensions) to add it as an extension.

You should then be able to add the `libwavebird` component to your project from the "Software Components" tab of the project properties.

### Using SLC-CLI

If you are using SLC-CLI, you can clone the repository directly into your SDK's `extension` folder.

You must then mark it as a trusted extension:

```bash
slc signature trust -extpath <path_to_sdk>/extension/libwavebird
```

You can then add the `libwavebird` component to your project's `.slcp` file:

```yaml
sdk_extension:
  - id: libwavebird
    version: 1.0.0

component:
  - id: libwavebird
    from: libwavebird
```    

### Using SLC-CLI without adding to the SDK

If you prefer to keep the repository outside of the SDK folder, you can pass the path to `slc generate` using the `--sdk-extensions` option:

```bash
slc generate myproject.slcp --sdk-extensions <path_to_libwavebird>
```

You can then add the `libwavebird` component to your project's `.slcp` file:

```yaml
component:
  - id: libwavebird
    from: libwavebird
```

## Usage

See the [WavePhoenix source code](https://github.com/loopj/wavephoenix) for an example of how to use this library.

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