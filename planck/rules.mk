SRC += features/mouse_turbo_click.c
SRC += muse.c

# Build Options
BOOTMAGIC_ENABLE = no             # Virtual DIP switches, no=lite
UNICODE_ENABLE = yes              # Unicode
MOUSEKEY_ENABLE = yes             # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes             # Audio control and System control(+450)
RGB_MATRIX_ENABLE = IS31FL3731    # RGB underlight
AUDIO_ENABLE = yes                # Audio output on port C6
MIDI_ENABLE = no                  # MIDI controls
CONSOLE_ENABLE = yes               # Console for debug(+400)
COMMAND_ENABLE = no               # Commands for debug and configuration
NKRO_ENABLE = no                  # Nkey Rollover
BLUETOOTH_ENABLE = no             # Enable Bluetooth with the Adafruit EZ-Key HID
DEFERRED_EXEC_ENABLE = yes        # Needed for turboclick functionality
