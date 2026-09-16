# Select the RAIL configuration for the target device family
set(WAVEBIRD_EFR32_FAMILIES efr32xg1 efr32xg14 efr32xg22)
if(NOT WAVEBIRD_EFR32_FAMILY IN_LIST WAVEBIRD_EFR32_FAMILIES)
  string(REPLACE ";" ", " families "${WAVEBIRD_EFR32_FAMILIES}")
  message(FATAL_ERROR "WAVEBIRD_EFR32_FAMILY must be set to one of: ${families}")
endif()

# Add EFR32-specific source files
target_sources(wavebird INTERFACE radio_efr32.c ${WAVEBIRD_EFR32_FAMILY}/rail_config.c)

# Add the generated RAIL configuration header for the selected family
target_include_directories(wavebird INTERFACE ${WAVEBIRD_EFR32_FAMILY})
