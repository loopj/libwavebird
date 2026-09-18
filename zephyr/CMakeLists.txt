if(CONFIG_WAVEBIRD)
  zephyr_library_named(wavebird)

  # The protocol itself, which touches no hardware
  zephyr_library_sources(
    ${ZEPHYR_CURRENT_MODULE_DIR}/src/bch3121.c
    ${ZEPHYR_CURRENT_MODULE_DIR}/src/packet.c
  )

  zephyr_include_directories(${ZEPHYR_CURRENT_MODULE_DIR}/include)

  # The radio, with the generated RAIL configuration for the part
  if(CONFIG_WAVEBIRD_RADIO)
    if(CONFIG_WAVEBIRD_RADIO_EFR32XG1)
      set(WAVEBIRD_RAIL_FAMILY efr32xg1)
    elseif(CONFIG_WAVEBIRD_RADIO_EFR32XG14)
      set(WAVEBIRD_RAIL_FAMILY efr32xg14)
    elseif(CONFIG_WAVEBIRD_RADIO_EFR32XG22)
      set(WAVEBIRD_RAIL_FAMILY efr32xg22)
    endif()

    set(WAVEBIRD_PLATFORM_DIR ${ZEPHYR_CURRENT_MODULE_DIR}/src/platform/efr32)

    zephyr_library_sources(
      ${WAVEBIRD_PLATFORM_DIR}/radio_efr32.c
      ${WAVEBIRD_PLATFORM_DIR}/${WAVEBIRD_RAIL_FAMILY}/rail_config.c
    )

    zephyr_library_include_directories(${WAVEBIRD_PLATFORM_DIR}/${WAVEBIRD_RAIL_FAMILY})
  endif()
endif()
