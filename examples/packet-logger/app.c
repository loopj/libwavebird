#include <stdio.h>

#include <wavebird/wavebird.h>

uint8_t message[WAVEBIRD_MESSAGE_BYTES];

// Handle received WaveBird packets here
void wavebird_packet_handler(const uint8_t *packet)
{
  // Decode the WaveBird packet
  int rc = wavebird_packet_decode(message, packet);
  if (rc < 0) {
    // Decoding failed, ignore for now
    return;
  }

  // Check what type of message we received
  if (wavebird_message_get_type(message) == WB_MESSAGE_TYPE_INPUT_STATE) {
    // Message is an input state message, print the values
    printf("B:%03X | SX:%3d | SY:%3d | CX:%3d | CY:%3d | TL:%3d | TR:%3d\n", wavebird_input_state_get_buttons(message),
           wavebird_input_state_get_stick_x(message), wavebird_input_state_get_stick_y(message),
           wavebird_input_state_get_substick_x(message), wavebird_input_state_get_substick_y(message),
           wavebird_input_state_get_trigger_left(message), wavebird_input_state_get_trigger_right(message));
  } else {
    // Message is an origin message, ignore for now
  }
}

// Handle radio errors here
void wavebird_error_handler(int error)
{
  // Ignore errors for now
}

/***************************************************************************/ /**
                                                                               * Initialize application.
                                                                               ******************************************************************************/
void app_init(void)
{
  // Initialize the WaveBird radio
  wavebird_radio_init(wavebird_packet_handler, wavebird_error_handler);

  // Set the WaveBird radio to listen on channel 0
  // Channel numbers are 0-15, corresponding to channels 1-16 on the WaveBird
  wavebird_radio_set_channel(0);

  printf("WaveBird packet scanner ready\n");
}

/***************************************************************************/ /**
                                                                               * App ticking function.
                                                                               ******************************************************************************/
void app_process_action(void)
{
  wavebird_radio_process();
}
